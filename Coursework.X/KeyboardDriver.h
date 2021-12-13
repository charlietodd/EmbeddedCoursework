#ifndef KEYBOARDDIVER_H
#define	KEYBOARDDIVER_H

#include <xc.h>

// create variables for pins
#define sw0 RB0
#define sw1 RB2
#define sw2 RB4
#define sw3 RB5
#define col1 RA1
#define col2 RC7
#define col3 RC6
#define col4 RC5



void init_keyboard();
char read_keys();

#endif	/* KEYBOARD_H */

