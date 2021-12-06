//Notes: A void pointer or a generic pointer is a special
// type of pointer that can point to variables of any
// data type.
// Since you can't have a variable of type void, it will
// not point to any data and cant be deferenced
// generic pointers are used to point to data of different
// types at different times

// these should not be used unless absolutely necessary 
// as they allow you to avoid type checking
#include <stdio.h>
#include <conio.h>

int main()
{
    int x = 10;
    char ch = 'A';
    
    void *gp;
    gp = &x;
    
    printf("\nGP points to the int value = %d", *(int*)gp);
    
    gp = &ch;
    printf("\nGP now points to the char %c", *(char*)gp);
    
    return 0;
}