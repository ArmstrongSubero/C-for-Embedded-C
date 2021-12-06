//NOTES:Function pointers allow us to call
// functions more flexibly and makes it
// possible to pass function addresses to
// other functions

// function pointers can only return up
// to one value but can have multiple
// parameters
#include <stdio.h>
#include <conio.h>

// variables
int x, y;

// function prototypes
int add(int a, int b);
int sub(int a, int b);

// fucntion definition with function
// pointer parameters
int foobar(int a, int b, int(*fp)(int, int))
{
    return fp(a, b);
}


int main()
{
    x = foobar(5, 12, &add);
    y = foobar(5, 12, &sub);
    
    printf("add: %d \t sub: %d", x, y);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}