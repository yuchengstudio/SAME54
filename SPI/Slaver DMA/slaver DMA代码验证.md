# 概述
## 本文目的
   这篇文档主要目的是想实现SAMD51 MCU的Slaver SPI 的DMA通信，在作者写这篇文档时，“START”还没有支持这款芯片的slaver SPI DMA方式的通信，但能找到基于SAML21的一个例程，基于此，做相应代码的移植修改工作能实现Slaver SPI DMA的功能。

参考代码：
https://github.com/yuchengstudio/SAME54/blob/master/SPI/Slaver%20DMA/SAML21_SPI_Slave_DMA0%20(1).7z


## 使用START产生最基本的SPI通信工程，用以验证SPI模块配置正确
 | 步骤 | 链接 | 说明 |
 | --- | ----- | ----- | 
 | 1 | https://github.com/yuchengstudio/SAME54/blob/master/SPI/Slaver%20DMA/reference/SAMD51P20A_SPI_SLAVER_DMA.rar |  | 
 | tips | <br/>1.测试功能Master spi syn 模式发数据，Slaver spi asyn读数据 <br/>2.测试功能：Slaver spi asyn发数据；Master spi syn 读数据， <br/>3.xxx | | 

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
