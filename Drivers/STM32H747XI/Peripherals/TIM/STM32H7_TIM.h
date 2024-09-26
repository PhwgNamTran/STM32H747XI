#ifndef STM32H7_TIM_H
#define STM32H7_TIM_H

#include "STM32H747xx.h"
#include "STM32H7_RCC.h"

/**
  * @brief  TIM Handle structures definition
  */
typedef struct
{
  TIM_ST                            *Instance;         /*!< Register base address                             */
  TIM_Init_ST                       Init;              /*!< TIM Time Base required parameters                 */
  TIM_ActiveChannel_N               Channel;           /*!< Active channel                                    */
  volatile TIM_StateTypeDef         State;             /*!< TIM operation state                               */
  volatile TIM_ChannelStateTypeDef  ChannelState[6];   /*!< TIM channel operation state                       */
  volatile TIM_ChannelStateTypeDef  ChannelNState[4];  /*!< TIM complementary channel operation state         */
  volatile TIM_DMABurstStateTypeDef DMABurstState;     /*!< DMA burst operation state                         */
} TIM_Handle_ST;

/**
  * @brief  TIM Init structures definition
  */
typedef struct
{
  uint32_t            Prescaler;
  uint32_t            CounterMode;
  uint32_t            Period;
  TIM_ClockDivision_N ClockDivision;
  uint32_t            AutoReloadPreload;
} TIM_Init_ST;

/**
  * @brief  TIM Counter Mode structures definition
  */
typedef enum
{
    TIM_COUNTERMODE_UP_N                = 0x0000U,     /*!< Up counting mode */
    TIM_COUNTERMODE_DOWN_N              = 0x0010U,     /*!< Down counting mode */
    TIM_COUNTERMODE_CENTERALIGNED1_N    = 0x0020U,     /*!< Center-aligned mode 1 */
    TIM_COUNTERMODE_CENTERALIGNED2_N    = 0x0040U,     /*!< Center-aligned mode 2 */
    TIM_COUNTERMODE_CENTERALIGNED3_N    = 0x0060U      /*!< Center-aligned mode 3 */
} TIM_CounterMode_N;

typedef enum
{
    TIM_CC1_INTERRUPT_N = 1U,         /*!< Capture/Compare 1 interrupt */
    TIM_CC2_INTERRUPT_N = 2U,         /*!< Capture/Compare 2 interrupt */
    TIM_CC3_INTERRUPT_N = 3U,         /*!< Capture/Compare 3 interrupt */
    TIM_CC4_INTERRUPT_N = 4U,         /*!< Capture/Compare 4 interrupt */
    TIM_COM_INTERRUPT_N = 5U          /*!< Communication interrupt */
} TIM_Interrupt_N;

/**
  * @brief  TIM DMA Request structures definition
  */
typedef enum
{
    TIM_CC1_DMA_REQUEST_N = 9U,       /*!< Capture/Compare 1 DMA request */
    TIM_CC2_DMA_REQUEST_N = 10U,      /*!< Capture/Compare 2 DMA request */
    TIM_CC3_DMA_REQUEST_N = 11U,      /*!< Capture/Compare 3 DMA request */
    TIM_CC4_DMA_REQUEST_N = 12U,      /*!< Capture/Compare 4 DMA request */
    TIM_COM_DMA_REQUEST_N = 13U       /*!< Communication DMA request */
} TIM_DMA_Request_N;

/**
  * @brief  TIM Active Channel structures definition
  */
typedef enum
{
  TIM_ACTIVE_CHANNEL_1        = 0x01U,    /*!< The active channel is 1     */
  TIM_ACTIVE_CHANNEL_2        = 0x02U,    /*!< The active channel is 2     */
  TIM_ACTIVE_CHANNEL_3        = 0x04U,    /*!< The active channel is 3     */
  TIM_ACTIVE_CHANNEL_4        = 0x08U,    /*!< The active channel is 4     */
  TIM_ACTIVE_CHANNEL_5        = 0x10U,    /*!< The active channel is 5     */
  TIM_ACTIVE_CHANNEL_6        = 0x20U,    /*!< The active channel is 6     */
  TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< All active channels cleared */
} TIM_ActiveChannel_N;

/**
  * @brief  TIM State structures definition
  */
typedef enum
{
  TIM_STATE_RESET             = 0x00U,    /*!< Peripheral not yet initialized or disabled  */
  TIM_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use    */
  TIM_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing              */
  TIM_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state                               */
  TIM_STATE_ERROR             = 0x04U     /*!< Reception process is ongoing                */
} TIM_StateTypeDef;

/**
  * @brief  TIM Channel States definition
  */
typedef enum
{
  TIM_CHANNEL_STATE_RESET     = 0x00U,    /*!< TIM Channel initial state                         */
  TIM_CHANNEL_STATE_READY     = 0x01U,    /*!< TIM Channel ready for use                         */
  TIM_CHANNEL_STATE_BUSY      = 0x02U     /*!< An internal process is ongoing on the TIM channel */
} TIM_ChannelStateTypeDef;

/**
  * @brief  TIM DMA Burst States definition
  */
typedef enum
{
  DMA_BURST_STATE_RESET       = 0x00U,    /*!< DMA Burst initial state */
  DMA_BURST_STATE_READY       = 0x01U,    /*!< DMA Burst ready for use */
  DMA_BURST_STATE_BUSY        = 0x02U     /*!< Ongoing DMA Burst       */
} TIM_DMABurstStateTypeDef;

/**
  * @brief  TIM CLock Division definition
  */
typedef enum
{
    TIM_CLOCKDIVISION_DIV1  = 0x0000U, /*!< Clock division: tDTS=tCK_INT   */
    TIM_CLOCKDIVISION_DIV2  = 0x0100U,     /*!< Clock division: tDTS=2*tCK_INT */
    TIM_CLOCKDIVISION_DIV4  = 0x0200U      /*!< Clock division: tDTS=4*tCK_INT */
}TIM_ClockDivision_N;

extern void TIM_DMA_Interrupt_Mode_Enable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Mode_Disable(TIM_ST *TIMx, uint8_t DMA_Interrupt_Mode);
extern void TIM_DMA_Interrupt_Clear_Status(TIM_ST *TIMx);
extern boolean TIM_DMA_Interrupt_Check_Status(TIM_ST *TIMx);
extern void TIM_Enable(TIM_ST *TIMx);

#endif