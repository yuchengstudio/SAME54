 //熔丝位读取命令
 //2018-12-6
 //作者：daodao6
//此处熔丝位根据自己的设定自行更改 
const uint32_t samd20_modified_fusebits[2] = {0xFE9A9239, 0xAEE0FFB1};
 

 static void read_fuse_bits(uint32_t *data)
 {
    uint32_t data[2];
 while (!(NVMCTRL->STATUS.reg & NVMCTRL_STATUS_READY));
	 data[0] = *((uint32_t *)NVMCTRL_USER);
	 data[1] = *(((uint32_t *)NVMCTRL_USER) + 1);
 }
 
 void program_fuse_bits(void)
{
	uint32_t samd51_new_fusebits[2]={0};
	/* Save current value of reserved fusebits */
	samd51_new_fusebits[0] = samd51_modified_fusebits[0];
	samd51_new_fusebits[1] = samd51_modified_fusebits[1];
	
	/* 读取当前是不是处于被写保护状态 */
	if (NVMCTRL->CTRLB.reg & NVMCTRL_CTRLB_CMD_SSB) {
		return;
	}
	/* Disable Cache */
	NVMCTRL->CTRLA.reg = NVMCTRL_CTRLA_CACHEDIS0_Pos| NVMCTRL_CTRLA_CACHEDIS1_Pos;
	/* Clear error flags */
	NVMCTRL->INTENCLR.reg |= NVMCTRL_INTENCLR_MASK;
	/* Set address, command will be issued elsewhere */
	NVMCTRL->ADDR.reg = NVMCTRL_USER;
	/* Erase the user page */
	NVMCTRL->CTRLB.reg = NVMCTRL_CTRLB_CMD_EP |
	NVMCTRL_CTRLB_CMDEX_KEY;
	/* Wait for NVM command to complete */
	while (!(NVMCTRL->STATUS.reg & NVMCTRL_STATUS_READY));
	/* Clear error flags */
	NVMCTRL->INTENCLR.reg |= NVMCTRL_INTENCLR_MASK;
	/* Set address, command will be issued elsewhere */
	NVMCTRL->ADDR.reg = NVMCTRL_USER;
	/* Erase the page buffer before buffering new data */
	NVMCTRL->CTRLB.reg = NVMCTRL_CTRLB_CMD_PBC |
	NVMCTRL_CTRLB_CMDEX_KEY;
	/* Wait for NVM command to complete */
	while (!(NVMCTRL->STATUS.reg & NVMCTRL_STATUS_READY));
	/* Clear error flags */
	NVMCTRL->INTENCLR.reg |= NVMCTRL_INTENCLR_MASK;
	/* Set address, command will be issued elsewhere */
	NVMCTRL->ADDR.reg = NVMCTRL_USER;
		/*注意用户页写入模式 */
	*((uint32_t *)NVMCTRL_USER) = samd51_new_fusebits[0];
	*(((uint32_t *)NVMCTRL_USER) + 1) = samd51_new_fusebits[1];
	NVMCTRL->CTRLB.reg = NVMCTRL_CTRLB_CMD_WQW|NVMCTRL_CTRLB_CMDEX_KEY;

    NVIC_SystemReset();//防止程序出错  考虑这里加系统复位
}
void example()
{
	uint32_t samd51_fusebits[2];
	 read_fuse_bits(samd51_fusebits);
    if((samd51_fusebits[0] != samd51_modified_fusebits[0])&&(samd51_fusebits[1]!=samd51_modified_fusebits[1]))
	{
        program_fuse_bits();}
	
}