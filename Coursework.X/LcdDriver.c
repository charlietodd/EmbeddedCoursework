#include <xc.h>
#include <string.h>

#include "LcdDriver.h"

// Functions
void delay ()  
{
    for (unsigned i=0; i<100; i++);
}

void delay_xy (int x, int y)
{
    int i,j;
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)NOP();
}


// write a command to LCD
void write_cmd(char cmd)
{
    // initialize pins
    rs = 0;
    rw = 0;
    en = 0;
    
    // set RA5 to high
    en = 1;
    delay(); 
    
    // place data on PORTD
    PORTD = cmd;
    delay(); 
    
    // set RA5 to low
    en = 0;
}

// write a byte of data
void write_data(char data){
    
    rs = 1; // is data not command
    rw = 0; // is data not read
    en = 0; 
    
    delay();
    
    en = 1;
    
    PORTD = data; // place data on PORTD
    
    delay();

    en = 0;
}

void clear_display(){
    // clear screen
    write_cmd(0x01);
}

// Write string starting at the specified position (0-31 indexing, will overwrite)
void write_string_at_pos(int position, char text[]) //used for writing multiple characters 
{
    move_cursor(position);
    for(int i=0; i<strlen(text); i++)
    {
        write_data(text[i]);
    }
}
// Writes a single character at the specified position (0-31 indexing, will overwrite)
void write_char_at_pos(int position, char character){
    move_cursor(position);
    write_data(character);
}

void init_display()
{
    write_cmd(0x01); //clear screen
    delay_xy(50,50);
    write_cmd(0x38); //8 bit, 2 line, 5x7 mode
    delay_xy(50,50);
    write_cmd(0x0e); //display on, cursor on, blink on
    delay_xy(50,50);
}
// Enforces 0-31 indexing scheme on LCD position (see notes)
void move_cursor(int position) // target an exact location on LCD
{
    write_cmd(0x02); // Reset cursor to start of LCD (keeps contents)
    delay_xy(50,50);
    if(position>=0 && position<=15)
    {
        // Start writing on first line
        for(int i=0; i<position; i++)
        {
            write_cmd(0x14); // Move cursor right (keeps contents)
            delay_xy(50,50);
        }
    }
    else if(position>=16 && position <=31 ){
        // Start writing on second line
        write_cmd(0x0C0); // Shift cursor to second line
        delay_xy(50,50);
        for(int i=16; i<position; i++)
        {
            write_cmd(0x14); // Move cursor right (keeps contents)
            delay_xy(50,50);
        }
    }
}

void wait_busy()
{
    rw = 1;
    rs = 0;
    TRISD = 0xff;
    while(RD7);
    TRISD = 0x00;
}
