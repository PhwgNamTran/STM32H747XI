#include "STLink_VCP.h"

/**
 * Function: STLink_VCP_Init
 * -------------------------
 * Initializes the STLink VCP USART with specified parameters.
 *
 * Parameters:
 *   None
 *
 * Returns:
 *   None
 */
void STLink_VCP_Init(void)
{
    // Enable clock source for USART PIN
    GPIO_Enable_ClockSource(STLink_VCP_USART_GPIO_Port_CLKSRC);

    // Enable clock source for USART
    USART_Enable_ClockSource(STLink_VCP_USART);

    // Configure USART pins
    USART_PIN_Config(STLink_VCP_USART_GPIO_Port, STLink_VCP_USART_GPIO_AFx,
                     STLink_VCP_USART_Rx_PIN, STLink_VCP_USART_Tx_PIN);
    
    // Configure USART with given parameters
    USART_Config(STLink_VCP_USART, 16000000U, STLink_VCP_USART_Baudrate, 
                 STLink_VCP_USART_OverSamplingMode, STLink_VCP_USART_DataLengthCode, 
                 STLink_VCP_USART_NumberOfStopBit, STLink_VCP_USART_ParityCheck);

    // Enable USART
    USART_Enable(STLink_VCP_USART);
}
