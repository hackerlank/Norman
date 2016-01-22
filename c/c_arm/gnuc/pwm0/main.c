#include "include/gpio.h"

void delay(int n)
{
	while(n--);
}

int main()
{
    init_clock();
	init_led();
//    init_beep();
//    init_key();  //轮循初始化
//    init_interrupt_for_key();   //中断的方式

//    init_timer4();
//    init_interrupt_for_timer4();
    init_pwm0();        //初始化脉冲调制器
    init_interrupt_for_timer0();
    init_timer0();      //开启定时器

    led_off_all();
	int i;
	while(1){
	}
	return 0;
}
