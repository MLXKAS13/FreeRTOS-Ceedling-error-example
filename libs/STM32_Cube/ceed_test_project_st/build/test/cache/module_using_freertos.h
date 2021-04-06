#include "../../../test/support/queue.h"
#include "../../../test/support/FreeRTOS.h"














typedef struct

{

    QueueHandle_t queue;

    StaticQueue_t queue_buffer;

} module_handle_t;



void module_init(uint32_t* queue_data, module_handle_t *handle);

void module_push(uint32_t value, module_handle_t* handle);

uint32_t module_pop(module_handle_t* handle);
