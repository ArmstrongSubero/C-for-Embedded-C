//Notes:This program allows you to add
// two two integers using pointers and functions

#include <stdio.h>
#include <conio.h>

void sum(int*, int*, int*);

int main()
{
    int num1, num2, total;
    num1 = 10;
    num2 = 20;
    
    sum(&num1, &num2, &total);
    printf("Total: %d\n", total);
    return 0;
}

void sum(int *a, int *b, int *t)
{
    *t = *a + *b;
}