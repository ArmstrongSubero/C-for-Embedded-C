//NOTES: Double pointers are important
// because they provide us a way to have
// pointers to pointers
// in the ARM CMSIS library header files
// these are popular
#include <stdio.h>
#include <conio.h>

int main()
{
    // declare a variable and set it to value 10
    int x = 10;
    
    // pointer that points to the address of x
    int *p = &x;
    
    // double pointers have two asterisks in front
    // pp points to the address of p
    int **pp = &p;
    
    // get the address of x
    // *pp == 8(&p) == p(address of x)
    printf("Address: %d\n", *pp);
    
    // get the value of x
    // **pp == *(*p) == *(p) == 10
    printf("Value: %d", **pp);
    return 0;
}