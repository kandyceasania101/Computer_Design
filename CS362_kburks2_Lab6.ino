#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>

//varibles for Time
int Hours ,Minutes, Seconds;

//variables for Date
int months, years, days;

//User prompt and format
String Date = "Enter Date :  MM/DD/YYYY.";
String Time = "Enter Time :  HH:MM:SS.";

//User input
String givenDate, givenTime;

LiquidCrystal LCD(11, 2, 4, 5, 6, 7);

//LCD Setup
void setup()
{
  LCD.begin(16, 2);
  Serial.begin(9660);
}

void loop()
{
  Serial.println(Date);
  
  //Wait
  while (1)
  {
    if (Serial.available() == 1){ break; }
  }

  if (Serial.available() == 1)
  {
    givenDate = Serial.readString();
    int length = givenDate.length();
    checkDate(givenDate);
    Serial.println(givenDate);

    //Check if input is too long
    if (length > 10){ Serial.println("Not Real Date, Try Again"); }
  }
  
  Serial.println(Time);
  
  while (1)
  {
    if (Serial.available() == 1){ break;}
  }

  if (Serial.available() == 1)
  {  
    givenTime = Serial.readString();
    checkTime(givenTime);
    
    setTime(Hours, Minutes, Seconds, days, months, years);
    clock();
    
    Serial.print(Hours);
    Serial.print(":");
    Serial.print(Minutes);
    Serial.print(":");
    Serial.println(Seconds);
  }
}

void checkDate(String Date)
{
  String month, DAY, year;

  month = Date.substring(0, Date.indexOf("/"));
  months = month.toInt();
  
  DAY = Date.substring(5, Date.indexOf("/") + 1);
  days = DAY.toInt();

  year = Date.substring(6);
  years = year.toInt();

  if ((months > 12) || (months < 1))
  {
    Serial.println("Not In Range. Try Again! ");
    loop();
  }
  else if ((months == 4) || (months == 6) || (months == 9) || (months == 11))
  {
    if ((days > 30) || (days < 1))
    {
      Serial.println("Not In Range. Try Again!");
      loop();
    }
  } 
  else if ((months == 1) || (months == 3) || (months == 5) || (months == 7) || (months == 8) || (months == 10) || (months == 12))
  {
    if ((days > 31) || (days < 1))
    {
      Serial.println("Not In Range. Try Again!");
      loop();
    }
  }
  else if (years % 4 == 0)
  {
    //leap year
    if (months == 2)
    {
      if (days > 29)
      {
        Serial.println("Not In Range. Try Again! ");
        loop();
      }
    }
  }
  else if (months == 2)
  {
    if (days > 28)
    {
      Serial.println("Not In Range. Try Again! ");
      loop();
    }
  }
}

void checkTime(String input)
{
  String hours, minutes, seconds;
  
  hours = input.substring(0, input.indexOf(":"));
  minutes = input.substring(5, input.indexOf(":") + 1);
  seconds = input.substring(6);
  
  Hours = hours.toInt();
  Minutes = minutes.toInt();
  Seconds = seconds.toInt();
  if ((Hours < 0) || (Hours > 23) || (Minutes < 0) || (Minutes > 59) || (Seconds < 0) || (Seconds > 59))
  {
    Serial.println("Not In Range. Try Again !");
    Serial.println(Time);
    while (1)
    {
      if (Serial.available() == 1){ break; }
    }
    if (Serial.available() == 1)
    {
      givenTime = Serial.readString();
      checkTime(givenTime);
      Serial.print(Hours);
      Serial.print(":");
      Serial.print(Minutes);
      Serial.print(":");
      Serial.println(Seconds);
    }
  }
}

void clock()
{
  while (1)
  {
    time_t t = now();
    Serial.print(hour(t));
    Serial.print(minute(t));
    Serial.print(second(t));
    Serial.println();
    Serial.println(day(t));
    Serial.println(month(t));
    Serial.println(year(t));
    delay(1000);
    LCD.clear();
    printDate(month(t), day(t), year(t));
    printTime(hour(t), minute(t), second(t));
  }
}

void printDate(int month, int day, int year)
{
  LCD.setCursor(10, 0);
  LCD.print(year);
  
  LCD.setCursor(9, 0);
  LCD.print("/");
  
  LCD.setCursor(7, 0);
  LCD.print(day);
  
  LCD.setCursor(5, 0);
  LCD.print("/");
  
  LCD.setCursor(3, 0);
  LCD.print(month);
}

void printTime(int hour, int minute, int second)
{
  LCD.setCursor(10, 1);
  if (second < 10){ LCD.print("0"); }
  
  LCD.print(second);
  LCD.setCursor(9, 1);
  LCD.print(":");
  
  LCD.setCursor(7, 1);
  LCD.print(minute);
  LCD.setCursor(5, 1);
  LCD.print(":");
  
  LCD.setCursor(3, 1);
  LCD.print(hour);
}
