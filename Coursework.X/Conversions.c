#include "Conversions.h"

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
