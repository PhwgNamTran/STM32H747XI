#include "STLink_VCP.h"

/**
 * Function: STLink_VCP_Init
 * -------------------------
 * Initializes the STLink VCP USART with specified parameters.
 *
 * Parameters:
 *   SysClock_Hz - The system clock in Hz.
 *
 * Returns:
 *   None
 */
void STLink_VCP_Init(uint32_t SysClock_Hz, USART_Mode Mode)
{
    // Enable clock source for USART PIN
    GPIO_Enable_ClockSource(STLink_VCP_USART_GPIO_Port_CLKSRC);

    // Enable clock source for USART
    USART_Enable_ClockSource(STLink_VCP_USART);

    // Configure USART pins
    USART_PIN_Config(STLink_VCP_USART_GPIO_Port, STLink_VCP_USART_GPIO_AFx,
                     STLink_VCP_USART_Rx_PIN, STLink_VCP_USART_Tx_PIN);
    
    // Configure USART with given parameters
    USART_Config(STLink_VCP_USART, SysClock_Hz, STLink_VCP_USART_Baudrate, 
                 STLink_VCP_USART_OverSamplingMode, STLink_VCP_USART_DataLengthCode, 
                 STLink_VCP_USART_NumberOfStopBit, STLink_VCP_USART_ParityCheck);
    // Config USART Operation Mode
    USART_SetMode(STLink_VCP_USART, Mode);
    // Enable USART
    USART_Enable(STLink_VCP_USART);
}

void STLink_VCP_Interrupt_Init(USART_Interrupt_Mode Interrupt_Mode)
{
    USART_Enable_Interrupt(STLink_VCP_USART, (uint32_t)Interrupt_Mode);
    NVIC_EnableIRQ(STLink_VCP_USART_IRQn);
}

/**
 * Function: STLink_VCP_Send
 * -------------------------
 * Sends a null-terminated string over the STLink VCP USART.
 *
 * Parameters:
 *   str - Pointer to the null-terminated string to be transmitted.
 *
 * Returns:
 *   None
 */
void STLink_VCP_Send(const char *str)
{
    USART_Transmit(STLink_VCP_USART, str);
}

