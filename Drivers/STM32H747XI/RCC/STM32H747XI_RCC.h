#ifndef STM32H747XI_RCC_H
#define STM32H747XI_RCC_H

#include "Common.h"

/* Refer to RM0399 Reference Manual from http://www.st.com */

/* RCC Register - Refer to CMSIS Library */
typedef struct
{
    volatile UINT32 CR;             /**< RCC clock control register,                             Address offset: 0x00  */
    volatile UINT32 HSICFGR;        /**< HSI Clock Calibration Register,                         Address offset: 0x04  */
    volatile UINT32 CRRCR;          /**< Clock Recovery RC  Register,                            Address offset: 0x08  */
    volatile UINT32 CSICFGR;        /**< CSI Clock Calibration Register,                         Address offset: 0x0C  */
    volatile UINT32 CFGR;           /**< RCC clock configuration register,                       Address offset: 0x10  */
    volatile UINT32 RESERVED1;      /**< Reserved,                                               Address offset: 0x14  */
    volatile UINT32 D1CFGR;         /**< RCC Domain 1 configuration register,                    Address offset: 0x18  */
    volatile UINT32 D2CFGR;         /**< RCC Domain 2 configuration register,                    Address offset: 0x1C  */
    volatile UINT32 D3CFGR;         /**< RCC Domain 3 configuration register,                    Address offset: 0x20  */
    volatile UINT32 RESERVED2;      /**< Reserved,                                               Address offset: 0x24  */
    volatile UINT32 PLLCKSELR;      /**< RCC PLLs Clock Source Selection Register,               Address offset: 0x28  */
    volatile UINT32 PLLCFGR;        /**< RCC PLLs  Configuration Register,                       Address offset: 0x2C  */
    volatile UINT32 PLL1DIVR;       /**< RCC PLL1 Dividers Configuration Register,               Address offset: 0x30  */
    volatile UINT32 PLL1FRACR;      /**< RCC PLL1 Fractional Divider Configuration Register,     Address offset: 0x34  */
    volatile UINT32 PLL2DIVR;       /**< RCC PLL2 Dividers Configuration Register,               Address offset: 0x38  */
    volatile UINT32 PLL2FRACR;      /**< RCC PLL2 Fractional Divider Configuration Register,     Address offset: 0x3C  */
    volatile UINT32 PLL3DIVR;       /**< RCC PLL3 Dividers Configuration Register,               Address offset: 0x40  */
    volatile UINT32 PLL3FRACR;      /**< RCC PLL3 Fractional Divider Configuration Register,     Address offset: 0x44  */
    volatile UINT32 RESERVED3;      /**< Reserved,                                               Address offset: 0x48  */
    volatile UINT32 D1CCIPR;        /**< RCC Domain 1 Kernel Clock Configuration Register        Address offset: 0x4C  */
    volatile UINT32 D2CCIP1R;       /**< RCC Domain 2 Kernel Clock Configuration Register        Address offset: 0x50  */
    volatile UINT32 D2CCIP2R;       /**< RCC Domain 2 Kernel Clock Configuration Register        Address offset: 0x54  */
    volatile UINT32 D3CCIPR;        /**< RCC Domain 3 Kernel Clock Configuration Register        Address offset: 0x58  */
    volatile UINT32 RESERVED4;      /**< Reserved,                                               Address offset: 0x5C  */
    volatile UINT32 CIER;           /**< RCC Clock Source Interrupt Enable Register              Address offset: 0x60  */
    volatile UINT32 CIFR;           /**< RCC Clock Source Interrupt Flag Register                Address offset: 0x64  */
    volatile UINT32 CICR;           /**< RCC Clock Source Interrupt Clear Register               Address offset: 0x68  */
    volatile UINT32 RESERVED5;      /**< Reserved,                                               Address offset: 0x6C  */
    volatile UINT32 BDCR;           /**< RCC Vswitch Backup Domain Control Register,             Address offset: 0x70  */
    volatile UINT32 CSR;            /**< RCC clock control & status register,                    Address offset: 0x74  */
    volatile UINT32 RESERVED6;      /**< Reserved,                                               Address offset: 0x78  */
    volatile UINT32 AHB3RSTR;       /**< RCC AHB3 peripheral reset register,                     Address offset: 0x7C  */
    volatile UINT32 AHB1RSTR;       /**< RCC AHB1 peripheral reset register,                     Address offset: 0x80  */
    volatile UINT32 AHB2RSTR;       /**< RCC AHB2 peripheral reset register,                     Address offset: 0x84  */
    volatile UINT32 AHB4RSTR;       /**< RCC AHB4 peripheral reset register,                     Address offset: 0x88  */
    volatile UINT32 APB3RSTR;       /**< RCC APB3 peripheral reset register,                     Address offset: 0x8C  */
    volatile UINT32 APB1LRSTR;      /**< RCC APB1 peripheral reset Low Word register,            Address offset: 0x90  */
    volatile UINT32 APB1HRSTR;      /**< RCC APB1 peripheral reset High Word register,           Address offset: 0x94  */
    volatile UINT32 APB2RSTR;       /**< RCC APB2 peripheral reset register,                     Address offset: 0x98  */
    volatile UINT32 APB4RSTR;       /**< RCC APB4 peripheral reset register,                     Address offset: 0x9C  */
    volatile UINT32 GCR;            /**< RCC RCC Global Control  Register,                       Address offset: 0xA0  */
    volatile UINT32 RESERVED8;      /**< Reserved,                                               Address offset: 0xA4  */
    volatile UINT32 D3AMR;          /**< RCC Domain 3 Autonomous Mode Register,                  Address offset: 0xA8  */
    volatile UINT32 RESERVED11[9];  /**< Reserved, 0xAC-0xCC                                     Address offset: 0xAC  */
    volatile UINT32 RSR;            /**< RCC Reset status register,                              Address offset: 0xD0  */
    volatile UINT32 AHB3ENR;        /**< RCC AHB3 peripheral clock  register,                    Address offset: 0xD4  */
    volatile UINT32 AHB1ENR;        /**< RCC AHB1 peripheral clock  register,                    Address offset: 0xD8  */
    volatile UINT32 AHB2ENR;        /**< RCC AHB2 peripheral clock  register,                    Address offset: 0xDC  */
    volatile UINT32 AHB4ENR;        /**< RCC AHB4 peripheral clock  register,                    Address offset: 0xE0  */
    volatile UINT32 APB3ENR;        /**< RCC APB3 peripheral clock  register,                    Address offset: 0xE4  */
    volatile UINT32 APB1LENR;       /**< RCC APB1 peripheral clock  Low Word register,           Address offset: 0xE8  */
    volatile UINT32 APB1HENR;       /**< RCC APB1 peripheral clock  High Word register,          Address offset: 0xEC  */
    volatile UINT32 APB2ENR;        /**< RCC APB2 peripheral clock  register,                    Address offset: 0xF0  */
    volatile UINT32 APB4ENR;        /**< RCC APB4 peripheral clock  register,                    Address offset: 0xF4  */
    volatile UINT32 RESERVED12;     /**< Reserved,                                               Address offset: 0xF8  */
    volatile UINT32 AHB3LPENR;      /**< RCC AHB3 peripheral sleep clock  register,              Address offset: 0xFC  */
    volatile UINT32 AHB1LPENR;      /**< RCC AHB1 peripheral sleep clock  register,              Address offset: 0x100 */
    volatile UINT32 AHB2LPENR;      /**< RCC AHB2 peripheral sleep clock  register,              Address offset: 0x104 */
    volatile UINT32 AHB4LPENR;      /**< RCC AHB4 peripheral sleep clock  register,              Address offset: 0x108 */
    volatile UINT32 APB3LPENR;      /**< RCC APB3 peripheral sleep clock  register,              Address offset: 0x10C */
    volatile UINT32 APB1LLPENR;     /**< RCC APB1 peripheral sleep clock  Low Word register,     Address offset: 0x110 */
    volatile UINT32 APB1HLPENR;     /**< RCC APB1 peripheral sleep clock  High Word register,    Address offset: 0x114 */
    volatile UINT32 APB2LPENR;      /**< RCC APB2 peripheral sleep clock  register,              Address offset: 0x118 */
    volatile UINT32 APB4LPENR;      /**< RCC APB4 peripheral sleep clock  register,              Address offset: 0x11C */
    volatile UINT32 RESERVED13[4];  /**< Reserved, 0x120-0x12C                                   Address offset: 0x120 */
} RCC_ST;

/**< RCC Core Register - Refer to CMSIS Library */
typedef struct
{
    volatile UINT32 RSR;            /**< RCC Reset status register,                              Address offset: 0x00 */
    volatile UINT32 AHB3ENR;        /**< RCC AHB3 peripheral clock  register,                    Address offset: 0x04 */
    volatile UINT32 AHB1ENR;        /**< RCC AHB1 peripheral clock  register,                    Address offset: 0x08 */
    volatile UINT32 AHB2ENR;        /**< RCC AHB2 peripheral clock  register,                    Address offset: 0x0C */
    volatile UINT32 AHB4ENR;        /**< RCC AHB4 peripheral clock  register,                    Address offset: 0x10 */
    volatile UINT32 APB3ENR;        /**< RCC APB3 peripheral clock  register,                    Address offset: 0x14 */
    volatile UINT32 APB1LENR;       /**< RCC APB1 peripheral clock  Low Word register,           Address offset: 0x18 */
    volatile UINT32 APB1HENR;       /**< RCC APB1 peripheral clock  High Word register,          Address offset: 0x1C */
    volatile UINT32 APB2ENR;        /**< RCC APB2 peripheral clock  register,                    Address offset: 0x20 */
    volatile UINT32 APB4ENR;        /**< RCC APB4 peripheral clock  register,                    Address offset: 0x24 */
    volatile UINT32 RESERVED9;      /**< Reserved,                                               Address offset: 0x28 */
    volatile UINT32 AHB3LPENR;      /**< RCC AHB3 peripheral sleep clock  register,              Address offset: 0x3C */
    volatile UINT32 AHB1LPENR;      /**< RCC AHB1 peripheral sleep clock  register,              Address offset: 0x40 */
    volatile UINT32 AHB2LPENR;      /**< RCC AHB2 peripheral sleep clock  register,              Address offset: 0x44 */
    volatile UINT32 AHB4LPENR;      /**< RCC AHB4 peripheral sleep clock  register,              Address offset: 0x48 */
    volatile UINT32 APB3LPENR;      /**< RCC APB3 peripheral sleep clock  register,              Address offset: 0x4C */
    volatile UINT32 APB1LLPENR;     /**< RCC APB1 peripheral sleep clock  Low Word register,     Address offset: 0x50 */
    volatile UINT32 APB1HLPENR;     /**< RCC APB1 peripheral sleep clock  High Word register,    Address offset: 0x54 */
    volatile UINT32 APB2LPENR;      /**< RCC APB2 peripheral sleep clock  register,              Address offset: 0x58 */
    volatile UINT32 APB4LPENR;      /**< RCC APB4 peripheral sleep clock  register,              Address offset: 0x5C */
    volatile UINT32 RESERVED10[4];  /**< Reserved, 0x60-0x6C                                     Address offset: 0x60 */
} RCC_Core_ST;

#define RCC_BASE    0x58024400U     /**< RCC Base Address */
#define RCC_C1_BASE 0x58024530U     /**< RCC Core 1 Base Address */
#define RCC_C2_BASE 0x58024590U     /**< RCC Core 2 Base Address */

/* RCC & RCC Core Declaration */
#define RCC         ((RCC_ST *) RCC_BASE)
#define RCC_C1      ((RCC_Core_ST *) RCC_C1_BASE)
#define RCC_C2      ((RCC_Core_ST *) RCC_C2_BASE)

#define System_Clock_Source_HSI         1U
#define System_Clock_Source_HSE         2U
#define System_Clock_Source_CSI         3U
#define System_Clock_Source_PLL1_P_CK   4U

#define CR_HSI_POS      0U
#define CR_HSI          (1 << CR_HSI_POS)

#define CR_HSIDIV_POS   3U

#define HSI_Clock   64000000U

#endif