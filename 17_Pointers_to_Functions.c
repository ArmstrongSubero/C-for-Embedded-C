#include <stdio.h>
#include <conio.h>

// function prototypes
int sum(int, int);
int product(int, int);
int difference(int, int);

int main()
{
    // value for a
    int a = 10;
    
    // value for b
    int b = 5;
    
    // result
    int result = 0;
    
    // function pointer
    int(*pfun)(int, int);
    
    pfun = sum;
    result = pfun(a, b);
    
    printf("pfun = sum result = %2d\n", result);
    
    
    pfun = product;
    result = pfun(a, b);
    
    printf("pfun = product result = %2d\n", result);
    
    
    pfun = difference;
    result = pfun(a, b);
    
    printf("pfun = difference result = %2d\n", result);
    
    
    
    return 0;
}

int sum(int x, int y)
{
    return x + y;
}

int product(int x, int y)
{
    return x * y;
}

int difference(int x, int y)
{
    return x - y;
}