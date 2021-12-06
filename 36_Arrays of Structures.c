//NOTES: Arrays of structures 
// are used when we want to duplicate multiple 
// instances of a condition 
#include <stdio.h>
#include <conio.h>

// structure defined with a typedef
typedef struct
{
    float re;
    float im;
} complex;

int main()
{
    // create an array of 3 instnces of
    // the complex structure
    // each member will have an re im member
    complex a[3];
    
    a[0].re = 1.25;
    a[0].im = 2.50;
    
    printf("re: %.2f \t im: %.2f", a[0].re, a[0].im);
    
    // 2 instances
    complex b[2];
    
    // pointer with 2 elements
    // points to the address of b[0] and b[1]
    complex *p_b[2] = {&b[0], &b[1]};
    
    // call the function
    functionName(&p_b[0]);
    return 0;
}

// function that recieves pointerarray
// it will recieve an array of structures
// of type complex
int functionName(complex *p_struct[])
{
    unsigned char j;
    
    for(j = 0; j < 2; j++)
    {
        p_struct[j] -> re = 1.25;
        p_struct[j] -> im = 2.50;
    }
}