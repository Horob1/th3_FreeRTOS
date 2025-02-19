// #include <Arduino.h>
// #include <Arduino_FreeRTOS.h>
// #include <task.h>
// #include <queue.h>

// QueueHandle_t xQueue;

// void task1(void *pvParameters);
// void task2(void *pvParameters);

// int count = 0;

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
//     xQueue = xQueueCreate(5, sizeof(char *));
//   }

//   while (1)
//   {
//     count++;
//     String messageStr = "Hello from Task 1: count = " + String(count);
//     char *message = new char[messageStr.length() + 1];
//     strcpy(message, messageStr.c_str());
//     xQueueSend(xQueue, &message, 0);

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
//       delete[] message; // Giải phóng bộ nhớ
//     }
//     else
//     {
//       Serial.println("Queue is empty");
//       vTaskDelay(3000 / portTICK_PERIOD_MS);
//     }
//   }
// }