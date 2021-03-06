#include <stdio.h>
#include <stdlib.h>
/*#############################################
##
##Create Date:2015-11-18
##Author:Norman
##Description: atoi 
##
##
###############################################

明确问题:
	atoi()函数功能:将字符串转换成整型数

分析问题:
		1.atoi 扫描参数nptr字符串,跳过前面的空格字符
		2.遇到数字或正负才开始做转换
		3.非数字或字符串时(\0)才结束转化,并将结束返回(返回转换一的整型数)

归纳:
	1.空格开头忽略
	2.非数字为0
	3.-负数显示负号
	4.遇到'\0'结束

总结:
    1.判断指针是否为空
    2.判断前面字符是否为空
    3.判断字符是否是-号开头
    4.判断字符前是否有-或+
    5.循环找出非零小于9的整数

*/

int my_atoi(const char* str) {
	int IsInter =1;
    int RetInt = 0;


    if(str == NULL) {
        return -1;
    }

    if(*str == ' ') {
        *str++;
    }

    if(*str == '-') {
        IsInter = -1;
    }

    if(*str == '-' || *str == '+') {
        *str++;
    }

    while(*str >= '0' && *str <= '9') {
        RetInt = RetInt*10+*str-'0';
        *str++;
    }
    RetInt = IsInter * RetInt;

	return RetInt;
}


int main(){
	char str[] = "A";
	char str1[] = "1234ab";				//数字
	char str2[] = "abc123";				//非数字
	char str3[] = "-123sa";				//负数
	char str4[] = " 356ab";				//前面空格
	char str5[] = "2'\0'8";				//遇到\0
	printf("After C Libary atoi str=%d\n",atoi(str));
	printf("After C Libary atoi str1=%d\n",atoi(str1));
	printf("After C Libary atoi str2=%d\n",atoi(str2));
	printf("After C Libary atoi str3=%d\n",atoi(str3));
	printf("After C Libary atoi str4=%d\n",atoi(str4));
	printf("After C Libary atoi str5=%d\n",atoi(str5));

	printf("Before atoi:%s\n",str3);

	printf("After atoi:%d\n",my_atoi(str3));
	return 0;
}
