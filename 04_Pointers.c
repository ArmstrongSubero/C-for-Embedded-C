//Notes: Pointers are used to pass information back and forth
// between functions
// they enable the return of multiple data items from a
// function via function arguments
// they also allow us ways to work with arrays and are
// used to create complex data structures and dynamic
// memory allocation

// general syntax of a pointer is
// data_type *ptr_name;
// eg
// int *pnum;
// char *pch;
// float *pfnum;

// take this example
// int x = 10; this is a regular assignment

// int *ptr; in this ptr is the name of a pointer
// variable and the * informs the compiler that
// ptr sis a pointer variable

// ptr = &x; in this case ptr is assigned the
// address of x. The & operator retrieves the addess of x
// called the lvalue and copies that into the contents
// of ptr.

// *ptr; in this we can dereference a pointer
// (the value of the variable to which it points) by using
// the unary * operator as in *ptr
// so in this case *ptr = 10

// *(&x) is equivalent to writing just x

// a null pointer does not point to any value
// which means it does not point to any valid
// memory address
// int *ptr = NULL;

#include <stdio.h>
#include <conio.h>

int main()
{
    // basic pointer
    int num, *pnum;
    pnum = &num;
    
    printf("\n Enter the number: ");
    //scanf("%d", &num);
    
    *pnum = 10;
    
    printf("\n The number that was entered is %d\n", *pnum);
    
    // pointer arithmetic
    int num1 = 2;
    int num2 = 3;
    int sum = 0;
    int mul = 0;
    int div = 1;
    
    int *ptr1, *ptr2;
    
    ptr1 = &num1;
    ptr2 = &num2;
    
    printf("%d %d\n", *ptr1, *ptr2);
    
    sum = *ptr1 + *ptr2;
    mul = sum * (*ptr1);
    
    printf("Sum: %d Mul: %d\n", sum, mul);
    
    *ptr2 += 1;
    printf("Ptr2: %d\n", *ptr2);
    
    div = 9 + (*ptr1)/(*ptr2) - 30;
    printf("Div: %d", div);
    
    
    return 0;
}