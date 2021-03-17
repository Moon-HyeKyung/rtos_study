#include "stdint.h"
#include "HalUart.h"

#include "stdio.h"
#include "stdbool.h"

#include "HalTimer.h"
#include "stdlib.h"

static void Hw_init(void);
static void Timer_test(void); // Timer method

void main(void)
{
	Hw_init();

	uint32_t i = 100;
	while(i--)
	{
		Hal_uart_put_char('N');
	}
	Hal_uart_put_char('\n');

	putstr("Hello World!\n");
	//
	// i = 100;
	// while(i--)
	// {
	// 	uint8_t ch = Hal_uart_get_char();
	// 	Hal_uart_put_char(ch);
	// }
	Timer_test(); // Timer 함수 호출

}
static void Hw_init(void)
{
    Hal_interrupt_init();
    Hal_uart_init();
		Hal_timer_init();
}

// Timer 정적함수 정의
static void Timer_test(void)
{
    while(true)
    {
        putstr("tic\n");
        delay(1000);
    }
}
