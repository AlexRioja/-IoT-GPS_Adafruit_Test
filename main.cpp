
// gps.cpp
// for use with Adafruit Ultimate GPS
// Reads in and parses GPS data

#include "MBed_Adafruit_GPS.h"
#include "PinNames.h"
#include "mbed.h"

BufferedSerial *gps_Serial;
BufferedSerial pc(USBTX, USBRX);
DigitalOut led1(LED1);

int main() {

  Timer t;


   printf("\r\n\nProgram start\r\n");
  gps_Serial = new BufferedSerial(PA_2, PA_1); // serial object for use w/ GPS
  Adafruit_GPS myGPS(gps_Serial);    // object of Adafruit's GPS class
  char c; // when read via Adafruit_GPS::read(), the class returns single
          // character stored here
  myGPS.begin(9600); // sets baud rate for GPS communication; note this may be changed
             // via Adafruit_GPS::sendCommand(char *) a list of GPS commands is
             // available at http://www.adafruit.com/datasheets/PMTK_A08.pdf
   ThisThread::sleep_for(1);

  myGPS.sendCommand("$PMTK605*31\r\n");
  t.start();
  while (t.read_ms() < 1000) {
    c = myGPS.read();
    if (c) {
       printf("%c", c);
    }
  }
  t.stop();
  t.reset();
  myGPS.sendCommand("$PMTK104*37\r\n");
  t.start();
  while (t.read_ms() < 1000) {
    c = myGPS.read();
    if (c) {
       printf("%c", c);
    }
  }
  t.stop();
  t.reset();
  myGPS.sendCommand("$PMTK220,1000*1F\r\n");
  t.start();
  while (t.read_ms() < 1000) {
    c = myGPS.read();
    if (c) {
       printf("%c", c);
    }
  }
  t.stop();
  t.reset();
  myGPS.sendCommand("$PMTK251,9600*17\r\n");
  t.start();
  while (t.read_ms() < 1000) {
    c = myGPS.read();
    if (c) {
       printf("%c", c);
    }
  }
  t.stop();
  t.reset();
  myGPS.sendCommand("$PMTK313,1*2E\r\n");
  t.start();
  while (t.read_ms() < 1000) {
    c = myGPS.read();
    if (c) {
       printf("%c", c);
    }
  }
  t.stop();
  t.reset();
  myGPS.sendCommand("$PMTK104*37\r\n");
  t.start();
  while (t.read_ms() < 1000) {
    c = myGPS.read();
    if (c) {
       printf("%c", c);
    }
  }
  t.stop();
  t.reset();
  myGPS.sendCommand("$PMTK251,9600*17\r\n");
  t.start();
  while (t.read_ms() < 1000) {
    c = myGPS.read();
    if (c) {
       printf("%c", c);
    }
  }
  t.stop();
  t.reset();

  myGPS.sendCommand("$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n");
   ThisThread::sleep_for(0.3);
  t.start();
  while (t.read_ms() < 1000) {
    c = myGPS.read();
    if (c) {
       printf("%c", c);
    }
  }
  t.stop();
  t.reset();
  myGPS.sendCommand("$PMTK319,1*24\r\n");
  t.start();
  while (t.read_ms() < 1000) {
    c = myGPS.read();
    if (c) {
       printf("%c", c);
    }
  }
  t.stop();
  t.reset();

  //        myGPS.sendCommand("$PMTK605*31\r\n"); I have tried these without
  //         ThisThread::sleep_foring and printing, also doesn't work
  //        myGPS.sendCommand("$PMTK104*37\r\n");
  //        myGPS.sendCommand("$PMTK220,1000*1F\r\n");
  //        myGPS.sendCommand("$PMTK251,9600*17\r\n");
  //        myGPS.sendCommand("$PMTK313,1*2E\r\n");
  //        myGPS.sendCommand("$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n");
  //        myGPS.sendCommand("$PMTK319,1*24\r\n");
  //        myGPS.sendCommand("$PMTK413*34\r\n");
  //        myGPS.sendCommand("$PMTK513,1*28\r\n");

  while (true) {

    c = myGPS.read();   // queries the GPS
     printf("%c", c); // this line will echo the GPS data if not paused
  }
}