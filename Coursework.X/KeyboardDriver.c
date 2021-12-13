#include "KeyboardDriver.h"

void init_keyboard()
{
    ADCON1 = 0x07;  // PORTA as ordinary I/O
    TRISA = 0x00;   // Configure RA0 -> RA7 as Input (1) or output (0) based on binary of 0x00
    TRISD = 0x00;   // Configure RD0 -> RD7 as Input (1) or output (0) based on binary of 0x00
    TRISC = 0x00;
}

char read_keys()
{
    for(int i = 0; i < 4; ++i){
        char keypad[16] = {'7', '8', '9', 'U',
                  '4', '5', '6', 'D',
                  '1', '2', '3', '#',
                  '-', '0', '+', '#',};
        int swIndexes[4] = {0, 1, 2, 3};
        switch(i){
            case 0:
                col1 = 1; 
                col2 = 0;
                col3 = 0;
                col4 = 0;
                swIndexes[0] = 0;
                swIndexes[1] = 1;
                swIndexes[2] = 2; 
                swIndexes[3] = 3;
                break;
            case 1:
                col1 = 0; 
                col2 = 1;
                col3 = 0;
                col4 = 0;
                swIndexes[0] = 4;
                swIndexes[1] = 5;
                swIndexes[2] = 6;
                swIndexes[3] = 7;
                break;
            case 2:
                col1 = 0; 
                col2 = 0;
                col3 = 1;   
                col4 = 0;
                swIndexes[0] = 8;
                swIndexes[1] = 9;
                swIndexes[2] = 10;
                swIndexes[3] = 11;
                break;
            case 3:
                col1 = 0; 
                col2 = 0;
                col3 = 0;
                col4 = 1;
                swIndexes[0] = 12;
                swIndexes[1] = 13;
                swIndexes[2] = 14;
                swIndexes[3] = 15;
                break;
            default:
                break;
        }
        if (sw0 == 0)
        {
            return keypad[swIndexes[0]];
        }
        if (sw1 == 0)
        {
            return keypad[swIndexes[1]];
        }
        if (sw2 == 0)
        {
            return keypad[swIndexes[2]];
        }
        if (sw3 == 0)
        {
            return keypad[swIndexes[3]];
        }
    } 
    return '#';
}


