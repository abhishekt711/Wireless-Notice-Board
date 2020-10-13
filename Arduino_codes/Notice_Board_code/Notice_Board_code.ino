#include <SoftwareSerial.h>
#include <Wire.h>
#include <dht.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C
#define DHT11_PIN 11
dht DHT;
SoftwareSerial SIM900(9, 10);
Adafruit_SSD1306 display(1);
int inByte;
void setup() {
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  SIM900.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);

  SIM900.print("AT+CMGF=1\r");
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Wireless Notice Board");
  display.display();
 

}
void loop()
{
  int y=0;
  int x=0;
  for (y=8; y<=15; y++)
      {
       for (x=0; x<127; x++)
       {
        display.drawPixel(x, y, BLACK); 
       }
      } 

 display.setTextSize(1);
 display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Wireless Notice Board");
  display.setCursor(0,8);
  int chk = DHT.read11(DHT11_PIN);
  display.print(DHT.temperature);
  display.setCursor(32,8);
  display.print("C");
 display.setCursor(84,8);
  display.print(DHT.humidity);
  display.setCursor(118,8);
  display.print("%");
  delay(400);
  display.display();
  display.clearDisplay();
    do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
 
   do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
 
   do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
 
   do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
    do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
 
   do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
   while ( !SIM900.available() );
   inByte = SIM900.read();   
   while ( !SIM900.available() );
   inByte = SIM900.read();
   int k =0;
   int m =16;

   while(1)
   {

       while ( !SIM900.available() );
       inByte = SIM900.read();
     
       if ( inByte == '\r' )
         break;
       else;
      Serial.write(inByte);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(k,m);
  display.println(char(inByte));
  // update display with all of the above graphics
  display.display();
  
   k=k+6;
   if(k>=124)
   {
    k=0;
    m=m+8;
   }
   if(m>=32)
   {
    k=0;
    m=0;
   }
}
 //while (1)
//{

//}

  }
   
  



