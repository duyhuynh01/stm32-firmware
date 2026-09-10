#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* ================= CPU ================= */
#define configCPU_CLOCK_HZ              (72000000UL)
#define configTICK_RATE_HZ              ((TickType_t)1000)

/* Tick type (FIX CHÍNH LỖI BẠN GẶP) */
#define configTICK_TYPE_WIDTH_IN_BITS   TICK_TYPE_WIDTH_32_BITS

/* ================= Heap ================= */
#define configTOTAL_HEAP_SIZE           ((size_t)(8 * 1024))
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configSUPPORT_STATIC_ALLOCATION   0

/* ================= Task ================= */
#define configMAX_PRIORITIES            5
#define configMINIMAL_STACK_SIZE        128
#define configMAX_TASK_NAME_LEN         16

#define configUSE_PREEMPTION            1
#define configUSE_TIME_SLICING          1
#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0

/* ================= Mutex / Semaphores ================= */
#define configUSE_MUTEXES               1
#define configUSE_COUNTING_SEMAPHORES   1

/* ================= Interrupt priority ================= */
#define configPRIO_BITS                 4

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY          15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY     5

#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

#define configKERNEL_INTERRUPT_PRIORITY \
    (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

/* ================= API includes ================= */
#define INCLUDE_vTaskDelay              1
#define INCLUDE_vTaskDelete             1
#define INCLUDE_vTaskSuspend            1

/* ================= Debug ================= */
#define configCHECK_FOR_STACK_OVERFLOW  2
#define configASSERT(x) if((x)==0) { taskDISABLE_INTERRUPTS(); for(;;); }

#define vPortSVCHandler     SVC_Handler
#define xPortPendSVHandler  PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */