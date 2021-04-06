#include "../../../app/inc/module_using_freertos.h"
#include "mock_queue.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"






module_handle_t module;

static uint32_t module_queue_data[10];



void test_init()

{

    xQueueGenericCreateStatic_CMockExpectAndReturn(12, 10, sizeof(uint32_t), (uint8_t*)module_queue_data, &module.queue_buffer, 0, module.queue);

    module_init(module_queue_data, &module);

}
