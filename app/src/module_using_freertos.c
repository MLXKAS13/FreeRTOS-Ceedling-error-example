#include "module_using_freertos.h"

void module_init(uint32_t* queue_data, module_handle_t *handle)
{
           handle->queue = xQueueCreateStatic(MODULE_QUEUE_DEPTH,
                                           sizeof(uint32_t),
                                           (uint8_t*)queue_data,
                                           &handle->queue_buffer); 
}

void module_push(uint32_t value, module_handle_t* handle)
{

}

uint32_t module_pop(module_handle_t* handle)
{
    return 0;
}