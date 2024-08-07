#ifndef CM7_INTERRUPT_HANDLER_H
#define CM7_INTERRUPT_HANDLER_H

#include "STM32H747XI_EXTI.h"
#include "Common.h"
#include "CM7_Project_Cfg.h"
#include "STM32H747XI_TIM.h"
#include "STM32H747XI_USART.h"
#include "STLink_VCP.h"

extern void USART1_IRQHandler(void) ;
extern void EXTI15_10_IRQHandler(void);
extern void TIM2_IRQHandler(void);

#endif