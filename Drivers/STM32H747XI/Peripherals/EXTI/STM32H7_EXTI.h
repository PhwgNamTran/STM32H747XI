#ifndef STM32H7_EXTI_H
#define STM32H7_EXTI_H

#include "STM32H747xx.h"

typedef enum
{
    Event_Input_EXTI_0                           = 0,
    Event_Input_EXTI_1                           = 1,
    Event_Input_EXTI_2                           = 2,
    Event_Input_EXTI_3                           = 3,
    Event_Input_EXTI_4                           = 4,
    Event_Input_EXTI_5                           = 5,
    Event_Input_EXTI_6                           = 6,
    Event_Input_EXTI_7                           = 7,
    Event_Input_EXTI_8                           = 8,
    Event_Input_EXTI_9                           = 9,
    Event_Input_EXTI_10                          = 10,
    Event_Input_EXTI_11                          = 11,
    Event_Input_EXTI_12                          = 12,
    Event_Input_EXTI_13                          = 13,
    Event_Input_EXTI_14                          = 14,
    Event_Input_EXTI_15                          = 15,
    Event_Input_PVD_AVD                          = 16,
    Event_Input_RTC_Alarms                       = 17,
    Event_Input_RTC_Tamper_Timestamp_LSECSS      = 18,
    Event_Input_RTC_Wakeup_Timer                 = 19,
    Event_Input_COMP1                            = 20,
    Event_Input_COMP2                            = 21,
    Event_Input_I2C1_Wakeup                      = 22,
    Event_Input_I2C2_Wakeup                      = 23,
    Event_Input_I2C3_Wakeup                      = 24,
    Event_Input_I2C4_Wakeup                      = 25,
    Event_Input_USART1_Wakeup                    = 26,
    Event_Input_USART2_Wakeup                    = 27,
    Event_Input_USART3_Wakeup                    = 28,
    Event_Input_USART6_Wakeup                    = 29,
    Event_Input_UART4_Wakeup                     = 30,
    Event_Input_UART5_Wakeup                     = 31,
    Event_Input_UART7_Wakeup                     = 32,
    Event_Input_UART8_Wakeup                     = 33,
    Event_Input_LPUART1_RX_Wakeup                = 34,
    Event_Input_LPUART1_TX_Wakeup                = 35,
    Event_Input_SPI1_Wakeup                      = 36,
    Event_Input_SPI2_Wakeup                      = 37,
    Event_Input_SPI3_Wakeup                      = 38,
    Event_Input_SPI4_Wakeup                      = 39,
    Event_Input_SPI5_Wakeup                      = 40,
    Event_Input_SPI6_Wakeup                      = 41,
    Event_Input_MDIO_Wakeup                      = 42,
    Event_Input_USB1_Wakeup                      = 43,
    Event_Input_USB2_Wakeup                      = 44,
    Event_Input_DSI_Wakeup                       = 46,
    Event_Input_LPTIM1_Wakeup                    = 47,
    Event_Input_LPTIM2_Wakeup                    = 48,
    Event_Input_LPTIM2_Output                    = 49,
    Event_Input_LPTIM3_Wakeup                    = 50,
    Event_Input_LPTIM3_Output                    = 51,
    Event_Input_LPTIM4_Wakeup                    = 52,
    Event_Input_LPTIM5_Wakeup                    = 53,
    Event_Input_SWPMI_Wakeup                     = 54,
    Event_Input_WKUP1                            = 55,
    Event_Input_WKUP2                            = 56,
    Event_Input_WKUP3                            = 57,
    Event_Input_WKUP4                            = 58,
    Event_Input_WKUP5                            = 59,
    Event_Input_WKUP6                            = 60,
    Event_Input_RCC_Interrupt                    = 61,
    Event_Input_I2C4_Event_Interrupt             = 62,
    Event_Input_I2C4_Error_Interrupt             = 63,
    Event_Input_LPUART1_Global_Interrupt         = 64,
    Event_Input_SPI6_Interrupt                   = 65,
    Event_Input_BDMA_CH0_Interrupt               = 66,
    Event_Input_BDMA_CH1_Interrupt               = 67,
    Event_Input_BDMA_CH2_Interrupt               = 68,
    Event_Input_BDMA_CH3_Interrupt               = 69,
    Event_Input_BDMA_CH4_Interrupt               = 70,
    Event_Input_BDMA_CH5_Interrupt               = 71,
    Event_Input_BDMA_CH6_Interrupt               = 72,
    Event_Input_BDMA_CH7_Interrupt               = 73,
    Event_Input_DMAMUX2_Interrupt                = 74,
    Event_Input_ADC3_Interrupt                   = 75,
    Event_Input_SAI4_Interrupt                   = 76,
    Event_Input_HSEM0_Interrupt                  = 77,
    Event_Input_HSEM1_Interrupt                  = 78,
    Event_Input_CortexM4_SEV_Interrupt           = 79,
    Event_Input_CortexM7_SEV_Interrupt           = 80,
    Event_Input_WWDG1_Reset                      = 82,
    Event_Input_WWDG2_Reset                      = 84,
    Event_Input_HDMI_CEC_Wakeup                  = 85,
    Event_Input_ETHERNET_Wakeup                  = 86,
    Event_Input_HSECSS_Interrupt                 = 87
}Event_Input_N;

extern void EXTI_Enable_Event_Input_Interrupt_CPU1(Event_Input_N Event_Input);
extern void EXTI_Enable_Event_Input_Interrupt_CPU2(Event_Input_N Event_Input);

extern void EXTI_Disable_Event_Input_Interrupt_CPU1(Event_Input_N Event_Input);
extern void EXTI_Disable_Event_Input_Interrupt_CPU2(Event_Input_N Event_Input);

extern void EXTI_Clear_Trigger_Request_Flag_CPU1(Event_Input_N Event_Input);
extern void EXTI_Clear_Trigger_Request_Flag_CPU2(Event_Input_N Event_Input);

extern boolean EXTI_Trigger_Request_Occurred_CPU1_B(Event_Input_N Event_Input);
extern boolean EXTI_Trigger_Request_Occurred_CPU2_B(Event_Input_N Event_Input);

extern void EXTI_Enable_Rising_Trigger(Event_Input_N Event_Input);
extern void EXTI_Disable_Rising_Trigger(Event_Input_N Event_Input);

extern void EXTI_Enable_Falling_Trigger(Event_Input_N Event_Input);
extern void EXTI_Disable_Falling_Trigger(Event_Input_N Event_Input);

#endif