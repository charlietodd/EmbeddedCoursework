#ifndef RTCDIVER_H
#define	RTCDIVER_H

#include <xc.h>
#include <string.h>
    
#define _XTAL_FREQ 4000000 //how fast the crystal weve used is (for us timing)
      
// create variables for pins
#define RST RE0     // Controls communication terminated or enabled
#define SCLK RE2    // Controls clock
#define RTC_IO RE1  // Input/output
    
unsigned char hours=0, hours10=0, hours1=0, minutes10=0, minutes1=0, seconds10=0, seconds1=0, seconds1old=0;
unsigned char tmp=0;

int s10 = 0;
int s1 = 0;
char sec10 = '0';
char sec = '0';
char min10 = '0';
char min = '0';
char hr10 = '0';
char hr = '0';
char time[6] = "HELLO!";

//void delay ();
//void delay_xy (int x, int y);
void write_cmd(char cmd);
void write_data(char data);
void write_string_at_pos(int position, char text[]); 
void write_char_at_pos(int position, char character);
void init_display();
void move_cursor(int position);
void wait_busy();
void clear_display();
void writeArray(int a[],int b[],int size);
void sendRTC (unsigned char value);
unsigned char getRTC (void);
char intToChar(int value);
void setTime(char timeDigit, char time);
//char intToHex(int i);
//int hexToInt(char i);
void setHour(int hour);
void setMin(int min);
void setSec(int sec);
char* getHour();
char* getMins();
char* getSecs();

#endif /* REALTIMECLOCK.H */