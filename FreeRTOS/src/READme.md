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
