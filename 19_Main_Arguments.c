//NOTES: We can pass arguemnts into main 
// you can call like 
// Program_name first second "this is third" 
#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[])
{
    printf("Program name %s\n", argv[0]);
    
    for(int i = 1; i < argc; ++i)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    
    return 0;
}