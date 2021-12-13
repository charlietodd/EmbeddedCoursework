#include "LcdDriver.h"
#include "KeyboardDriver.h"
#include "RtcDriver.h"
#include "Delay.h"

#include <xc.h> // DO WE NEED IN MAIN OR DRIVERS THAT USE IT? DOES WORK LIKE THIS THOUGH (SAVE MEMORY?)

// config
#pragma config FOSC = HS    // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF   // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON   // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF  // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF    // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)

unsigned char mode = HOME;

void write_empties();

// ================== LCD AND KEYBOARD ==================
//void main(void) 
//{
//    ADCON1 = 0x07;
//    TRISA = 0x00;
//    TRISD = 0x00;
//    
//    init_display();
//    clear_display();
//    write_string_at_pos(0, "hello world: ");
//    int currentPos = 16;
//    
//    while (1)
//    {
//        init_keyboard();
//        char test = read_keys();
//        if(test != '#')
//        {
//            write_char_at_pos(currentPos, test);
//            if(currentPos != 31){
//             ++currentPos;   
//            }
//            else{
//                currentPos = 16;
//            }
//        }
//        delay_xy (10, 100); // debouncing done here
//    }
//}

//// ================== REAL TIME CLOCK ==================
//void main(void) 
//{
//    ADCON1 = 0x07;
//    TRISA = 0x00;   
//    TRISD = 0x00;
//    TRISE = 0x00;
//    
//    init_display();
//    clear_display();
//    write_string_at_pos(0, "hello world: ");
//    int currentPos = 16;
//
//    // ====== USE TO SET CURRENT TIME ======
//    //setHour(18);
//    //setMin(22);
//    //setSec(01);
//    
//    while (1)
//    {
//        move_cursor(currentPos);
//        
//        // hours
//        RST = 1;
//        sendRTC(0x85);
//        tmp = getRTC();
//        RST = 0;
//               
//        hr = intToChar(tmp & 0b00001111);
//        hr10 = intToChar((tmp & 0b00110000) >> 4);
//        
//        write_data(hr10);
//        write_data(hr);
//        write_data(':');
//        __delay_ms(100);
//        
//        // retrieve mins
//        RST = 1;
//        sendRTC(0x83);
//        tmp = getRTC();
//        RST = 0;
//               
//        min = intToChar(tmp & 0b00001111);
//        min10 = intToChar((tmp & 0b01110000) >> 4);
//        
//        write_data(min10);
//        write_data(min);
//        write_data(':');
//        __delay_ms(100);
//        
//        // retrieve seconds
//        RST = 1;
//        sendRTC(0x81);
//        tmp = getRTC();
//        RST = 0;
//               
//        sec = intToChar(tmp & 0b00001111);
//        sec10 = intToChar((tmp & 0b01110000) >> 4);
//        
//        write_data(sec10);
//        write_data(sec);
//     
//    }
//}

void main(void) 
{
    ADCON1 = 0x07;
    TRISA = 0x00;
    TRISD = 0x00;
    
    init_display();
    clear_display();
    write_string_at_pos(0, "hello world: ");
    int currentPos = 16;
    
    
    while (1)
    {
        init_keyboard();
        char test = read_keys();
        if(test != '#')
        {
            write_char_at_pos(currentPos, test);
            if(currentPos != 31){
             ++currentPos;   
            }
            else{
                currentPos = 16;
            }
        }
        delay_xy (10, 100); // debouncing done here
    }
}