#include <stdint.h>

#include "system.h"
#include "module_using_freertos.h"

module_handle_t module;
static uint32_t module_queue_data[MODULE_QUEUE_DEPTH];

void init()
{
    module_init(module_queue_data, &module);
}

void system_main()
{
    init();

    for (uint32_t i = 0; i < MODULE_QUEUE_DEPTH; i++)
    {
        module_push(i, &module);
    }

    uint32_t results[MODULE_QUEUE_DEPTH / 2];
    for (uint32_t i = 0; i < MODULE_QUEUE_DEPTH / 2; i++)
    {
        results[i] = module_pop(&module);
    }

    (void)results;
}