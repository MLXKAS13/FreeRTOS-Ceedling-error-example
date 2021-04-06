#include "../../../test/support/FreeRTOS.h"






struct QueueDefinition;

typedef struct QueueDefinition * QueueHandle_t;



typedef struct xSTATIC_QUEUE

{

 void *pvDummy1[ 3 ];



 union

 {

  void *pvDummy2;

  UBaseType_t uxDummy2;

 } u;



 StaticList_t xDummy3[ 2 ];

 UBaseType_t uxDummy4[ 3 ];

 uint8_t ucDummy5[ 2 ];

} StaticQueue_t;



QueueHandle_t xQueueGenericCreateStatic( const UBaseType_t uxQueueLength, const UBaseType_t uxItemSize, uint8_t *pucQueueStorage, StaticQueue_t *pxStaticQueue, const uint8_t ucQueueType );
