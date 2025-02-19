// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include <task.h>
// #include <queue.h>

// QueueHandle_t xQueue;

// void task1(void *pvParameters);
// void task2(void *pvParameters);

// void setup()
// {
//   Serial.begin(9600);
//   xTaskCreate(task1, "Task1", 100, NULL, 2, NULL);
//   xTaskCreate(task2, "Task2", 100, NULL, 1, NULL);
//   vTaskStartScheduler();
// }

// void loop() {}

// /**
//  * Task 1
//  * @param pvParameters void pointer
//  *
//  * Task 1 có nhiệm vụ khởi tạo queue và gửi dữ liệu cho Task 2
//  */
// void task1(void *pvParameters)
// {
//   Serial.println("Task 1 is running");
//   // khởi tạo queue nếu chưa tồn tại
//   if (xQueue == NULL)
//   {
//     xQueue = xQueueCreate(1, sizeof(char *));
//   }

//   while (1)
//   {
    
//     // char *message1 = (char *)pvPortMalloc(100 * sizeof(char));
//     // sprintf(message1, "Hello from Task 1 first time");
//     // xQueueSend(xQueue, &message1, 0);

//     // char *message2 = (char *)pvPortMalloc(100 * sizeof(char));
//     // sprintf(message2, "Hello from Task 1 second time");
//     // xQueueSend(xQueue, &message2, 0);

//     char *message1 = (char *)pvPortMalloc(100 * sizeof(char));
//     sprintf(message1, "Hello from Task 1 first time");
//     xQueueSend(xQueue, &message1, 0);
//     vPortFree(message1);

//     char *message2 = (char *)pvPortMalloc(100 * sizeof(char));
//     sprintf(message2, "Hello from Task 1 second time");
//     xQueueOverwrite(xQueue, &message2);

//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }

// /**
//  * Task 2
//  * @param pvParameters void pointer
//  *
//  * Task 2 có nhiệm vụ nhận dữ liệu từ Task 1 và in ra Serial Monitor
//  */
// void task2(void *pvParameters)
// {
//   Serial.println("Task 2 is running");
//   while (1)
//   {
//     if (uxQueueMessagesWaiting(xQueue) > 0)
//     {
//       char *message;
//       xQueueReceive(xQueue, &message, 0);
//       Serial.println(message);
//       vPortFree(message);
//     }
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }