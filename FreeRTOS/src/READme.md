1. define a TaskHandle_t TaskXYZ
2. Create in setup() ad xTaskCreatePinnedToCore()

xTaskCreatePinnedToCore(
codeForTask1,
"Task-Name",
1000,       /* Stack size */
NULL,       /*Task parameter*/
1,          /*priority for the Task*/
&Task1,     /* Task handler to keep track of the task */
1           /*Core to pin to*/

)
The naming of the prefixes of the variables and functions results from the variable type or
the variable type of the return value.
"c" stands for "char",
"s" for "short",
"v" for "void",
 a "u" for "unsigned" and
"x" for all non-standard types

### Filling the task with content - the task function
To fill the previously created task with life, you use the task function that you defined in xTaskCreate() (pvTaskCode). It is necessary to write void *pvParameters once again in the receiving function, even if you pass NULL. So, for example: void blink1(void *pvParameters){....}.
void Task1_Code(void *parameter){};
Inside the function you can call other functions without this way.

#### The following applies to the task function:
It has no return value.
Like a stand-alone sketch, the task function consists of a type of setup, i.e. code that is only executed once and a continuous loop that you implement with while(1){....} or for(;;){....}.
A task can delete itself with vTaskDelete( NULL );. Deletion is carried out from outside the task using the task handle, i.e. vTaskDelete(pxCreatedTask).
