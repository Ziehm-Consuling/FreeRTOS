/*H**********************************************************************
 * FILENAME :        main_speedTest.cpp             DESIGN REF: FMCM00
 *                   (rename to main.cpp to test single file)
 * DESCRIPTION :
 *       Speed test for the cores of the ESP32. Testing multithreading on ESP32.
 *
 * PUBLIC FUNCTIONS :
 *         Core_0:
 *              void    create_artificial_Load()
 *              int     myFunction(int, int)
 *         Core_1:
 *              task_0.h ->
 *              task_1.h
 * NOTES :
 *       The naming of the prefixes of the variables and functions results from the variable type or
 *       the variable type of the return value.
 *       "c" stands for "char", an "s" for "short",
 *       "v" for "void", a "u" for "unsigned" and
 *       "x" for all non-standard types
 *
 *       Copyright Tjark Ziehm 2024
 *
 * AUTHOR :    Tjark Ziehm        START DATE :    20 April 2024
 *
 * CHANGES :
 *
 * Convention:   <major>.<minor>.<patch>
 * REF NO  VERSION DATE        WHO     DETAIL
 * F21/33  A.03.04 20April2024 TZ      add second Task for different Core
 *
 *H*/

#include <Arduino.h>
#include "clock.h"  // ESP32Time rtc;
#include "task_0.h" // Core X
#include "task_1.h" // Core X
#include "task_2.h" // Core X

TaskHandle_t Task0; /* define the taskhandler with name it */
TaskHandle_t Task1; /* define the taskhandler with name it */
TaskHandle_t Task2;

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  setTime();
  // Workload-Task
  xTaskCreatePinnedToCore(
      Task1_Code, /* Function name */
      "Task1",    /* Internal name */
      2000,       /* Stack size */
      NULL,       /* Task parameter */
      NULL,          /* priority for the Task */
      &Task1,     /* Task handler to keep track of the task by internal name */
      0           /* Core to pin to */
  );

  delay(500);

  // LED-Task
  xTaskCreatePinnedToCore(
      Task2_Code, /* Function name */
      "Task2",    /* Internal name */
      2000,       /* Stack size */
      NULL,       /* Task parameter */
      NULL,          /* priority for the Task */
      &Task2,     /* Task handler to keep track of the task by internal name */
      0           /* Core to pin to */
  );
}

void loop()
{
  // put your main code here, to run repeatedly:
  // if no code is avaible in loop, the stack size will still be defined on default
  // this can slow down the process, so create a minimum a no-real-task function delay(0);
  getTime();
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}
