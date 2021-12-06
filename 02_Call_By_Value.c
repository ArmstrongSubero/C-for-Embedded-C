// Notes: When functions are called by value, the function
// creates a new variable of the same data type as the
// arguments passed to it and the values of the arguments
// are copied into the newly created variables
// values of the variables in the calling functions remain
// unaffected will call-by-value
// call by value uses additional storage space and takes time
// to copy resulting in a performance penalty 

#include <stdio.h>
#include <conio.h>

void add(int n);

int main()
{
    int num = 2;
    
    printf("\n The value before calling function = %d", num);
    add(num);
    
    printf("\n Value after calling the function = %d", num);
    
    return 0;
}

void add(int n)
{
    n = n + 10;
    
    printf("\n The value of num in function = %d", n);
}