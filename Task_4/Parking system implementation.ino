#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

#define t1 8
#define t2 9
#define t3 10

int Buzzer = 13;
long int start;
long int endtime;
void setup()
{
lcd.begin(16,2);
  lcd.setCursor(0,0);
  Serial.begin(9600);
   start= micros();
     }

long readDistance(int trigPin, int echoPin)
{
 pinMode(trigPin, OUTPUT);
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(5);
 digitalWrite(trigPin, LOW);
 pinMode(echoPin, INPUT);
return pulseIn(echoPin, HIGH);
float readtime= micros();
  Serial.println("read time ");
  Serial.println(readtime);
  }
void loop()
{
  
  float p1 = 0.01724* readDistance(t1, t1),p2 = 0.01724* readDistance(t2, t2),p3 = 0.01724* readDistance(t3, t3);

  
  Serial.println("Distance of the vehicle at parkking space 1 -" +String(p1)+"cm");
  Serial.println("Distance of the vehicle at parking space 2 -" +String(p2)+"cm");
  Serial.println("Distance of the vehicle at parking space 3 -" +String(p3)+"cm");
 
  
  if(p1>50 & p2>50 & p3>50)
  {
    lcd.setCursor(0,0);
    lcd.print("All are available  ");
    lcd.setCursor(0,1);
    lcd.print("1,2,3 are free    ");
    delay(500);
    endtime=micros();
    float executiontime;
    executiontime=endtime-start;
    Serial.print("execution time is ");
    Serial.print(executiontime);
    Serial.print("microseconds\n\n");
    start=endtime;
        }
  
  else if((p1>50 & p2>50)|(p2>50 & p3>50 )|( p3>50 & p1>50))
  {
    lcd.setCursor(0,0);
    lcd.print("Two available  ");
    lcd.setCursor(0,1);
    if(p1>50 & p2>50)
      lcd.print("Parking 1,2 are free ");
    else if(p2>50 & p3>50)
      lcd.print("Parking 2,3 are free  ");
    else if(p3>50 & p1>50)
      lcd.print("Parking 1,3 are free  ");
      delay(500);
      endtime=micros();
    float executiontime;
    executiontime=endtime-start;
    Serial.print("execution time is ");
    Serial.print(executiontime);
    Serial.print("microseconds\n\n");
    
  start=endtime;
  }
         
        else if ((p1<50 & p2<50 & p3<50))
      {
        lcd.setCursor(0,0);
        lcd.print("Not available    ");
        lcd.setCursor(0,1);
        lcd.print("Parking full     ");
        delay(500);
        tone(Buzzer, 500);
      delay(1000);
      noTone(Buzzer);
      delay(100);
     endtime=micros();
    long int executiontime;
    executiontime=endtime-start;
    Serial.print("execution time is ");
    Serial.print(executiontime);
    Serial.print("microseconds\n\n");  
        start=endtime;
        }
   else if((p1<50 & p2<50)|(p2<50 & p3<50)|(p1<50 & p3<50))
    {    
    lcd.setCursor(0,0);
    lcd.print("One available   ");
    lcd.setCursor(0,1);
    if(p1>50) 
        lcd.print("Parking 1 is free    ");
  else if(p2>50)
        lcd.print("Parking 2 is free    ");
  else 
    lcd.print("Parking 3 is free   ");
      delay(500);
      endtime=micros();
    long int executiontime;
    executiontime=endtime-start;
    Serial.print("execution time is ");
    Serial.print(executiontime);
    Serial.print("microseconds\n\n");
   start=endtime;  
   }

    delay(100);
       }