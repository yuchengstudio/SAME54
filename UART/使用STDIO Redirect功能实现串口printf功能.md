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
prinft()函数格式说明
```
% - 0 m.n l或h 格式字符
　　下面对组成格式说明的各项加以说明：
　　①%:表示格式说明的起始符号，不可缺少。
　　②-:有-表示左对齐输出，如省略表示右对齐输出。
　　③0:有0表示指定空位填0,如省略表示指定空位不填。
　　④m.n:m指域宽，即对应的输出项在输出设备上所占的字符数。N指精度。用于说明输出的实型数的小数位数。对数值型的来说，未指定n时，隐含的精度为n=6位。
　　⑤l或h:l对整型指long型，对实型指double型。h用于将整型的格式字符修正为short型。
　　---------------------------------------
　　格式字符
　　格式字符用以指定输出项的数据类型和输出格式。
　　①d格式：用来输出十进制整数。有以下几种用法：
　　%d:按整型数据的实际长度输出。
　　%md:m为指定的输出字段的宽度。如果数据的位数小于m,则左端补以空格，若大于m,则按实际位数输出。
　　%ld:输出长整型数据。
　　②o格式：以无符号八进制形式输出整数。对长整型可以用"%lo"格式输出。同样也可以指定字段宽度用"%mo"格式输出。
　　例：
　　main（）
　　{ int a = -1;
　　printf（"%d, %o", a, a）；
　　}
　　运行结果：-1,177777
　　程序解析：-1在内存单元中（以补码形式存放）为（1111111111111111）2,转换为八进制数为（177777）8.
　　③x格式：以无符号十六进制形式输出整数。对长整型可以用"%lx"格式输出。同样也可以指定字段宽度用"%mx"格式输出。
　　④u格式：以无符号十进制形式输出整数。对长整型可以用"%lu"格式输出。同样也可以指定字段宽度用"%mu"格式输出。
　　⑤c格式：输出一个字符。
　　⑥s格式：用来输出一个串。有几中用法
　　%s:例如：printf（"%s", "CHINA"）输出"CHINA"字符串（不包括双引号）。
　　%ms:输出的字符串占m列，如字符串本身长度大于m,则突破获m的限制，将字符串全部输出。若串长小于m,则左补空格。
　　%-ms:如果串长小于m,则在m列范围内，字符串向左靠，右补空格。
　　%m.ns:输出占m列，但只取字符串中左端n个字符。这n个字符输出在m列的右侧，左补空格，注意：如果n未指定，默认为0.
　　%-m.ns:其中m、n含义同上，n个字符输出在m列范围的左侧，右补空格。如果n>m,则自动取n值，即保证n个字符正常输出，注意：如果n未指定，默认为0.
　　如果是sprintf（desc, "%m.ns", sour）； 如果desc空间够的话，会在%m.ns 串 的结尾自动补null字符，不同于strncpy.
　　例如 :sprintf（desc, "%.3s", "123456"）； desc如果空间>=4字节的话，第4个字节将是null字符。
　　⑦f格式：用来输出实数（包括单、双精度），以小数形式输出。有以下几种用法：
　　%f:不指定宽度，整数部分全部输出并输出6位小数。
　　%m.nf:输出共占m列，其中有n位小数，如数值宽度小于m左端补空格。
　　%-m.nf:输出共占n列，其中有n位小数，如数值宽度小于m右端补空格。
　　⑧e格式：以指数形式输出实数。可用以下形式：
　　%e:数字部分（又称尾数）输出6位小数，指数部分占5位或4位。
　　%m.ne和%-m.ne:m、n和"-"字符含义与前相同。此处n指数据的数字部分的小数位数，m表示整个输出数据所占的宽度。
　　⑨g格式：自动选f格式或e格式中较短的一种输出，且不输出无意义的零。
　　---------------------------------------
　　关于printf函数的进一步说明：
　　如果想输出字符"%",则应该在"格式控制"字符串中用连续两个%表示，如：
　　printf（"%f%%", 1.0/3）；
　　输出0.333333%.
　　---------------------------------------
　　对于单精度数，使用%f格式符输出时，仅前7位是有效数字，小数6位。
　　对于双精度数，使用%lf格式符输出时，前16位是有效数字，小数6位。
　　------------------------------------------------------------------
　　printf（）函数是格式输出函数，请求printf（）打印变量的指令取决与变量的类型。例如，在打印整数是使用%d符号，在打印字符是 用%c 符号。这些符号被称为转换说明。因为它们指定了如何不数据转换成可显示的形式。下列列出的是ANSI C标准printf（）提供的各种转换说明。
　　转换说明及作为结果的打印输出%a 浮点数、十六进制数字和p-记数法（C99）
　　%A 浮点数、十六进制数字和p-记法（C99）
　　%c 一个字符
　　%d 有符号十进制整数
　　%e 浮点数、e-记数法
　　%E 浮点数、E-记数法
　　%f 浮点数、十进制记数法
　　%g 根据数值不同自动选择%f或%e.
　　%G 根据数值不同自动选择%f或%e.
　　%i 有符号十进制数（与%d相同）
　　%o 无符号八进制整数
　　%p 指针
　　%s 字符串
　　%u 无符号十进制整数
　　%x 使用十六进制数字0f的无符号十六进制整数
　　%X 使用十六进制数字0f的无符号十六进制整数
　　%% 打印一个百分号
　　//还有一个特殊的格式%*.* ,这两个星号的值分别由第二个和第三个参数的值指定 printf（"%.*s \n", 8, "abcdefgggggg"）；
　　printf（"%*.*f \n", 3,3, 1.25456f）；使用printf （）函数 printf（）的基本形式： printf（"格式控制字符串",变量列表）；#include<cstdio>int main（）
　　{
　　//for int
　　int i=30122121;
　　long i2=309095024l;
　　short i3=30;
　　unsigned i4=2123453; printf（"%d,%o,%x,%X,%ld,%hd,%u\n",i,i,i,i,i2,i3,i4）；//如果是：%l,%h,则输不出结果
　　printf（"%d,%ld\n",i,i2）；//试验不出%ld和%d之间的差别，因为long是4bytes www.yztrans.com 
　　printf（"%hd,%hd\n\n\n",i,i3）；//试验了%hd和%d之间的差别，因为short是2bytes
　　//for string and char
　　char ch1='d';
　　unsigned char ch2=160;
　　char *str="Hello everyone!";
　　printf（"%c,%u,%s\n\n\n",ch1,ch2,str）；//unsigned char超过128的没有字符对应
　　//for float and double,unsigned and signed can not be used with double and float
　　float fl=2.566545445F;//or 2.566545445f
　　double dl=265.5651445; www.jamo123.com 
　　long double dl2=2.5654441454;
　　//%g没有e格式，默认6位包括小数点前面的数，
　　//%f没有e格式，默认6位仅只小数点后面包含6位
　　//%e采用e格式，默认6位为转化后的小数点后面的6位
　　printf（"%f,%e,%g,%.7f\n",fl,dl,dl,dl）；
　　printf（"%f,%E,%G,%f\n",fl,dl,dl,dl）；//%F is wrong
　　printf（"%.8f,%.10e\n",fl,dl）；
　　printf（"%.8e,%.10f\n\n\n",fl,dl）；
　　//for point
　　int *iP=&i;
　　char *iP1=new char;
　　void *iP2;//dangerous!
　　printf（"%p,%p,%p\n\n\n",iP,iP1,iP2）；
　　//其他知识：负号，表示左对齐（默认是右对齐）；%6.3,6表示宽度，3表示精度
　　char *s="Hello world!";
　　printf（":%s: \n:%10s: \n:%.10s: \n:%-10s: \n:%.15s: \n:%-15s: \n:%15.10s: \n:%-15.10s:\n\n\n",
　　s,s,s,s,s,s,s,s）； double ddd=563.908556444;
　　printf（":%g: \n:%10g: \n:%.10g: \n:%-10g: \n:%.15g: \n:%-15g: \n:%15.10g: \n:%-15.10g:\n\n\n",
　　ddd,ddd,ddd,ddd,ddd,ddd,ddd,ddd）；
　　//还有一个特殊的格式%*.* ,这两个星号的值分别由第二个和第三个参数的值指定 printf（"%.*s \n", 8, "abcdefgggggg"）；
　　printf（"%*.*f \n", 3,3, 1.25456f）； return 0;
　　}
  ```


