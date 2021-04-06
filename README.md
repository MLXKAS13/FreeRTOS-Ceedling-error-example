## FreeRTOS + Ceedling error example project
This demonstrates the issue of trying to mock FreeRTOS functions and functionality included in the Middlewares directory (things like queue, task, etc.).

### Requirements for building:
* arm-none-eabi-gcc toolchain (can be install from any system package manager)

### Requirements for testing:
* ceedling

### Description
The problem test in question is test_module_using_freertos.c. The Makefile, project, and ceedling config is in libs/STM32_Cube/ceed_test_project_st/. Running `ceedling` from that directoy will currently give you the following output:

```
Test 'test_module_using_freertos.c'
-----------------------------------
Generating runner for test_module_using_freertos.c...
Compiling test_module_using_freertos_runner.c...
Compiling test_module_using_freertos.c...
Linking test_module_using_freertos.out...
/usr/bin/ld: build/test/out/c/module_using_freertos.o: in function `module_init':
/fwdev/ceed_test_project/libs/STM32_Cube/ceed_test_project_st/../../../app/src/module_using_freertos.c:5: undefined reference to `xQueueCreateStatic'
collect2: error: ld returned 1 exit status
ERROR: Shell command failed.
> Shell executed command:
'gcc "build/test/out/c/test_module_using_freertos_runner.o" "build/test/out/c/test_module_using_freertos.o" "build/test/out/c/mock_queue.o" "build/test/out/c/unity.o" "build/test/out/c/module_using_freertos.o" "build/test/out/c/cmock.o" -o "build/test/out/test_module_using_freertos.out"'
> And exited with status: [1].
```

The `xQueueCreateStatic` function is used in `module_init()`, which is the function I'm currently trying to test. I have defined the `xQueueCreateStatic` function header in test/support/queue.h. You can also see the rest of the FreeRTOS headers I've stubbed out there to compile the code with ceedling. 

My first question is: do I have to go through and redefine every FreeRTOS function (and _those_ function's dependencies, and so on) I use in my code under test? The 5 files in test/support are the full dependency chain of typedefs, enums, and functions, as they exist in the actual FreeRTOS code. Those 5 files are only for the use of this _single_ queue function. Can you imagine how deep that will go for using FreeRTOS in a full application with many different RTOS-defined types and functions?

Second: if the above is true, am I then still expected to go through and manually create implementation files to implement function stubs for every since function in the support headers? Since I'm getting the above error, the linker can't find the `xQueueCreateStatic` symbol implemented anywhere. Is this not the point of the mocking framework? I would expect that by including mock_module_using_freertos.h I would be free from this. I can see the implementation that's generated in the mock_queue.c file, it's just not exposed by the mock_queue.h file. Is this a bug or is this somehow intended?
