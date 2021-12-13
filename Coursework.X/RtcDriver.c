#include "RtcDriver.h"
#include "LcdDriver.h"

#include <xc.h>
#include <string.h>

void delay () ;

void delay_xy (int x, int y);

// write a command to LCD
void write_cmd(char cmd);

// write a byte of data
void write_data(char data);

void clear_display();

// Write string starting at the specified position (0-31 indexing, will overwrite)
void write_string_at_pos(int position, char text[]);

// Writes a single character at the specified position (0-31 indexing, will overwrite)
void write_char_at_pos(int position, char character);

void init_display();

// Enforces 0-31 indexing scheme on LCD position (see notes)
void move_cursor(int position);

void wait_busy();

void writeArray(int a[],int b[],int size) 
{
    int i;
    
    for(i=0;i<size;i++)
    {
    b[i] = a[i];
    }
}

void sendRTC (unsigned char value) 
{
    RTC_IO = 0;
    TRISE = 0; // set data port as output
    char n = 0;
    
    // loop over eight bits
    for (n = 0; n < 8; n++) 
    {
        RTC_IO = (value >> n) & 1;
        SCLK = 1;
        __delay_us(10);
        SCLK = 0;
    }
    RTC_IO = 0;

}

unsigned char getRTC (void) 
{
    unsigned char value = 0;
    char n = 0;
    TRISE = 0x02;    
    
    // collect all eight bits
    for (n = 0; n < 8; n++) 
    {
        value |= (RTC_IO << n);
        SCLK = 1;
        __delay_us(10);
        SCLK = 0;
    }
    return value;
    
    TRISE = 0x00;
    RTC_IO = 0;
 
}

char intToChar(int value)
{
    switch(value)
    {
        case(0):
            return('0');
        case(1):
            return('1');
        case(2):
            return('2');
        case(3):
            return('3');
        case(4):
            return('4');
        case(5):
            return('5');
        case(6):
            return('6');
        case(7):
            return('7');
        case(8):
            return('8');
        case(9):
            return('9');
        default:
            return 'e';
         
    }
}

void setTime(char timeDigit, char time){
    RST = 1;
    sendRTC(timeDigit);
    sendRTC(time);
    RST = 0;
    __delay_us(20);
}

char intToHex(int i){
    char h = 0;
    int power = 1;
    while (i)
    {
        // assert(h % 16 < 10)
        h += i % 10 * power;
        i /= 10;
        power *= 16;
    }
    return h;
}

int hexToInt(char i){
    char h = 0;
    int power = 1;
    while (i)
    {
        // assert(h % 16 < 10)
        h += i % 16 * power;
        i /= 16;
        power *= 10;
    }
    return h;
}

void setHour(int hour){
    setTime(0x84,intToHex(hour));
}

void setMin(int min){
    setTime(0x82,intToHex(min));
}

void setSec(int sec){
    setTime(0x80,intToHex(sec));
}

char* getHour(){    
    RST = 1;
    sendRTC(0x85);
    tmp = getRTC();
    RST = 0;
   
    char hr[3] = "  ";

    hr[1] = intToChar(tmp & 0b00001111);
    hr[0] = intToChar((tmp & 0b00110000) >> 4);
    hr[2] = '\0';
    return &hr;
}

char* getMins()
{
    RST = 1;
    sendRTC(0x83);
    tmp = getRTC();
    RST = 0;
   
    char mins[3] = "  ";

    mins[1] = intToChar(tmp & 0b00001111);
    mins[0] = intToChar((tmp & 0b01110000) >> 4);
    mins[2] = '\0';
    return &mins;
}

char* getSecs()
{
    RST = 1;
    sendRTC(0x81);
    tmp = getRTC();
    RST = 0;
   
    char secs[3] = "  ";

    secs[1] = intToChar(tmp & 0b00001111);
    secs[0] = intToChar((tmp & 0b01110000) >> 4);
    secs[2] = '\0';
    return &secs;
}

#ifdef	__cplusplus
}
#endif

