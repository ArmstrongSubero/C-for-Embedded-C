#include <stdio.h>
#include <conio.h>

struct byteBits
{
    unsigned int b1volts: 1;
    unsigned int b1amps: 1;
    unsigned int b1humid: 2;
    unsigned int b1temp: 1;
    unsigned int b1tach: 3;
    
} x;


int main()
{
    // may contain values from 0 to 1
    x.b1volts = 1;
    
    // may contain values from 0 to 1
    x.b1amps = 0;
    
    // may contain values from 0 to 3
    x.b1humid = 0b10;
    
    // may contain values from 0 to 1
    x.b1temp = 0x0;
    
    // may contain values from 0 to 7
    x.b1tach = 7;
    
    printf("%d", x.b1humid);
    
    
    return 0;
}