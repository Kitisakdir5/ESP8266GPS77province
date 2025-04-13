
// this program no average distances

#include <TridentTD_LineNotify.h>
////////////// Library for GPS ES8266 ///////////////////
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
 // #include <ESP8266WiFi.h>
#include "characterthai.h"
#include "gpspro77.h"
#include "distancegps1.h"

/*
   This sample sketch demonstrates the normal use of a TinyGPS++ (TinyGPSPlus) object.
   It requires the use of SoftwareSerial, and assumes that you have a
   4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/
static const int RXPin = 12 , TXPin = 14 ;  // (4,5) GPIO4 or D2 connect to TX from GPS GPIO5 or D1 connect to RX
static const uint32_t GPSBaud = 9600;  // 9600 use follow clip Viral Science

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

////////////// variable for Linenotify ////////////////
#define SSID        "SuperHero4G" //  "J_Kitisak_2.4GHz"                                     //ใส่ ชื่อ Wifi ที่จะเชื่อมต่อ
#define PASSWORD    "876543210"    // "081234"                                //ใส่ รหัส Wifi
#define LINE_TOKEN  "PajKJCZ8h5kou3invwQZsXyYt4PVHFt8FpWlhLRNrIV" //ใส่ รหัส TOKEN ที่ได้มาจากข้างบน


String latandlong1 ,latandlong2 , disline1 , disline2 ; 
String comma1 = "," , meter1 = " เมตร" , settingA1 , settingA2 , settingA3 , settingA4 ;
String settinggps = "กำหนดค่าพิกัด GPS ตำแหน่งที่ท่านจอดรถเก๋งเอาไว้ " , thisgps ="นี่คือพิกัดรถเก๋งของท่านตอนนี้ " ; 
String distext = "รถเก๋งของท่านอยู่ห่างจากที่จอดรถเป็นระยะทาง " ;
byte setpushg1 = 0 ;
char latstr1[15] , longstr1[15] ; 
/////// speed from GPS is knot . change to Km/h. 1 knot = 1.852 Km/h  ///////////// 

//////////////////// Variable /////////////////////
double gpslat = 0.0 , gpslong=0.0 , speedkmph =0.0 ;
int speedkmphi = 0 ;
String kmphth = " กิโลเมตรต่อชั่วโมง" , speedkmphall ,speedtext = "รถเก๋งของท่านกำลังวิ่งด้วยความเร็ว " ;
// SET FIX GPS 
double LatitudeC1= 10.47272  , LongitudeC1 = 98.81155 , Distance3= 0.0 ; 
byte countn2= 1 ,c1 = 0, c2=0 ,c3=0 , c4 = 0,c5 ;

// Interrupt 
const byte interruptPin = D8 ;
const byte buzzPin = D0 ;
const byte ledPin = D7 ;

 String gpslat2 , gpslong2 ,speedkmph2 ;
int day1 , month1 , year1 ;
char latstr[15], longstr[15] , latstrf[15] , longstrf[15] , latstrt[15], longstrt[15]  ;

int fixdist1 = 10 , nowdist1=0, nowdist2=0 , alarm1 = 0 , alarm2 = 0 , alarm3=0 ; 
// fixdist1 = 10 
// check delete old distance
int discp1 , discp2 ;
byte countn3 = 1 ;

//// estimated province77
double distance77=0.0 ,distance7710 = 0.0, lat77=0.0, long77=0.0 , compared77=0.0 ;
byte c6 , c7 ,c8 , compared72=0 , count771 = 1 ;
String provincen ;

void ICACHE_RAM_ATTR setgps() {
 LatitudeC1 = gpslat ;
 LongitudeC1 = gpslong ;
  Serial.print("Set Latitude , Longitude parking spots ") ;
  Serial.print("LatitudeC1 = ") ;
  Serial.print(LatitudeC1 , 6 ) ;
  Serial.print(" - ") ;
  Serial.print("LongitudeC1 = ") ;
  Serial.print(LongitudeC1 , 6 ) ;
  Serial.print("\n") ;
  setpushg1 = 1 ;
}



  //////////////// not delay in void loop //////////////////
void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {

    Serial.print("Begin LOOP Void displayInfo() ");
    Serial.print("\n");
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
   gpslat = gps.location.lat() ; ////////// Latitude
   gpslong = gps.location.lng() ; /////////  Longitude

    dtostrf(gpslat,8,5,latstr);  // 8,6
    dtostrf(gpslong,8,5,longstr);  // 8,6

  Serial.print("\n");
  Serial.print("set GPS Latitude = ");
  Serial.print(LatitudeC1,6);
  Serial.print("\n");
  Serial.print("set GPS Longitude = ");
  Serial.print(LongitudeC1,6);
  Serial.print("\n");

while ( setpushg1 == 0) {
  gpsready() ;
Serial.println("Push Green Botton.... ") ;
delay(1000) ;
}

if ( setpushg1 == 1) {
    lcd.clear() ;
    dtostrf(gpslat,8,5,latstrt);  // 8,6
    dtostrf(gpslong,8,5,longstrt);  // 8,6

  latandlong1 = latstrt + comma1 + longstrt ;
  settingA1 = settinggps + latandlong1 ;
 // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);

  for ( c4=1 ; c4 < 3 ; c4++ ) {
   Serial.println("The car stop in this GPS .") ;
     LINE.notify(settingA1) ; // กำหนดค่าพิกัด GPS ตั้งต้น 
     digitalWrite(buzzPin,HIGH) ;
      delay(1000) ; // 500
      digitalWrite(buzzPin,LOW) ;
      delay(500) ;
    digitalWrite(ledPin,HIGH) ;
      delay(1000);  
      digitalWrite(ledPin,LOW) ;
      delay(500) ;
      Serial.println("Setting GPS LAt LONG begin ....") ;
  }  // END for loop c4
    setpushg1 = 2 ;
}  // END setpushg1 == 1

 /// Show LCD Begin  ///////////   
    lcd.setCursor(0,0);
    lcd.print("P1=");
    lcd.setCursor(11,0);
    lcd.print(",");
    lcd.setCursor(0,1);
    lcd.print("P2=");
    lcd.setCursor(11,1);
    lcd.print(",");
    lcd.setCursor(0,2);
    lcd.print("D=");
    lcd.setCursor(9,2);
    lcd.print("mS=");

  speedkmph = 1.852 * gps.speed.kmph() ;
  speedkmphi = int(speedkmph) ;
  speedkmph2 = String(speedkmph) ; 
  Serial.print("Show speed KmpH 2 and 1.852");
  Serial.print("\n");
  Serial.print(speedkmph2); 
   Serial.print("\n");
  /// convert double to string for  show  LCD /////
  //// dtostrf(float_value, min_width,num_digits_after_decimal,where_to_store_string)
   /////  dtostrf(gpslat,min width 8 is 10.47401 ,6 is .474010 ,latstr);
    dtostrf(LatitudeC1,8,5,latstrf);  // 8,6
    dtostrf(LongitudeC1,8,5,longstrf);  // 8,6

////////////  show latitude longitude on LCD ////
    lcd.setCursor(3,0);
    lcd.print(latstrf);
    lcd.setCursor(12,0);
    lcd.print(longstrf);
    lcd.setCursor(3,1);
    lcd.print(latstr);
    lcd.setCursor(12,1);
    lcd.print(longstr);
/// solution distance 
    Distance3 = soldistance1(gpslat, gpslong, LatitudeC1, LongitudeC1 ) ;

  Serial.print("Distance from solution 3");
  Serial.print("\n");
  Serial.print(Distance3,6) ;
  Serial.print("\n");
  
/// calculated  GPS point where is province ? 
      Serial.print("Estimates province 77 now GPS = ") ;
      Serial.print(gpslat,6) ;
      Serial.print(" , ") ;
      Serial.print(gpslong,6) ;
      Serial.print("\n") ;

  for(c6=1;c6 < 78; c6++) {
    lat77 = Latitude77[c6] ;
    long77 = Longitude77[c6] ;

    distance77 = soldistance1(gpslat, gpslong, lat77, long77 ) ;
    distance7710 = distance77 / 1000 ;
   //   Serial.print("province = ") ;
   //   Serial.print(c6) ;
   //   Serial.print(" - ") ;
   //   Serial.print(Provice77[c6]) ;
   //   Serial.print(" = ") ;
   //   Serial.print(lat77,6) ;
   //   Serial.print(" , ") ;
   //   Serial.print(long77,6) ;
   //   Serial.print(" - ") ;
   //   Serial.print("distance7710 = ") ;
   //   Serial.print(distance7710,3) ;
   //   Serial.print(" km ") ;
   //   Serial.print("\n") ;
   dist77[c6] = distance7710 ;
    

  }  /// END  for(c6=1;c6 < 79; C6++) 

//  compare distance province 77
for ( c7=1 ; c7 < 77 ; c7++) { 
count771++ ;
if ( c7 == 1) {
  if ( dist77[c7] < dist77[count771] ) {
        compared77 = dist77[c7] ;
  }
  if ( dist77[c7] > dist77[count771] ) {
        compared77 = dist77[count771] ;
  }
  if ( dist77[c7] == dist77[count771] ) {
        compared77 = dist77[c7] ;
  }
}
if ( c7 > 1 ) {
  if ( compared77 < dist77[count771] ) {
        //compared77 = dist77[count771] ;
  }
  if ( compared77 > dist77[count771] ) {
        compared77 = dist77[count771] ;
  }
  if ( compared77 == dist77[count771] ) {
       // compared77 = compared77 ;
  }
}
 // Serial.print("c7 = ") ;
 // Serial.print(c7) ;
 // Serial.print(" - ") ;
 // Serial.print("dist77 = ") ;
 // Serial.print(dist77[c7]) ;
 // Serial.print(" - ") ;
 // Serial.print("before compared77 = ") ;
 // Serial.print(compared77) ;
 // Serial.print("\n") ;

}   // for ( c7=1 ; c7 < 78 ; c7++) 


   for( c8 =1; c8 < 78 ;c8++) {    
    if ( compared77 == dist77[c8]){
      compared72 = c8 ;
 // Serial.print("compared77 = ") ;
 // Serial.print(compared77) ;
 // Serial.print(" - ") ;
 // Serial.print("compared72 = ") ;
 // Serial.print(compared72) ;
 // Serial.print(" - ") ;
 // Serial.print("c8 = ") ;
//  Serial.print(c8 ) ;
//  Serial.print(" - ") ;
 // Serial.print(Provice77[compared72] ) ;
 // Serial.print("\n") ;
   provincen = Provice77[compared72] ;
    }  
   } // END  for( c8 =1; c8 < 78 ;c8++) { 
  count771 = 1 ;

  ///   show LCD speedkmphi
    lcd.setCursor(13,2);
    lcd.print(speedkmphi);
    lcd.setCursor(16,2);
    lcd.print("km/h");

    // fixdist1 = 10 
    alarm1 = fixdist1 ; // 10 m , C , no sound , "รถจอดอยู่ที่เดิม"
    alarm2 = fixdist1 + 5 ; // 15 m , B , sound 1 , "รถเคลื่อนที่"
    alarm3 = fixdist1 + 20 ; // 20 m  , A , sound 1 , "รถโดนขโมย",ส่งพิกัด
   


/// show distance
  Serial.print("Distance3 = ") ;
  Serial.print(Distance3,6) ;
  Serial.print(" -  ") ;
  Serial.print("LAT = ") ;
  Serial.print(gpslat,6) ;
  Serial.print(" -  ") ;
  Serial.print("LONG = ") ;
  Serial.print(gpslong,6) ;
  Serial.print("\n") ;
    dtostrf(gpslat,8,5,latstr1);  // 8,6
    dtostrf(gpslong,8,5,longstr1);  // 8,6
    nowdist2 = int(Distance3) ;
// show GPS is NOW  
    lcd.setCursor(3,1);
    lcd.print(latstr1);
    lcd.setCursor(12,1);
    lcd.print(longstr1);

  ///   show LCD Distance3

  // check distance for delete old value 
// check delete old distance
//int discp1 , discp2 ;
// byte countn3 = 1 ;
   if ( countn3==1) {
    discp1 = nowdist2 ; // 50
    nowdist1 = discp1 ;
   lcd.setCursor(2,2);
   lcd.print(nowdist1);
   }

  if ( countn3==2) {
    discp2 = nowdist2 ; // 5000
  
  if ( discp1 > discp2 ) {
    nowdist1 = discp2 ;
    lcd.setCursor(2,2);
    lcd.print("       ");
    lcd.setCursor(2,2);
    lcd.print(nowdist1);
  }

 if ( discp1 == discp2 ) {
    nowdist1 = discp1 ;
    lcd.setCursor(2,2);
    lcd.print(nowdist1);
  }
 if ( discp1 < discp2 ) {
    nowdist1 = discp2 ;
    lcd.setCursor(2,2);
    lcd.print(nowdist1);
  }

    countn3 = 1 ;
   }
  // if ( countn3==2) 

 countn3++ ;



  // show LCD province 
    lcd.setCursor(0,3);
    lcd.print(provincen);

  
  // show distance GPS now and setting
    disline1 = String(Distance3) ;
    disline2 = disline1 + meter1 ;
// show speed car and string
    speedkmphall = speedkmph2 + kmphth ;
// show GPS car is now 
    latandlong2 = latstr1 + comma1 + longstr1 ;
    settingA2 = thisgps + latandlong2 ;
    settingA3 = speedtext + speedkmphall ;
    settingA4 = distext + disline2 ;
   if (  nowdist2 > alarm3  ){  // && ( speedkmphi > 5) 
    Serial.println("The car have stolen by Robber.") ;
   LINE.notify("รถเก๋งของท่านกำลังถูกขโมยออกจากที่จอดรถ");
   LINE.notify(settingA2);
   LINE.notify(settingA3);
    delay(500) ;
   LINE.notify(settingA4) ; 
   LINE.notify(provincen) ;    //
   lcd.clear() ;
   caution1() ;
  digitalWrite(buzzPin,HIGH) ;
  delay(1000) ; // 500
  digitalWrite(buzzPin,LOW) ;
  delay(500) ;
  digitalWrite(ledPin,HIGH) ; //    tone(D7, 1000, 1000); 
  delay(500) ;
  digitalWrite(ledPin,LOW) ;   
  delay(500) ;
  lcd.clear() ;
   }

/*
   if ( ( alarm1 < nowdist2) && ( nowdist2 < alarm2 ) ){
     Serial.println("The car is moving .") ;
       LINE.notify("รถเก๋งของท่านกำลังเคลื่อนที่");
      tone(buzzPin, 1000, 1000);  // สร้างเสียงที่ความถี่ 1000 Hz และยาว 1 วินาที
      delay(1500);  // หยุด 1.5 วินาที         
   }
   */
  ///////////// delay for program send latitude longitude to line /////////////////
  delay(500) ;
  ////////////// clear data string /////////////////
  latandlong1 = "" ;


  }  /// END    if (gps.location.isValid())
 else
  {
    Serial.print(F("INVALID"));
  }
  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());    
    day1 = gps.date.day() ;
    month1 = gps.date.month() ; 
    year1 = gps.date.year() ;    
  }
  else
  {
    Serial.print(F("INVALID"));
  }
 
  Serial.println();

  ///////////// END void displayInfo()  //////////////
}

void setup() {
//  Line notify set Wifi
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  ////////////////////// SETUP for GPS ESP8266  /////////////////
   ss.begin(GPSBaud);
  Serial.println(F("DeviceExample.ino"));
  Serial.println(F("A simple demonstration of TinyGPS++ with an attached GPS module"));
  Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("by Mikal Hart"));
  Serial.println(); 
  // lcd begin
    lcd.begin();
   waitwifigps() ;
  pinMode(ledPin,OUTPUT) ;
   pinMode(buzzPin,OUTPUT) ; 
   // Interrupt RISING  
  pinMode(interruptPin,INPUT_PULLUP) ;
  attachInterrupt(digitalPinToInterrupt(interruptPin), setgps, RISING) ;
 ///// end void setup loop    
}

void loop() {

  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
     if (gps.encode(ss.read()))
      displayInfo();
      delay(200) ;
///// change speed knot to Km/h  ////////////
// convert string to float use command string.toFloat() ;
// Ex. string abc = "5" ; -> float def = abc.toFloat() ;
  ///////////////////////////////////////////  

///////////////  Calculate Distance for GPS Fix to GPS  /////////////////
  ////       Right Distance = 53.62 m
   
 // Δ = Delta ,φ = Phi = Latitude , λ = lamda = Longitude 
 // formula a = sin^2(Δ(φ/2)) + cos φ1 * cos φ2 * sin^2(Δλ/2) 
 //         c = 2 * atan * 2 * (root a, root (1-a) 
 //         d = R * C           
 //         R = 6.3781 * 10^3 km Earth's Radius

 ////////////// end void loop  /////////////////
}












