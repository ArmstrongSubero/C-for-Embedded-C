//Notes: Since arguments are not copied to the new
// variables it has greater time and space efficiency than
// a call by value and the function can change the
// value of the argument and the change is reflected in
// the calling function. A function can return only
// one value.
// A disadvantage is the original values could have been
// overwritten

#include <stdio.h>
#include <conio.h>

void add(int *);

int main()
{
    int num = 2;
    printf("\n The value of num before function = %d", num);
    
    add(&num);
    printf("\n The value of num after calling the function = %d", num);
    
    return 0;
}

void add(int *n)
{
    *n = *n + 10;
    printf("\n The value of num in the called function = %d", *n);
}