#include "STM32H747XI_TIM.h"

/*
 * Function: TIM_Enable_ClockSource
 * --------------------
 * Enables the clock source for a TIM peripheral.
 *
 * Parameters:
 *   TIM_Num: Timer number to enable the clock source for.
 *
 * Returns:
 *   None
 */
void TIM_Enable_ClockSource(UINT8 TIM_Num) 
{
    switch (TIM_Num)
    {
        case TIM1_Num:
            SET_BIT(RCC->APB2LPENR, TIM1_CLKSRC);  /**< Enable TIM1 clock source */
            break;
        case TIM8_Num:
            SET_BIT(RCC->APB2LPENR, TIM8_CLKSRC);  /**< Enable TIM8 clock source */
            break;
        case TIM15_Num:
            SET_BIT(RCC->APB2LPENR, TIM15_CLKSRC); /**< Enable TIM15 clock source */
            break;
        case TIM16_Num:
            SET_BIT(RCC->APB2LPENR, TIM16_CLKSRC); /**< Enable TIM16 clock source */
            break;
        case TIM17_Num:
            SET_BIT(RCC->APB2LPENR, TIM17_CLKSRC); /**< Enable TIM17 clock source */
            break;
        case TIM2_Num:
            SET_BIT(RCC->APB1LLPENR, TIM2_CLKSRC); /**< Enable TIM2 clock source */
            break;
        case TIM3_Num:
            SET_BIT(RCC->APB1LLPENR, TIM3_CLKSRC); /**< Enable TIM3 clock source */
            break;
        case TIM4_Num:
            SET_BIT(RCC->APB1LLPENR, TIM4_CLKSRC); /**< Enable TIM4 clock source */
            break;
        case TIM5_Num:
            SET_BIT(RCC->APB1LLPENR, TIM5_CLKSRC); /**< Enable TIM5 clock source */
            break;
        case TIM6_Num:
            SET_BIT(RCC->APB1LLPENR, TIM6_CLKSRC); /**< Enable TIM6 clock source */
            break;
        case TIM7_Num:
            SET_BIT(RCC->APB1LLPENR, TIM7_CLKSRC); /**< Enable TIM7 clock source */
            break;
        case TIM12_Num:
            SET_BIT(RCC->APB1LLPENR, TIM12_CLKSRC); /**< Enable TIM12 clock source */
            break;
        case TIM13_Num:
            SET_BIT(RCC->APB1LLPENR, TIM13_CLKSRC); /**< Enable TIM13 clock source */
            break;
        case TIM14_Num:
            SET_BIT(RCC->APB1LLPENR, TIM14_CLKSRC); /**< Enable TIM14 clock source */
            break;
        default:
            // Handle invalid timer number
            break;
    }
}

/*
 * Function: TIM_Config
 * ------------------------
 * Configures the TIM peripheral with the specified prescaler, auto-reload value,
 * and counter direction.
 *
 * Parameters:
 *   TIMx              - Pointer to the TIM peripheral.
 *   TIMx_PSC          - Prescaler value.
 *   TIMx_ARR          - Auto-reload value.
 *   Counter_Direction - Boolean value to set the counter direction.
 *                       TRUE: Down-counting mode.
 *                       FALSE: Up-counting mode.
 *
 * Returns:
 *   None
 */
void TIM_Config(TIM_ST *TIMx, UINT32 TIMx_PSC, UINT32 TIMx_ARR, BOOL Counter_Direction)
{
    WRITE_REG(TIMx->PSC, TIMx_PSC);  // Set the prescaler value
    WRITE_REG(TIMx->ARR, TIMx_ARR);  // Set the auto-reload value
    if(Counter_Direction)
    {
        SET_BIT(TIMx->CR1, CR1_DIR); // Set the counter direction to down-counting
    }
    else
    {
        CLEAR_BIT(TIMx->CR1, CR1_DIR); // Set the counter direction to up-counting
    }
}

/*
 * Function: TIM_DMA_Interrupt_Mode_Enable
 * ------------------------
 * Enables the specified DMA interrupt mode for the given TIM peripheral.
 *
 * Parameters:
 *   TIMx                - Pointer to the TIM peripheral.
 *   DMA_Interrupt_Mode  - DMA interrupt mode to be enabled.
 *
 * Returns:
 *   None
 */
void TIM_DMA_Interrupt_Mode_Enable(TIM_ST *TIMx, UINT8 DMA_Interrupt_Mode)
{
    if(DMA_Interrupt_Mode < TIM_DMA_Interrupt_Reserved)
    {
        SET_BIT(TIMx->DIER, (1 << DMA_Interrupt_Mode)); // Enable the specified DMA interrupt mode
    }
    else
    {
        /* Nothing to do */
    }
}

/*
 * Function: TIM_DMA_Interrupt_Mode_Disable
 * ------------------------
 * Disables the specified DMA interrupt mode for the given TIM peripheral.
 *
 * Parameters:
 *   TIMx                - Pointer to the TIM peripheral.
 *   DMA_Interrupt_Mode  - DMA interrupt mode to be disabled.
 *
 * Returns:
 *   None
 */
void TIM_DMA_Interrupt_Mode_Disable(TIM_ST *TIMx, UINT8 DMA_Interrupt_Mode)
{
    if(DMA_Interrupt_Mode < TIM_DMA_Interrupt_Reserved)
    {
        CLEAR_BIT(TIMx->DIER, (1 << DMA_Interrupt_Mode)); // Disable the specified DMA interrupt mode
    }
    else
    {
        /* Nothing to do */
    }
}

/*
 * Function: TIM_Enable
 * ------------------------
 * Enables the TIM peripheral by setting the CEN bit in the CR1 register.
 *
 * Parameters:
 *   TIMx - Pointer to the TIM peripheral.
 *
 * Returns:
 *   None
 */
void TIM_Enable(TIM_ST *TIMx)
{
    SET_BIT(TIMx->CR1, CR1_CEN); // Enable the TIM peripheral
}
