# 概述
## 本文目的
<br/>1 reference
<br/>2 00262810
<br/>3 这篇文档主要目的是想实现SAMD51 MCU的Slaver SPI 的DMA通信，在作者写这篇文档时，“START”还没有支持这款芯片的slaver SPI DMA方式的通信，但能找到基于SAML21的一个例程，基于此，做相应代码的移植修改工作能实现Slaver SPI DMA的功能。

参考代码：
https://github.com/yuchengstudio/SAME54/blob/master/SPI/Slaver%20DMA/SAML21_SPI_Slave_DMA0%20(1).7z


## 使用START产生最基本的SPI通信工程，用以验证SPI模块配置正确
 | 步骤 | 链接 | 说明 |
 | --- | ----- | ----- | 
 | 1 | https://github.com/yuchengstudio/SAME54/blob/master/SPI/Slaver%20DMA/reference/SAMD51P20A_SPI_SLAVER_DMA.rar |  | 
 | tips1 | <br/>1.测试功能Master spi syn 模式发数据，Slaver spi asyn读数据 <br/>2.测试功能：Slaver spi asyn发数据；Master spi syn 读数据， <br/>3.硬件连接说明：<br/>a.SCK PB27(master) <--> PC05(slaver);<br/>b.MISO PB28(master) <-->PC04(slaver); <br/>c.MOSI PB29(master) <--> PC07(slaver);   <br/>c. SS PB26(master) <--> PC06(slaver)| | 
 | tips2 | ![image](https://github.com/yuchengstudio/SAME54/blob/master/SPI/Slaver%20DMA/reference/SPI_DMA_001.jpg) |  | 
 | tips3 | 在相应的断点处查看相应的数据buf是否接收到正确数据|  | 
 | 2| 配置SPI_0为Master_DMA模式，验证通信结果|  | 
 |  | https://github.com/yuchengstudio/SAME54/blob/master/SPI/Slaver%20DMA/reference/SAMD51P20A_SPI_SLAVER_DMA(1).rar |  | 
 | tips | <br/>1 请使用解压包下的 SAMD51P20A_SPI_SLAVER_DMA(1)\.atmel-start-backup 目录下的SAMD51P20A_SPI_SLAVER_DMA(1)_7工程。|  | 
 | 3 | 配置SPI_1为Slaver_DMA模式，验证通信结果|  |
 | note | 在作者写这篇文字的时候，SAMD51还不能通过START来配置slaver spi的DMA模式，所以需要自己配置，如下步骤就是如何手动配置的过程|  | 
 | 3.1 |  https://github.com/yuchengstudio/SAME54/blob/master/SPI/Slaver%20DMA/reference/SAMD51P20A_SPI_SLAVER_DMA(1).rar| SPI_slaver_DMA移植成功 | 
 | tips | <br/>1 请使用解压包下的 SAMD51P20A_SPI_SLAVER_DMA(1)\.atmel-start-backup 目录下的SAMD51P20A_SPI_SLAVER_DMA(1)_10工程。|  | 
 
 ## 在“SAMD51P20A_SPI_SLAVER_DMA.rar”工程基础上使用START配置Master SPI DMA通信
 

## 重要代码修改分析
```
#include <atmel_start.h>

/* Buffer length to transfer/receive */
#define		BUFFER_LEN						(12)

#define CONF_SERCOM_2_RECEIVE_DMA_CHANNEL	1
static uint8_t string[BUFFER_LEN];
volatile uint8_t receiveComplete  = 0;
volatile uint8_t received_data_len  = 0;

/* callbacks */
static void dma_transfer_done_rx(struct _dma_resource *const resource)
{
	receiveComplete = true;
}

static void dma_error_rx(struct _dma_resource *const resource)
{
	/* write error handling code here */
}

/* register callbacks */
/*
void register_dma_rx_callback(void)
{
	struct _dma_resource *resource_rx;
	_dma_get_channel_resource(&resource_rx, CONF_SERCOM_2_RECEIVE_DMA_CHANNEL);
	resource_rx->dma_cb.transfer_done = dma_transfer_done_rx;
	resource_rx->dma_cb.error         = dma_error_rx;
}
*/


/* SERCOM RX channel configuration */
void Configure_Channel_rx()
{
	//_dma_set_source_address(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, (uint32_t) & (((SercomSpi *)(SPI_1.dev.prvt))->DATA.reg));
	//_dma_set_destination_address(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, (uint32_t *)string);
	//_dma_set_data_amount(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, (uint32_t)BUFFER_LEN);
	//_dma_enable_transaction(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, false);

	/* callback */
	//register_dma_rx_callback();

	/* Enable DMA transfer complete interrupt */
	//_dma_set_irq_state(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, DMA_TRANSFER_COMPLETE_CB, true);
	
	asm("nop");
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	//Configure_Channel_rx();
	//spi_s_sync_enable(&SPI_1);
	SPI_0_example();
	asm("nop");
	/* Replace with your application code */
	while (1) {
	}
}

```


```
Please find below the example for SPI DMA Slave. We are going to add this in future START release.

Workaround:
Configuration in START
configure SPI module in HAL:Driver:SPI_Slave_Sync driver and configure one GPIO pin as a input Interrupt using start. Enable DMA and do required DMA configuration for transferring data from SPI slave data register to memory

Connections on Hardware
connect Master Slave select(SS) PIN to Slave Slave select(SS) pin and input interrupt GPIO. Slave select pin acts as interrupt to the MCU to understand the data transfer is completed by detection Low to High transition on SS pin if SS is Active low.

Source Code
#include <atmel_start.h>
#include <hpl_dma.h>
#include "driver_examples.h"

#define CONF_SERCOM_2_RECEIVE_DMA_CHANNEL 1
/* Buffer length to transfer/receive */
#define BUFFER_LEN (12)

extern DmacDescriptor _descriptor_section[DMAC_CH_NUM] ;
extern DmacDescriptor _write_back_section[DMAC_CH_NUM] ;

volatile uint8_t receiveComplete = 0;
volatile uint8_t received_data_len = 0;

static uint8_t string[BUFFER_LEN];

/* callbacks */
static void dma_transfer_done_rx(struct _dma_resource *const resource)
{ receiveComplete = true; }
static void dma_error_rx(struct _dma_resource *const resource)
{ /* write error handling code here */ }
static void button_on_PB07_pressed(void)
{ received_data_len = (_descriptor_section[CONF_SERCOM_2_RECEIVE_DMA_CHANNEL].BTCNT.reg - _write_back_section[CONF_SERCOM_2_RECEIVE_DMA_CHANNEL].BTCNT.reg); }
/* register callbacks */
void register_dma_rx_callback(void)
{ struct _dma_resource *resource_rx; _dma_get_channel_resource(&resource_rx, CONF_SERCOM_2_RECEIVE_DMA_CHANNEL); resource_rx->dma_cb.transfer_done = dma_transfer_done_rx; resource_rx->dma_cb.error = dma_error_rx; }
/* SERCOM RX channel configuration */
void Configure_Channel_rx()
{ _dma_set_source_address(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, (uint32_t) & (((SercomSpi *)(SPI_1.dev.prvt))->DATA.reg)); _dma_set_destination_address(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, (uint32_t *)string); _dma_set_data_amount(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, (uint32_t)BUFFER_LEN); _dma_enable_transaction(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, false); /* callback */ register_dma_rx_callback(); /* Enable DMA transfer complete interrupt */ _dma_set_irq_state(CONF_SERCOM_2_RECEIVE_DMA_CHANNEL, DMA_TRANSFER_COMPLETE_CB, true); }
int main(void)
{
/* Initializes MCU, drivers and middleware */
atmel_start_init();
ext_irq_register(PIN_PB07, button_on_PB07_pressed);
Configure_Channel_rx();
spi_s_sync_enable(&SPI_1);

/* Replace with your application code */
while (1) {
}
}

The Start Project is attached here.
This project contain 2 SPI one is in master mode(SERCOM0) and other is in slave mode(SERCOM2)

Master SPI : driver : HAL:Driver:SPI_Master_DMA : SERCOM0
Slave SPI : driver :HAL:Driver:SPI_Slave_Sync : SERCOM2

External interrupt driver for sensing Slave select pin to understand the data transfer is finished from master SPI.

Please ask the customer to use this.

```
