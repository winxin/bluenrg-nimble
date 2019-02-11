/**
 * This file was generated by Apache Newt version: 1.4.1
 */

#ifndef H_MYNEWT_SYSCFG_
#define H_MYNEWT_SYSCFG_

/**
 * This macro exists to ensure code includes this header when needed.  If code
 * checks the existence of a setting directly via ifdef without including this
 * header, the setting macro will silently evaluate to 0.  In contrast, an
 * attempt to use these macros without including this header will result in a
 * compiler error.
 */
#define MYNEWT_VAL(x)                           MYNEWT_VAL_ ## x



/*** @apache-mynewt-core/hw/bsp/nrf51dk-16kbram */
#ifndef MYNEWT_VAL_BSP_NRF51
#define MYNEWT_VAL_BSP_NRF51 (1)
#endif

#ifndef MYNEWT_VAL_I2C_0_FREQUENCY
#define MYNEWT_VAL_I2C_0_FREQUENCY (100)
#endif

#ifndef MYNEWT_VAL_I2C_0_SCL_PIN
#define MYNEWT_VAL_I2C_0_SCL_PIN (7)
#endif

#ifndef MYNEWT_VAL_I2C_0_SDA_PIN
#define MYNEWT_VAL_I2C_0_SDA_PIN (30)
#endif

#ifndef MYNEWT_VAL_SPI_0_MASTER_PIN_MISO
#define MYNEWT_VAL_SPI_0_MASTER_PIN_MISO (28)
#endif

#ifndef MYNEWT_VAL_SPI_0_MASTER_PIN_MOSI
#define MYNEWT_VAL_SPI_0_MASTER_PIN_MOSI (25)
#endif

#ifndef MYNEWT_VAL_SPI_0_MASTER_PIN_SCK
#define MYNEWT_VAL_SPI_0_MASTER_PIN_SCK (29)
#endif

#ifndef MYNEWT_VAL_SPI_1_SLAVE_PIN_MISO
#define MYNEWT_VAL_SPI_1_SLAVE_PIN_MISO (28)
#endif

#ifndef MYNEWT_VAL_SPI_1_SLAVE_PIN_MOSI
#define MYNEWT_VAL_SPI_1_SLAVE_PIN_MOSI (25)
#endif

#ifndef MYNEWT_VAL_SPI_1_SLAVE_PIN_SCK
#define MYNEWT_VAL_SPI_1_SLAVE_PIN_SCK (29)
#endif

#ifndef MYNEWT_VAL_SPI_1_SLAVE_PIN_SS
#define MYNEWT_VAL_SPI_1_SLAVE_PIN_SS (24)
#endif

#ifndef MYNEWT_VAL_TIMER_0
#define MYNEWT_VAL_TIMER_0 (0)
#endif

#ifndef MYNEWT_VAL_TIMER_1
#define MYNEWT_VAL_TIMER_1 (0)
#endif

#ifndef MYNEWT_VAL_TIMER_2
#define MYNEWT_VAL_TIMER_2 (0)
#endif

#ifndef MYNEWT_VAL_TIMER_3
#define MYNEWT_VAL_TIMER_3 (1)
#endif

#ifndef MYNEWT_VAL_UART_0
#define MYNEWT_VAL_UART_0 (1)
#endif

#ifndef MYNEWT_VAL_UART_0_PIN_CTS
#define MYNEWT_VAL_UART_0_PIN_CTS (10)
#endif

#ifndef MYNEWT_VAL_UART_0_PIN_RTS
#define MYNEWT_VAL_UART_0_PIN_RTS (8)
#endif

#ifndef MYNEWT_VAL_UART_0_PIN_RX
#define MYNEWT_VAL_UART_0_PIN_RX (11)
#endif

#ifndef MYNEWT_VAL_UART_0_PIN_TX
#define MYNEWT_VAL_UART_0_PIN_TX (9)
#endif

/*** @apache-mynewt-core/hw/mcu/nordic/nrf51xxx */
#ifndef MYNEWT_VAL_ADC_0
#define MYNEWT_VAL_ADC_0 (0)
#endif

#ifndef MYNEWT_VAL_ADC_0_REFMV_0
#define MYNEWT_VAL_ADC_0_REFMV_0 (0)
#endif

#ifndef MYNEWT_VAL_ADC_0_REFMV_1
#define MYNEWT_VAL_ADC_0_REFMV_1 (0)
#endif

#ifndef MYNEWT_VAL_ADC_0_REFMV_VDD
#define MYNEWT_VAL_ADC_0_REFMV_VDD (0)
#endif

#ifndef MYNEWT_VAL_I2C_0
#define MYNEWT_VAL_I2C_0 (0)
#endif

#ifndef MYNEWT_VAL_I2C_1
#define MYNEWT_VAL_I2C_1 (0)
#endif

/* Overridden by @apache-mynewt-core/hw/bsp/nrf51dk-16kbram (defined by @apache-mynewt-core/hw/mcu/nordic/nrf51xxx) */
#ifndef MYNEWT_VAL_MCU_DCDC_ENABLED
#define MYNEWT_VAL_MCU_DCDC_ENABLED (0)
#endif

#ifndef MYNEWT_VAL_MCU_FLASH_MIN_WRITE_SIZE
#define MYNEWT_VAL_MCU_FLASH_MIN_WRITE_SIZE (1)
#endif

#ifndef MYNEWT_VAL_SPI_0_MASTER
#define MYNEWT_VAL_SPI_0_MASTER (0)
#endif

#ifndef MYNEWT_VAL_SPI_0_SLAVE
#define MYNEWT_VAL_SPI_0_SLAVE (0)
#endif

#ifndef MYNEWT_VAL_SPI_1_MASTER
#define MYNEWT_VAL_SPI_1_MASTER (0)
#endif

#ifndef MYNEWT_VAL_SPI_1_SLAVE
#define MYNEWT_VAL_SPI_1_SLAVE (0)
#endif

/* Overridden by @apache-mynewt-core/hw/bsp/nrf51dk-16kbram (defined by @apache-mynewt-core/hw/mcu/nordic/nrf51xxx) */
#ifndef MYNEWT_VAL_XTAL_32768
#define MYNEWT_VAL_XTAL_32768 (1)
#endif

#ifndef MYNEWT_VAL_XTAL_32768_SYNTH
#define MYNEWT_VAL_XTAL_32768_SYNTH (0)
#endif

#ifndef MYNEWT_VAL_XTAL_RC
#define MYNEWT_VAL_XTAL_RC (0)
#endif

/*** @apache-mynewt-core/kernel/os */
#ifndef MYNEWT_VAL_FLOAT_USER
#define MYNEWT_VAL_FLOAT_USER (0)
#endif

#ifndef MYNEWT_VAL_MSYS_1_BLOCK_COUNT
#define MYNEWT_VAL_MSYS_1_BLOCK_COUNT (12)
#endif

#ifndef MYNEWT_VAL_MSYS_1_BLOCK_SIZE
#define MYNEWT_VAL_MSYS_1_BLOCK_SIZE (292)
#endif

#ifndef MYNEWT_VAL_MSYS_2_BLOCK_COUNT
#define MYNEWT_VAL_MSYS_2_BLOCK_COUNT (0)
#endif

#ifndef MYNEWT_VAL_MSYS_2_BLOCK_SIZE
#define MYNEWT_VAL_MSYS_2_BLOCK_SIZE (0)
#endif

#ifndef MYNEWT_VAL_OS_CLI
#define MYNEWT_VAL_OS_CLI (0)
#endif

#ifndef MYNEWT_VAL_OS_COREDUMP
#define MYNEWT_VAL_OS_COREDUMP (0)
#endif

/* Overridden by @apache-mynewt-core/hw/bsp/nrf51dk-16kbram (defined by @apache-mynewt-core/kernel/os) */
#ifndef MYNEWT_VAL_OS_CPUTIME_FREQ
#define MYNEWT_VAL_OS_CPUTIME_FREQ (32768)
#endif

/* Overridden by @apache-mynewt-core/hw/bsp/nrf51dk-16kbram (defined by @apache-mynewt-core/kernel/os) */
#ifndef MYNEWT_VAL_OS_CPUTIME_TIMER_NUM
#define MYNEWT_VAL_OS_CPUTIME_TIMER_NUM (3)
#endif

#ifndef MYNEWT_VAL_OS_CTX_SW_STACK_CHECK
#define MYNEWT_VAL_OS_CTX_SW_STACK_CHECK (0)
#endif

#ifndef MYNEWT_VAL_OS_CTX_SW_STACK_GUARD
#define MYNEWT_VAL_OS_CTX_SW_STACK_GUARD (4)
#endif

/* Overridden by @apache-mynewt-core/apps/blehci (defined by @apache-mynewt-core/kernel/os) */
#ifndef MYNEWT_VAL_OS_MAIN_STACK_SIZE
#define MYNEWT_VAL_OS_MAIN_STACK_SIZE (64)
#endif

#ifndef MYNEWT_VAL_OS_MAIN_TASK_PRIO
#define MYNEWT_VAL_OS_MAIN_TASK_PRIO (127)
#endif

#ifndef MYNEWT_VAL_OS_MEMPOOL_CHECK
#define MYNEWT_VAL_OS_MEMPOOL_CHECK (0)
#endif

#ifndef MYNEWT_VAL_OS_MEMPOOL_POISON
#define MYNEWT_VAL_OS_MEMPOOL_POISON (0)
#endif

#ifndef MYNEWT_VAL_OS_SCHEDULING
#define MYNEWT_VAL_OS_SCHEDULING (1)
#endif

#ifndef MYNEWT_VAL_OS_SYSVIEW
#define MYNEWT_VAL_OS_SYSVIEW (0)
#endif

#ifndef MYNEWT_VAL_OS_SYSVIEW_TRACE_CALLOUT
#define MYNEWT_VAL_OS_SYSVIEW_TRACE_CALLOUT (1)
#endif

#ifndef MYNEWT_VAL_OS_SYSVIEW_TRACE_EVENTQ
#define MYNEWT_VAL_OS_SYSVIEW_TRACE_EVENTQ (1)
#endif

#ifndef MYNEWT_VAL_OS_SYSVIEW_TRACE_MBUF
#define MYNEWT_VAL_OS_SYSVIEW_TRACE_MBUF (0)
#endif

#ifndef MYNEWT_VAL_OS_SYSVIEW_TRACE_MEMPOOL
#define MYNEWT_VAL_OS_SYSVIEW_TRACE_MEMPOOL (0)
#endif

#ifndef MYNEWT_VAL_OS_SYSVIEW_TRACE_MUTEX
#define MYNEWT_VAL_OS_SYSVIEW_TRACE_MUTEX (1)
#endif

#ifndef MYNEWT_VAL_OS_SYSVIEW_TRACE_SEM
#define MYNEWT_VAL_OS_SYSVIEW_TRACE_SEM (1)
#endif

#ifndef MYNEWT_VAL_SANITY_INTERVAL
#define MYNEWT_VAL_SANITY_INTERVAL (15000)
#endif

#ifndef MYNEWT_VAL_WATCHDOG_INTERVAL
#define MYNEWT_VAL_WATCHDOG_INTERVAL (30000)
#endif

/*** @apache-mynewt-core/libc/baselibc */
#ifndef MYNEWT_VAL_BASELIBC_ASSERT_FILE_LINE
#define MYNEWT_VAL_BASELIBC_ASSERT_FILE_LINE (0)
#endif

#ifndef MYNEWT_VAL_BASELIBC_PRESENT
#define MYNEWT_VAL_BASELIBC_PRESENT (1)
#endif

/*** @apache-mynewt-core/sys/console/stub */
#ifndef MYNEWT_VAL_CONSOLE_UART_BAUD
#define MYNEWT_VAL_CONSOLE_UART_BAUD (115200)
#endif

#ifndef MYNEWT_VAL_CONSOLE_UART_DEV
#define MYNEWT_VAL_CONSOLE_UART_DEV ("uart0")
#endif

#ifndef MYNEWT_VAL_CONSOLE_UART_FLOW_CONTROL
#define MYNEWT_VAL_CONSOLE_UART_FLOW_CONTROL (UART_FLOW_CTL_NONE)
#endif

/*** @apache-mynewt-core/sys/flash_map */
#ifndef MYNEWT_VAL_FLASH_MAP_MAX_AREAS
#define MYNEWT_VAL_FLASH_MAP_MAX_AREAS (10)
#endif

/*** @apache-mynewt-core/sys/stats/full */
#ifndef MYNEWT_VAL_STATS_CLI
#define MYNEWT_VAL_STATS_CLI (0)
#endif

#ifndef MYNEWT_VAL_STATS_NAMES
#define MYNEWT_VAL_STATS_NAMES (0)
#endif

#ifndef MYNEWT_VAL_STATS_NEWTMGR
#define MYNEWT_VAL_STATS_NEWTMGR (0)
#endif

/*** @apache-mynewt-core/sys/sysinit */
#ifndef MYNEWT_VAL_SYSINIT_CONSTRAIN_INIT
#define MYNEWT_VAL_SYSINIT_CONSTRAIN_INIT (1)
#endif

#ifndef MYNEWT_VAL_SYSINIT_PANIC_FILE_LINE
#define MYNEWT_VAL_SYSINIT_PANIC_FILE_LINE (0)
#endif

#ifndef MYNEWT_VAL_SYSINIT_PANIC_MESSAGE
#define MYNEWT_VAL_SYSINIT_PANIC_MESSAGE (0)
#endif

/*** @apache-mynewt-nimble/nimble */
#ifndef MYNEWT_VAL_BLE_EXT_ADV
#define MYNEWT_VAL_BLE_EXT_ADV (0)
#endif

#ifndef MYNEWT_VAL_BLE_EXT_ADV_MAX_SIZE
#define MYNEWT_VAL_BLE_EXT_ADV_MAX_SIZE (31)
#endif

#ifndef MYNEWT_VAL_BLE_MAX_CONNECTIONS
#define MYNEWT_VAL_BLE_MAX_CONNECTIONS (1)
#endif

#ifndef MYNEWT_VAL_BLE_MULTI_ADV_INSTANCES
#define MYNEWT_VAL_BLE_MULTI_ADV_INSTANCES (0)
#endif

#ifndef MYNEWT_VAL_BLE_ROLE_BROADCASTER
#define MYNEWT_VAL_BLE_ROLE_BROADCASTER (1)
#endif

#ifndef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_ROLE_CENTRAL (1)
#endif

#ifndef MYNEWT_VAL_BLE_ROLE_OBSERVER
#define MYNEWT_VAL_BLE_ROLE_OBSERVER (1)
#endif

#ifndef MYNEWT_VAL_BLE_ROLE_PERIPHERAL
#define MYNEWT_VAL_BLE_ROLE_PERIPHERAL (1)
#endif

#ifndef MYNEWT_VAL_BLE_WHITELIST
#define MYNEWT_VAL_BLE_WHITELIST (1)
#endif

/*** @apache-mynewt-nimble/nimble/controller */
#ifndef MYNEWT_VAL_BLE_DEVICE
#define MYNEWT_VAL_BLE_DEVICE (1)
#endif

/* Overridden by @apache-mynewt-nimble/nimble/controller (defined by @apache-mynewt-nimble/nimble/controller) */
#ifndef MYNEWT_VAL_BLE_HW_WHITELIST_ENABLE
#define MYNEWT_VAL_BLE_HW_WHITELIST_ENABLE (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_ADD_STRICT_SCHED_PERIODS
#define MYNEWT_VAL_BLE_LL_ADD_STRICT_SCHED_PERIODS (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_CONN_PARAM_REQ
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_CONN_PARAM_REQ (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_DATA_LEN_EXT
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_DATA_LEN_EXT (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_EXT_SCAN_FILT
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_EXT_SCAN_FILT (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_2M_PHY
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_2M_PHY (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_CODED_PHY
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_CODED_PHY (0)
#endif

/* Overridden by @apache-mynewt-nimble/nimble/controller (defined by @apache-mynewt-nimble/nimble/controller) */
#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_CSA2
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_CSA2 (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_ENCRYPTION
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_ENCRYPTION (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_PING
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_PING (MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_ENCRYPTION)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LL_EXT_ADV
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LL_EXT_ADV (MYNEWT_VAL_BLE_EXT_ADV)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LL_PRIVACY
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LL_PRIVACY (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_SLAVE_INIT_FEAT_XCHG
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_SLAVE_INIT_FEAT_XCHG (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CONN_INIT_MAX_TX_BYTES
#define MYNEWT_VAL_BLE_LL_CONN_INIT_MAX_TX_BYTES (27)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CONN_INIT_MIN_WIN_OFFSET
#define MYNEWT_VAL_BLE_LL_CONN_INIT_MIN_WIN_OFFSET (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CONN_INIT_SLOTS
#define MYNEWT_VAL_BLE_LL_CONN_INIT_SLOTS (4)
#endif

#ifndef MYNEWT_VAL_BLE_LL_DIRECT_TEST_MODE
#define MYNEWT_VAL_BLE_LL_DIRECT_TEST_MODE (0)
#endif

/* Overridden by @apache-mynewt-nimble/nimble/controller (defined by @apache-mynewt-nimble/nimble/controller) */
#ifndef MYNEWT_VAL_BLE_LL_EXT_ADV_AUX_PTR_CNT
#define MYNEWT_VAL_BLE_LL_EXT_ADV_AUX_PTR_CNT (5)
#endif

#ifndef MYNEWT_VAL_BLE_LL_MASTER_SCA
#define MYNEWT_VAL_BLE_LL_MASTER_SCA (7)
#endif

#ifndef MYNEWT_VAL_BLE_LL_MAX_PKT_SIZE
#define MYNEWT_VAL_BLE_LL_MAX_PKT_SIZE (251)
#endif

#ifndef MYNEWT_VAL_BLE_LL_MFRG_ID
#define MYNEWT_VAL_BLE_LL_MFRG_ID (0x038F)
#endif

#ifndef MYNEWT_VAL_BLE_LL_NUM_SCAN_DUP_ADVS
#define MYNEWT_VAL_BLE_LL_NUM_SCAN_DUP_ADVS (8)
#endif

#ifndef MYNEWT_VAL_BLE_LL_NUM_SCAN_RSP_ADVS
#define MYNEWT_VAL_BLE_LL_NUM_SCAN_RSP_ADVS (8)
#endif

#ifndef MYNEWT_VAL_BLE_LL_OUR_SCA
#define MYNEWT_VAL_BLE_LL_OUR_SCA (20)
#endif

#ifndef MYNEWT_VAL_BLE_LL_PRIO
#define MYNEWT_VAL_BLE_LL_PRIO (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_RESOLV_LIST_SIZE
#define MYNEWT_VAL_BLE_LL_RESOLV_LIST_SIZE (4)
#endif

#ifndef MYNEWT_VAL_BLE_LL_RNG_BUFSIZE
#define MYNEWT_VAL_BLE_LL_RNG_BUFSIZE (32)
#endif

#ifndef MYNEWT_VAL_BLE_LL_STRICT_CONN_SCHEDULING
#define MYNEWT_VAL_BLE_LL_STRICT_CONN_SCHEDULING (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SUPP_MAX_RX_BYTES
#define MYNEWT_VAL_BLE_LL_SUPP_MAX_RX_BYTES (MYNEWT_VAL_BLE_LL_MAX_PKT_SIZE)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SUPP_MAX_TX_BYTES
#define MYNEWT_VAL_BLE_LL_SUPP_MAX_TX_BYTES (MYNEWT_VAL_BLE_LL_MAX_PKT_SIZE)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SYSVIEW
#define MYNEWT_VAL_BLE_LL_SYSVIEW (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_TX_PWR_DBM
#define MYNEWT_VAL_BLE_LL_TX_PWR_DBM (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_USECS_PER_PERIOD
#define MYNEWT_VAL_BLE_LL_USECS_PER_PERIOD (3250)
#endif

#ifndef MYNEWT_VAL_BLE_LL_WHITELIST_SIZE
#define MYNEWT_VAL_BLE_LL_WHITELIST_SIZE (8)
#endif

#ifndef MYNEWT_VAL_BLE_LP_CLOCK
#define MYNEWT_VAL_BLE_LP_CLOCK (1)
#endif

#ifndef MYNEWT_VAL_BLE_NUM_COMP_PKT_RATE
#define MYNEWT_VAL_BLE_NUM_COMP_PKT_RATE ((2 * configTICK_RATE_HZ))
#endif

#ifndef MYNEWT_VAL_BLE_PUBLIC_DEV_ADDR
#define MYNEWT_VAL_BLE_PUBLIC_DEV_ADDR ((uint8_t[6]){0x8F, 0x7A, 0xF1, 0xEB, 0x49, 0x7C})
#endif

/* Overridden by @apache-mynewt-core/hw/bsp/nrf51dk-16kbram (defined by @apache-mynewt-nimble/nimble/controller) */
#ifndef MYNEWT_VAL_BLE_XTAL_SETTLE_TIME
#define MYNEWT_VAL_BLE_XTAL_SETTLE_TIME (1500)
#endif

/*** @apache-mynewt-nimble/nimble/transport/uart */
#ifndef MYNEWT_VAL_BLE_ACL_BUF_COUNT
#define MYNEWT_VAL_BLE_ACL_BUF_COUNT (12)
#endif

#ifndef MYNEWT_VAL_BLE_ACL_BUF_SIZE
#define MYNEWT_VAL_BLE_ACL_BUF_SIZE (255)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_ACL_OUT_COUNT
#define MYNEWT_VAL_BLE_HCI_ACL_OUT_COUNT (12)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_EVT_BUF_SIZE
#define MYNEWT_VAL_BLE_HCI_EVT_BUF_SIZE (70)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_EVT_HI_BUF_COUNT
#define MYNEWT_VAL_BLE_HCI_EVT_HI_BUF_COUNT (8)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_EVT_LO_BUF_COUNT
#define MYNEWT_VAL_BLE_HCI_EVT_LO_BUF_COUNT (8)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_UART_BAUD
#define MYNEWT_VAL_BLE_HCI_UART_BAUD (921600)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_UART_DATA_BITS
#define MYNEWT_VAL_BLE_HCI_UART_DATA_BITS (8)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_UART_FLOW_CTRL
#define MYNEWT_VAL_BLE_HCI_UART_FLOW_CTRL (HAL_UART_FLOW_CTL_RTS_CTS)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_UART_PARITY
#define MYNEWT_VAL_BLE_HCI_UART_PARITY (HAL_UART_PARITY_NONE)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_UART_PORT
#define MYNEWT_VAL_BLE_HCI_UART_PORT (0)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_UART_STOP_BITS
#define MYNEWT_VAL_BLE_HCI_UART_STOP_BITS (1)
#endif

#endif