#ifndef ASPACE_H
#define ASPACE_H

/* Memory Address Mapping */
#define ROM_BASE		(0x40000000)
#define ROM_SIZE		(0x50000)

#define HP_SRAM_BASE	(0x40800000)
#define HP_SRAM_SIZE	(0x80000)

#define FLASH_BASE		(0x42000000)
#define FLASH_SIZE		(0x1000000)

#define LP_SRAM_BASE	(0x50000000)
#define LP_SRAM_SIZE	(0x4000)

#define PERI_BASE		(0x60000000)
#define PERI_SIZE		(0xD0000)

/* Peripheral/Module Address Mapping */
#define UART0_OFS			(0x0)
#define UART0_BASE			(PERI_BASE + UART0_OFS)
#define UART0_SIZE			(0x1000)

#define UART1_OFS			(0x1000)
#define UART1_BASE			(PERI_BASE + UART1_OFS)
#define UART1_SIZE			(0x1000)

#define XTS_AES_OFS			(0x2000)
#define XTS_AES_BASE		(PERI_BASE + XTS_AES_OFS)
#define XTS_AES_SIZE		(0x1000)

#define I2C_OFS				(0x4000)
#define I2C_BASE			(PERI_BASE + I2C_OFS)
#define I2C_SIZE			(0x1000)

#define UHCI_OFS			(0x5000)
#define UHCI_BASE			(PERI_BASE + UHCI_OFS)
#define UHCI_SIZE			(0x1000)

#define RMT_OFS				(0x6000)
#define RMT_BASE			(PERI_BASE + RMT_OFS)
#define RMT_SIZE			(0x1000)

#define LEDC_OFS			(0x7000)
#define LEDC_BASE			(PERI_BASE + LEDC_OFS)
#define LEDC_SIZE			(0x1000)

#define TIMG0_OFS			(0x8000)
#define TIMG0_BASE			(PERI_BASE + TIMG0_OFS)
#define TIMG0_SIZE			(0x1000)

#define TIMG1_OFS			(0x9000)
#define TIMG1_BASE			(PERI_BASE + TIMG1_OFS)
#define TIMG1_SIZE			(0x1000)

#define SYSTIMER_OFS		(0xA000)
#define SYST1MER_BASE		(PERI_BASE + SYSTIMER_OFS)
#define SYST1MER_SIZE		(0x1000)

#define TWAI0_OFS			(0xB000)
#define TWAI0_BASE			(PERI_BASE + TWAI0_OFS)
#define TWAI0_SIZE			(0x1000)

#define I2S_OFS				(0xC000)
#define I2S_BASE			(PERI_BASE + I2S_OFS)
#define I2S_SIZE			(0x1000)

#define TWAI1_OFS			(0xD000)
#define TWAI1_BASE			(PERI_BASE + TWAI1_OFS)
#define TWAI1_SIZE			(0x1000)

#define SAR_ADC_OFS			(0xE000)
#define SAR_ADC_BASE		(PERI_BASE + SAR_ADC_OFS)
#define SAR_ADC_SIZE		(0x1000)

#define USB_JTAG_OFS		(0xF000)
#define USB_JTAG_BASE		(PERI_BASE + USB_JTAG_OFS)
#define USB_JTAG_SIZE		(0x1000)

#define INTMTX_OFS			(0x10000)
#define INTMTX_BASE			(PERI_BASE + INTMTX_OFS)
#define INTMTX_SIZE			(0x1000)

#define PCNT_OFS			(0x12000)
#define PCNT_BASE			(PERI_BASE + PCNT_OFS)
#define PCNT_SIZE			(0x1000)

#define SOC_ETM_OFS			(0x13000)
#define SOC_ETM_BASE		(PERI_BASE + SOC_ETM_OFS)
#define SOC_ETM_SIZE		(0x1000)

#define MCPWM_OFS			(0x14000)
#define MCPWM_BASE			(PERI_BASE + MCPWM_OFS)
#define MCPWM_SIZE			(0x1000)

#define PARL_IO_OFS			(0x15000)
#define PARL_IO_BASE		(PERI_BASE + PARL_IO_OFS)
#define PARL_IO_SIZE		(0x1000)

#define SDIO_HINF_OFS		(0x16000)
#define SDIO_HINF_BASE		(PERI_BASE + SDIO_HINF_OFS)
#define SDIO_HINF_SIZE		(0x1000)

#define SDIO_SLC_OFS		(0x17000)
#define SDIO_SLC_BASE		(PERI_BASE + SDIO_SLC_OFS)
#define SDIO_SLC_SIZE		(0x1000)

#define SDIO_SLCHOST_OFS	(0x18000)
#define SDIO_SLCHOST_BASE	(PERI_BASE + SDIO_SLCHOST_OFS)
#define SDIO_SLCHOST_SIZE	(0x1000)

#define GDMA_OFS			(0x80000)
#define GDMA_BASE			(PERI_BASE + GDMA_OFS)
#define GDMA_SIZE			(0x1000)

#define GP_SPI2_OFS			(0x81000)
#define GP_SPI2_BASE		(PERI_BASE + GP_SPI2_OFS)
#define GP_SPI2_SIZE		(0x1000)

#define AES_OFS				(0x88000)
#define AES_BASE			(PERI_BASE + AES_OFS)
#define AES_SIZE			(0x1000)

#define SHA_OFS				(0x89000)
#define SHA_BASE			(PERI_BASE + SHA_OFS)
#define SHA_SIZE			(0x1000)

#define RSA_OFS				(0x8A000)
#define RSA_BASE			(PERI_BASE + RSA_OFS)
#define RSA_SIZE			(0x1000)

#define ECC_OFS				(0x8B000)
#define ECC_BASE			(PERI_BASE + ECC_OFS)
#define ECC_SIZE			(0x1000)

#define DS_OFS				(0x8C000)
#define DS_BASE				(PERI_BASE + DS_OFS)
#define DS_SIZE				(0x1000)

#define HMAC_OFS			(0x8D000)
#define HMAC_BASE			(PERI_BASE + HMAC_OFS)
#define HMAC_SIZE			(0x1000)

#define IO_MUX_OFS			(0x90000)
#define IO_MUX_BASE			(PERI_BASE + IO_MUX_OFS)
#define IO_MUX_SIZE			(0x1000)

#define GPIO_OFS			(0x91000)
#define GPIO_BASE			(PERI_BASE + GPIO_OFS)
#define GPIO_SIZE			(0x1000)

#define MEM_MON_OFS			(0x92000)
#define MEM_MON_BASE		(PERI_BASE + MEM_MON_OFS)
#define MEM_MON_SIZE		(0x1000)

#define HP_SYSREG_OFS		(0x95000)
#define HP_SYSREG_BASE		(PERI_BASE + HP_SYSREG_OFS)
#define HP_SYSREG_SIZE		(0x1000)

#define PCR_OFS				(0x96000)
#define PCR_BASE			(PERI_BASE + PCR_OFS)
#define PCR_SIZE			(0x1000)

#define TEE_OFS				(0x98000)
#define TEE_BASE			(PERI_BASE + TEE_OFS)
#define TEE_SIZE			(0x1000)

#define HP_APM_OFS			(0x99000)
#define HP_APM_BASE			(PERI_BASE + HP_APM_OFS)
#define HP_APM_SIZE			(0x1000)

#define PMU_OFS				(0xB0000)
#define PMU_BASE			(PERI_BASE + PMU_OFS)
#define PMU_SIZE			(0x400)

#define LP_CLKRST_OFS		(0xB0400)
#define LP_CLKRST_BASE		(PERI_BASE + LP_CLKRST_OFS)
#define LP_CLKRST_SIZE		(0x400)

#define EFUSE_OFS			(0xB0800)
#define EFUSE_BASE			(PERI_BASE + EFUSE_OFS)
#define EFUSE_SIZE			(0x400)

#define RTC_TIMER_OFS		(0xB0C00)
#define RTC_TIMER_BASE		(PERI_BASE + RTC_TIMER_OFS)
#define RTC_TIMER_SIZE		(0x400)

#define LP_AON_OFS			(0xB1000)
#define LP_AON_BASE			(PERI_BASE + LP_AON_OFS)
#define LP_AON_SIZE			(0x400)

#define LP_UART_OFS			(0xB1400)
#define LP_UART_BASE		(PERI_BASE + LP_UART_OFS)
#define LP_UART_SIZE		(0x400)

#define LP_I2C_OFS			(0xB1800)
#define LP_I2C_BASE			(PERI_BASE + LP_I2C_OFS)
#define LP_I2C_SIZE			(0x400)

#define RTC_WDT_OFS			(0xB1C00)
#define RTC_WDT_BASE		(PERI_BASE + RTC_WDT_OFS)
#define RTC_WDT_SIZE		(0x400)

#define LP_IO_MUX_OFS		(0xB2000)
#define LP_IO_MUX_BASE		(PERI_BASE + LP_IO_MUX_OFS)
#define LP_IO_MUX_SIZE		(0x400)

#define I2C_ANA_MST_OFS		(0xB2400)
#define I2C_ANA_MST_BASE	(PERI_BASE + I2C_ANA_MST_OFS)
#define I2C_ANA_MST_SIZE	(0x400)

#define LPPERI_OFS			(0xB2800)
#define LPPERI_BASE			(PERI_BASE + LPPERI_OFS)
#define LPPERI_SIZE			(0x400)

#define LP_ANA_PERI_OFS		(0xB2C00)
#define LP_ANA_PERI_BASE	(PERI_BASE + LP_ANA_PERI_OFS)
#define LP_ANA_PERI_SIZE	(0x400)

#define LP_TEE_OFS			(0xB3400)
#define LP_TEE_BASE			(PERI_BASE + LP_TEE_OFS)
#define LP_TEE_SIZE			(0x400)

#define LP_APM_OFS			(0xB3800)
#define LP_APM_BASE			(PERI_BASE + LP_APM_OFS)
#define LP_APM_SIZE			(0x400)

#define TRACE_OFS			(0xC0000)
#define TRACE_BASE			(PERI_BASE + TRACE_OFS)
#define TRACE_SIZE			(0x1000)

#define ASSIST_DEBUG_OFS	(0xC2000)
#define ASSIST_DEBUG_BASE	(PERI_BASE + ASSIST_DEBUG_OFS)
#define ASSIST_DEBUG_SIZE	(0x1000)

#define INTPRI_OFS			(0xC5000)
#define INTPRI_BASE			(PERI_BASE + INTPRI_OFS)
#define INTPRI_SIZE			(0x1000)

#endif /* ASPACE_H */
