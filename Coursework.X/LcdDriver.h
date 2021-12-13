#include <xc.h>

#ifndef LCDDIVER_H
#define	LCDDIVER_H

// create variables for pins
#define rs RA2
#define rw RA3
#define en RA5

void delay_xy (int x, int y);
void write_cmd(char cmd);
void write_data(char data);
void clear_display();
void write_string_at_pos(int position, char text[]);
void write_char_at_pos(int position, char character);
void init_display();
void wait_busy();
void move_cursor(int position);

#endif	/* LCD_H */

