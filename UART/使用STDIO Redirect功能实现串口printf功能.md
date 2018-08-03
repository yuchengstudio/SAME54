# 目录
# 概述
## 1.参考
如下图所示，可以在start中调用STDIO Redirect功能
![images](https://github.com/yuchengstudio/SAME54/blob/master/UART/reference/STDIO%20Redirect_002.jpg)

参考工程如下
https://github.com/yuchengstudio/SAME54/blob/master/UART/E54%20stdiotest.rar

```
#include "math.h"
#include "atmel_start.h"
#include <hal_gpio.h>
#include <hal_delay.h>

signed long  testslong = 0x8000;
unsigned long  testlong = 0x80000;
unsigned long long  testlonglong = 1276295748;
signed long  testlongaa = 1276295748;
unsigned long long power222a = pow(2.0, 27);

int main(void)
{
	atmel_start_init();

	
	while (true) {
		delay_ms(2000);
		
		printf("testlongaa = %ld \n\r",  testlongaa);
		printf("testlonglong = %ld \n\r",  testlonglong);
		printf("testslong = %ld testlong = %ld  testlonglong = %ld \n\r",  testslong, testlong, testlonglong);
		
		printf("power222a = %ld power222a = 0x%x\n\r",  power222a,  power222a);
		
		printf("testslong = %ld testlong = %ld  testslong = 0x%x testlong = 0x%x \n\r",  testslong, testlong, testslong,testlong);
		
		gpio_toggle_pin_level(LED0);
	}
}

```


