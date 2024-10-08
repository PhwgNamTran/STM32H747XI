#include "CM7_Interrupt_Handler.h"
#include "CM7_Interrupt_Cfg.h"
#include "Common.h"
#include "UserLED.h"


/*
 * Function: USART1_IRQHandler
 * -----------------------------
 * Interrupt handler for USART1.
 * Checks and handles various USART1 interrupt flags.
 * Clears the interrupt flags after processing.
 * 
 * Parameters:
 *   None
 *
 * Returns:
 *   None
 */

#if(STLINK_VCP_USED && STLink_VCP_Interrupt_USED)
uint16_t static gs_STLink_VCP_RxBuffer_UW[STLink_VCP_USART_RxBufferSize];
uint8_t static gs_STLink_VCP_RxIdx_UB = 0;
#endif

void USART1_IRQHandler(void) 
{
#if(STLINK_VCP_USED && STLink_VCP_Interrupt_USED)
    if (USART_Check_Interrupt_Flag(STLink_VCP_USART, USART_Interrupt_ReceptionDataNotEmpty))
    {
        // Read a single data from the USART
        uint16_t Rx_Data = USART_Receive_Single_Data(STLink_VCP_USART);
        // Echo received data
        USART_Transmit_Single_Data(STLink_VCP_USART, Rx_Data);
        // Store the received data in the buffer and increment the index
        gs_STLink_VCP_RxBuffer_UW[gs_STLink_VCP_RxIdx_UB++] = Rx_Data;
        // Check if there is space in the receive buffer
        if(gs_STLink_VCP_RxIdx_UB == STLink_VCP_USART_RxBufferSize)
        {
            /* USER CODE START */
            UserLED_TOGGLE(UserLED_1);
            /* USER CODE END */
            /* Reset buffer and index */
            gs_STLink_VCP_RxIdx_UB = 0;
            memset(gs_STLink_VCP_RxBuffer_UW, 0x00, STLink_VCP_USART_RxBufferSize * sizeof(uint16_t));
        }
        // Clear the interrupt flag for reception data
        USART_Clear_Interrupt_Flag(STLink_VCP_USART, USART_Interrupt_ReceptionDataNotEmpty);
    }
    else
    {
        /* Other Interrupt Flags ... */
    }
#endif
}

/*
 * Function: TIM2_IRQHandler
 * --------------------------
 * Interrupt handler for TIM2.
 * Checks and handles DMA interrupt status for TIM2.
 * If DMA interrupt is set, toggles User LED 1 and clears the interrupt status.
 * 
 * Parameters:
 *   None
 *
 * Returns:
 *   None
 */
void TIM2_IRQHandler(void)
{
#if(TIM2_USED && TIM2_Interrupt_USED)
    if (TIM_DMA_Interrupt_Check_Status(TIM2))
    {
        #if(USER_LED_1_USED)
        UserLED_TOGGLE(UserLED_1);        // Toggle User LED 1
        #endif
        TIM_DMA_Interrupt_Clear_Status(TIM2);  // Clear DMA interrupt status for TIM2
    }
    else
    {
        // Handle other conditions if needed
    }
#endif
}

/*
 * Function: EXTI15_10_IRQHandler
 * ------------------------------
 * Interrupt handler for EXTI lines 10 to 15.
 *
 * This function handles interrupt requests for EXTI lines 10 to 15 based on configuration.
 * It clears the trigger request flag and optionally executes user-defined code.
 */
void EXTI15_10_IRQHandler(void)
{
#if(EXTI_10_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_10))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_10);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif

#if(EXTI_11_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_11))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_11);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif

#if(EXTI_12_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_12))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_12);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif

#if(EXTI_13_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_13))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_13);
        /* USER CODE START */
        #if(USER_LED_1_USED)
        UserLED_TOGGLE(UserLED_1); // Example user code: Toggle UserLED_1 on EXTI 13
        #endif
        /* USER CODE END */
    }
#endif

#if(EXTI_14_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_14))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_14);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif

#if(EXTI_15_ENABLED)
    if (EXTI_Trigger_Request_Occurred_C1_B(Event_Input_EXTI_15))
    {
        EXTI_Clear_Trigger_Request_Flag_C1(Event_Input_EXTI_15);
        /* USER CODE START */

        /* USER CODE END */
    }
#endif
}
