/*H**********************************************************************
* FILENAME :        main_speedTest.cpp             DESIGN REF: FMCM00
*                   (rename to main.cpp to test single file)
* DESCRIPTION :
*       Speed test for the cores of the ESP32. Testing multithreading on ESP32.
*
* PUBLIC FUNCTIONS :
*       void    create_artificial_Load()
*       int     myFunction(int, int)
*
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

#define LED_BUILTIN 2

TaskHandle_t Task1; /* define the taskhandler with name it */
TaskHandle_t Task2;

unsigned long loops1 = 2000;
unsigned long loops2 = 2000;
float t1;
int t2;
int t3;
unsigned long qq = 0;
unsigned long i, j;

// put function declarations here:
int myFunction(int, int);

// function declaration for calcualtion for speedtest:
/* function to make more heavy calculation for the task */
void create_artificial_Load()
{
  for (long i = 0; i < loops1; i++)
  {
    for (long j = 1; j < loops2; j++)
    {
      qq++;
      t1 = 5000.03 * i;
      t2 = 150 * 1234234 * i;
      t3 = j % 554;
    }
  }
}

void blink_LED(){
  Serial.printf("Core %d\n ", xPortGetCoreID());
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void Task1_Code(void *parameter)
{

  for (;;)
  {
    long start = millis();

    create_artificial_Load();

    Serial.print("Finish Task 1 which runs on Core ");
    Serial.print(xPortGetCoreID());
    Serial.print(" Time ");
    Serial.println(millis() - start);
    delay(10);
  }
}

void Task2_Code(void *parameter)
{
  for (;;) {
    long start = millis();

    blink_LED();

    Serial.print("Finish Task 2 which runs on Core ");
    Serial.print( xPortGetCoreID());
    Serial.print(" Time ");
    Serial.println(millis() - start);
    delay(10);
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  xTaskCreatePinnedToCore(
      Task1_Code, /* Function name */
      "Task1",    /* Internal name */
      900,       /* Stack size */
      NULL,       /* Task parameter */
      1,          /* priority for the Task */
      &Task1,     /* Task handler to keep track of the task by internal name */
      0           /* Core to pin to */
  );

  delay(500);

  xTaskCreatePinnedToCore(
      Task2_Code, /* Function name */
      "Task2",    /* Internal name */
      900,       /* Stack size */
      NULL,       /* Task parameter */
      1,          /* priority for the Task */
      &Task2,     /* Task handler to keep track of the task by internal name */
      1           /* Core to pin to */
  );
}

void loop()
{
  // put your main code here, to run repeatedly:
  // if no code is avaible in loop, the stack size will still be defined on default
  // this can slow down the process
  delay(0);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}
