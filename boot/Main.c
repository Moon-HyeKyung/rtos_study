#include "stdint.h"
#include "HalUart.h"

#include "stdio.h"
#include "stdbool.h"

#include "HalTimer.h"
#include "stdlib.h"

#include "kernel.h"
#include "task.h"

static void Hw_init(void);

static void Timer_test(void); // Timer method

static void Kernel_init(void); // kernel init

void User_task0(void);
void User_task1(void);
void User_task2(void);

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

	// i = 100;
	// while(i--)
	// {
	// 	uint8_t ch = Hal_uart_get_char();
	// 	Hal_uart_put_char(ch);
	// }

	Kernel_init();
	//Timer_test(); // Timer 함수 호출

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

static void Kernel_init(void)
{
    uint32_t taskId;

    Kernel_task_init();

    taskId = Kernel_task_create(User_task0);
    if (NOT_ENOUGH_TASK_NUM == taskId)
    {
        putstr("Task0 creation fail\n");
    }

    taskId = Kernel_task_create(User_task1);
    if (NOT_ENOUGH_TASK_NUM == taskId)
    {
        putstr("Task1 creation fail\n");
    }

    taskId = Kernel_task_create(User_task2);
    if (NOT_ENOUGH_TASK_NUM == taskId)
    {
        putstr("Task2 creation fail\n");
    }

		 Kernel_task_start();
}

//////////////// TASKS ///////////////////////////
void User_task0(void)
{
    uint32_t local = 0;

    while(true)
    {

    putstr("User Task #0\n");
    Kernel_yield();

    }
}

void User_task1(void)
{
    uint32_t local = 0;

    while(true)
    {

    putstr("User Task #1\n");
    Kernel_yield();

    }
}

void User_task2(void)
{
    uint32_t local = 0;

    while(true)
    {

    putstr("User Task #2\n");
    Kernel_yield();

    }
}
