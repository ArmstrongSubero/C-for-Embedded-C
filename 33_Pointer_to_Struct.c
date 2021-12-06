//NOTES:We can use poninters for struct
// variables note that the pointer must
// first be initialized to point to
// the address of the structure itself
// ptrName = &structVariable;

#include <stdio.h>
#include <conio.h>

// struct for complex type
typedef struct
{
    float re;
    float im;
} complex;


int main()
{
    // complex variable
    complex x;
    
    // ptr to complex
    complex *p;
    
    p = &x;
    
    // set x.re to 1.25 via p
    p->re = 1.25;
    
    // set x.im = 2.50 via p
    p->im = 2.50;
    
    return 0;
}