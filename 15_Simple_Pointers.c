#include <stdio.h>
#include <conio.h>

int main()
{
    // a variable type int initialize to 0
    int number = 0;
    
    // a pointer that points to type int
    int *pnumber = NULL;
    
    number = 10;
    
    // output the address
    printf("Number's address: %d\n", &number);
    
    // output the value
    printf("number's value: %d\n\n", number);
    
    // store the address of number in pnunber
    pnumber = &number;
    
    // output address
    printf("pnumber's address: %p\n", (void*)&pnumber);
    
    printf("pnumber's size: %zd bytes\n", sizeof(pnumber));
    
    printf("pnumber's value: %p\n", pnumber);
    printf("value pointed to: %d\n", *pnumber);
    
    
    return 0;
}