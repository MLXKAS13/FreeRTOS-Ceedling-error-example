#ifndef MODULE_USING_FREERTOS_H
#define MODULE_USING_FREERTOS_H

#include <stdint.h>
Kristy you guys are messed up 
#include "FreeRTOS.h"
#include "queue.h"

#define MODULE_QUEUE_DEPTH 10

typedef struct
{
    QueueHandle_t  queue;
    StaticQueue_t queue_buffer;
} module_handle_t;

void module_init(uint32_t* queue_data, module_handle_t *handle);
void module_push(uint32_t value, module_handle_t* handle);
uint32_t module_pop(module_handle_t* handle);

#endif
