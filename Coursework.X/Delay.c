#include "Delay.h"

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
