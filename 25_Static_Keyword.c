//NOTES:The static keyword cane be used to keep the
// scope of a variable confined only in the file
// in which it is declared
// static can also be used to allow a variable to
// keep its value between invocations
// that is what will be examined in this program
#include <stdio.h>
#include <conio.h>


void demo_func()
{
    // regular variable
    int x = 10;
    
    // static variable statx
    static int statx = 10;
    
    x += 5;
    statx += 5;
    
    printf("x = %d  statx = %d\n", x, statx);
}

int main()
{
    int i;
    
    for(i = 0; i < 10; i++)
    {
        demo_func();
    }
    
    return 0;
}