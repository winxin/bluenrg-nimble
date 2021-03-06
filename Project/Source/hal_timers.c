/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>

#include "hal/hal_timer.h"

#include "BlueNRG_x_device.h"
#include "BlueNRG1_conf.h"
#include "SDK_EVAL_Config.h"

/* 500 ms period setting */
#define RTC_PERIOD_500ms                               ((32768-1)/2)

#define __HAL_DISABLE_INTERRUPTS(x)                     \
    do {                                                \
        x = __get_PRIMASK();                            \
        __disable_irq();                                \
    } while(0);

#define __HAL_ENABLE_INTERRUPTS(x)                      \
    do {                                                \
        if (!x) {                                       \
            __enable_irq();                             \
        }                                               \
    } while(0);

TAILQ_HEAD(hal_timer_qhead, hal_timer);

static struct hal_timer_qhead hal_timer_q = TAILQ_HEAD_INITIALIZER(hal_timer_q);

static void
bluenrg_timer_match(uint32_t expiry)
{
    RTC_DateTimeType RTC_DateTime = {0};

    RTC_SetMatchTimeDate(&RTC_DateTime);

    /* Enable RTC clock watch interrupt */
    RTC_IT_Config(RTC_IT_CLOCKWATCH, ENABLE);
    RTC_IT_Clear(RTC_IT_CLOCKWATCH);
}

static uint32_t
bluenrg_timer_now(void)
{
    RTC_DateTimeType RTC_DateTime = {0};

    RTC_GetTimeDate(&RTC_DateTime);

    return 0;
}

static bool
bluenrg_timer_check(uint32_t expiry)
{
    int32_t delta;

    /* Make sure the clock match happen */
    delta = (int32_t)(bluenrg_timer_now() + 1 - expiry);

    return (delta >= 0);
}

/**
 * nrf timer set ocmp
 *
 * Set the OCMP used by the timer to the desired expiration tick
 *
 * NOTE: Must be called with interrupts disabled.
 *
 * @param timer Pointer to timer.
 */
static void
bluenrg_timer_set(uint32_t expiry)
{
    if (bluenrg_timer_check(expiry)) {
        NVIC_SetPendingIRQ(RTC_IRQn);
    } else {
        bluenrg_timer_match(expiry);
    }
}

/* Disable output compare used for timer */
static void
bluenrg_timer_disable(void)
{
    /* Disable RTC clock watch interrupt */
    RTC_IT_Config(RTC_IT_CLOCKWATCH, DISABLE);
    RTC_IT_Clear(RTC_IT_CLOCKWATCH);
}

void
bluenrg_timer_handler(void)
{
    uint32_t ctx;
    struct hal_timer *timer;

    /* disable interrupts */
    __HAL_DISABLE_INTERRUPTS(ctx);

    while ((timer = TAILQ_FIRST(&hal_timer_q)) != NULL) {
        /* In case the current stamp is less 1 */
        if (bluenrg_timer_check(timer->expiry)) {
            TAILQ_REMOVE(&hal_timer_q, timer, link);
            timer->link.tqe_prev = NULL;
            timer->cb_func(timer->cb_arg);
        } else {
            break;
        }
    }

    /* Any timers left on queue? If so, we need to set OCMP */
    timer = TAILQ_FIRST(&hal_timer_q);
    if (timer) {
        bluenrg_timer_set(timer->expiry);
    } else {
        bluenrg_timer_disable();
    }

    __HAL_ENABLE_INTERRUPTS(ctx);
}

/**
 * hal timer init
 *
 * Initialize platform specific timer items
 *
 * @param timer_num     Timer number to initialize
 * @param cfg           Pointer to platform specific configuration
 *
 * @return int          0: success; error code otherwise
 */
int
hal_timer_init(int timer_num, void *cfg)
{
    RTC_InitType RTC_Init_struct;
    NVIC_InitType NVIC_InitStructure;

    /* Enable RTC clocks */
    SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_RTC, ENABLE);

    RTC_Init_struct.RTC_operatingMode = RTC_TIMER_PERIODIC;    /**< Periodic RTC mode */
    RTC_Init_struct.RTC_PATTERN_SIZE = 1 - 1;                  /**< Pattern size set to 1 */
    RTC_Init_struct.RTC_TLR1 = RTC_PERIOD_500ms;               /**< Enable 0.5s timer period */
    RTC_Init_struct.RTC_PATTERN1 = 0x00;                       /**< RTC_TLR1 selected for time generation */
    RTC_Init(&RTC_Init_struct);

    /* Enable RTC Timer interrupt*/
    RTC_IT_Config(RTC_IT_TIMER, ENABLE);
    RTC_IT_Clear(RTC_IT_TIMER);

    /** Delay between two write in RTC0->TCR register has to be
      * at least 3 x 32k cycle + 2 CPU cycle. For that reason it
      * is neccessary to add the delay. 
      */
    for (volatile uint16_t i=0; i<600; i++) {
        __asm("NOP");
    }

    /* Set the RTC_IRQn interrupt priority and enable it */
    NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = MED_PRIORITY;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* Enable RTC */
    RTC_Cmd(ENABLE);

    return 0;
}

/**
 * hal timer config
 *
 * Configure a timer to run at the desired frequency. This starts the timer.
 *
 * @param timer_num
 * @param freq_hz
 *
 * @return int
 */
int
hal_timer_config(int timer_num, uint32_t freq_hz)
{
    RTC_DateTimeType RTC_DateTime;

    /* Set the present time and date */
    RTC_DateTime.Second = 0;
    RTC_DateTime.Minute = 0;
    RTC_DateTime.Hour = 0;
    RTC_DateTime.WeekDay = 4;
    RTC_DateTime.MonthDay = 1;
    RTC_DateTime.Month = 1;
    RTC_DateTime.Year = 1970;
    RTC_SetTimeDate(&RTC_DateTime);

    /* CLK1HZ clock is similar to CLK32K */
    RTC->CTCR_b.CKDIV = 0;
    /* It is neccessary to add the delay */
    for (volatile uint16_t i=0; i<600; i++) {
        __asm("NOP");
    }

    /* Enable RTC clockwatch */
    RTC_ClockwatchCmd(ENABLE);

    return 0;
}

/**
 * hal timer deinit
 *
 * De-initialize a HW timer.
 *
 * @param timer_num
 *
 * @return int
 */
int
hal_timer_deinit(int timer_num)
{
    SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_RTC, DISABLE);

    return 0;
}

/**
 * hal timer get resolution
 *
 * Get the resolution of the timer. This is the timer period, in nanoseconds
 *
 * @param timer_num
 *
 * @return uint32_t The
 */
uint32_t
hal_timer_get_resolution(int timer_num)
{
    return (1000000000UL / 32768UL);
}

/**
 * hal timer read
 *
 * Returns the timer counter. NOTE: if the timer is a 16-bit timer, only
 * the lower 16 bits are valid. If the timer is a 64-bit timer, only the
 * low 32-bits are returned.
 *
 * @return uint32_t The timer counter register.
 */
uint32_t
hal_timer_read(int timer_num)
{
    uint32_t tcntr;

    tcntr = bluenrg_timer_now();

    return tcntr;
}

/**
 * hal timer delay
 *
 * Blocking delay for n ticks
 *
 * @param timer_num
 * @param ticks
 *
 * @return int 0 on success; error code otherwise.
 */
int
hal_timer_delay(int timer_num, uint32_t ticks)
{
    uint32_t until;

    until = hal_timer_read(timer_num) + ticks;
    while ((int32_t)(hal_timer_read(timer_num) - until) <= 0) {
        /* Loop here till finished */
    }

    return 0;
}

/**
 *
 * Initialize the HAL timer structure with the callback and the callback
 * argument. Also initializes the HW specific timer pointer.
 *
 * @param cb_func
 *
 * @return int
 */
int
hal_timer_set_cb(int timer_num, struct hal_timer *timer, hal_timer_cb cb_func,
                 void *arg)
{
    timer->cb_func = cb_func;
    timer->cb_arg = arg;
    timer->link.tqe_prev = NULL;
    timer->bsp_timer = NULL;

    return 0;
}

int
hal_timer_start(struct hal_timer *timer, uint32_t ticks)
{
    return hal_timer_start_at(timer, bluenrg_timer_now() + ticks);
}

int
hal_timer_start_at(struct hal_timer *timer, uint32_t tick)
{
    uint32_t ctx;
    struct hal_timer *entry;

    if ((timer == NULL) || (timer->link.tqe_prev != NULL) ||
        (timer->cb_func == NULL)) {

        return EINVAL;
    }

    timer->expiry = tick;

    __HAL_DISABLE_INTERRUPTS(ctx);

    if (TAILQ_EMPTY(&hal_timer_q)) {
        TAILQ_INSERT_HEAD(&hal_timer_q, timer, link);
    } else {
        TAILQ_FOREACH(entry, &hal_timer_q, link) {
            if ((int32_t)(timer->expiry - entry->expiry) < 0) {
                TAILQ_INSERT_BEFORE(entry, timer, link);
                break;
            }
        }
        if (!entry) {
            TAILQ_INSERT_TAIL(&hal_timer_q, timer, link);
        }
    }

    /* If this is the head, we need to set new OCMP */
    if (timer == TAILQ_FIRST(&hal_timer_q)) {
        bluenrg_timer_set(timer->expiry);
    }

    __HAL_ENABLE_INTERRUPTS(ctx);

    return 0;
}

/**
 * hal timer stop
 *
 * Stop a timer.
 *
 * @param timer
 *
 * @return int
 */
int
hal_timer_stop(struct hal_timer *timer)
{
    uint32_t ctx;
    bool reset_ocmp;
    struct hal_timer *entry;

    if (timer == NULL) {
        return EINVAL;
    }

    __HAL_DISABLE_INTERRUPTS(ctx);
    
    if (timer->link.tqe_prev != NULL) {
        reset_ocmp = false;
        if (timer == TAILQ_FIRST(&hal_timer_q)) {
            /* If first on queue, we will need to reset OCMP */
            entry = TAILQ_NEXT(timer, link);
            reset_ocmp = true;
        }
        TAILQ_REMOVE(&hal_timer_q, timer, link);
        timer->link.tqe_prev = NULL;
        if (reset_ocmp) {
            if (entry) {
                bluenrg_timer_set(entry->expiry);
            } else {
                bluenrg_timer_disable();
            }
        }
    }

    __HAL_ENABLE_INTERRUPTS(ctx);

    return 0;
}

