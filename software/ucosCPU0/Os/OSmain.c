
#include <stdio.h>
#include "includes.h"
#include "../inc/sopc.h"
//#include "sys/alt_irq.h"
//#include "altera_avalon_timer_regs.h"
//#include "alt_types.h"
//#include <priv/alt_legacy_irq.h>

static void compInit(void);
unsigned long int * fifoWrData = (unsigned long int *)(FIFO0_IN_BASE);//写FIFO地址
unsigned long int * fifoRdData = (unsigned long int *)(FIFO0_OUT_BASE);//读FIFO地址

/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK    task1_stk[TASK_STACKSIZE];
OS_STK    task2_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      2
#define TASK2_PRIORITY      1

/* Prints "Hello World" and sleeps for three seconds */
void task1(void* pdata)
{
  int temp[2];
//  compInit();
//  compCtrl->data.bit.rst = 0;
////  OSTimeDly(50);
//  *fifoWrData = 0x9abcf407;
//  *fifoWrData = 0x12345678;
//  OSTimeDly(10);
//  temp[0] = *fifoRdData;
//  temp[1] = *fifoRdData;
    led->data = 1;
    while (1)
    { 
//    printf("Hello from task2\n");
        led->data = ~led->data;
//      compCtrl->data.bit.dataEn = 0;
//      compDataL->data = temp[0];
//      compDataH->data = temp[1];
//      compCtrl->data.bit.dataEn = 1;
        OSTimeDlyHMSM(0, 0, 1, 0);
  }
}
/* Prints "Hello World" and sleeps for three seconds */
void task2(void* pdata)
{
//    led->data = 1;
    while (1)
    { 
//    printf("Hello from task2\n");
//    led->data = ~led->data;
    OSTimeDlyHMSM(0, 0, 1, 0);
    }
}

//static void compInit(void)
//{
//    fifo->event = 0x3f;         //写event全位1，清空event
//    fifo->irqEn = 0x0;          //禁止所有中断
//    fifo->almostEmpty = ALMOSTEMPTY;    //设置将空阈值
//    fifo->almostFull = ALMOSRFULL;      //设置将满阈值
//    compCtrl->data.bit.order = 0;
//    compCtrl->data.bit.rst = 1;
//    compCtrl->data.bit.dataEn = 1;
////    OSTimeDly(10);
//}

/* The main function creates two task and starts multi-tasking */
int main(void)
{
  OSTaskCreateExt(task1,
                  NULL,
                  (void *)&task1_stk[TASK_STACKSIZE-1],
                  TASK1_PRIORITY,
                  TASK1_PRIORITY,
                  task1_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
              
               
  OSTaskCreateExt(task2,
                  NULL,
                  (void *)&task2_stk[TASK_STACKSIZE-1],
                  TASK2_PRIORITY,
                  TASK2_PRIORITY,
                  task2_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
  OSStart();
  return 0;
}
