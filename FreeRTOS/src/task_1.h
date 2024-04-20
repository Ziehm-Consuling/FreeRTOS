unsigned long loops1 = 2000;
unsigned long loops2 = 2000;
float t1;
int t2;
int t3;
unsigned long qq = 0;
unsigned long i, j;

void create_artificial_Load();

void Task1_Code(void *parameter)
{

  for (;;)
  {
    long start = millis();

    //create_artificial_Load();
    delay(500);
    Serial.printf("Finish Task 1 which runs on Core %d", xPortGetCoreID());
    Serial.print(" Time: ");
    Serial.println(millis() - start);
    Serial.print(" -------------------------------- \n");
    delay(1000);
  }
}


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
