#include "FreeRTOS.h"
#include "task.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)xTask;
    (void)pcTaskName;

    taskDISABLE_INTERRUPTS();
    for (;;);
}

/* Optional: malloc fail hook */
void vApplicationMallocFailedHook(void)
{
    taskDISABLE_INTERRUPTS();
    for (;;);
}

/* Optional: idle hook (nếu cần) */
void vApplicationIdleHook(void)
{
    /* để trống cũng được */
}