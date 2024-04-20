

#define LED_BUILTIN 2

void blink_LED();

void Task2_Code(void *parameter)
{
  for (;;)
  {
    long start = millis();

    //blink_LED();
    delay(500);

    Serial.printf("Finish Task 2 which runs on Core %d", xPortGetCoreID());
    Serial.print(" Time: ");
    Serial.println(millis() - start);
    Serial.print(" -------------------------------- \n");
    delay(1000);
  }
}

void blink_LED()
{
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                     // wait for a second
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                     // wait for a second
}
