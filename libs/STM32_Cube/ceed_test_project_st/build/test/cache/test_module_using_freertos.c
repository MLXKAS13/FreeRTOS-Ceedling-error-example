#include "../../../app/inc/module_using_freertos.h"
#include "build/test/mocks/mock_queue.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"






module_handle_t module;

static uint32_t module_queue_data[10];



void test_init()

{

    module_init(module_queue_data, &module);

}
