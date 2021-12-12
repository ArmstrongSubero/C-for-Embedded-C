#include <stdio.h>
#include <conio.h>

int main()
{
    long num1 = 0L;
    long num2 = 0L;
    
    long *pnum = NULL;
    
    // get address of num1
    pnum = &num1;
    
    // set num1 to 2
    *pnum = 2L;
    
    // increment num2
    ++num2;
    
    // add num1 to num2
    num2 += *pnum;
    
    // get address of num 2
    pnum = &num2;
    
    // increment num2 indirectly
    ++*pnum;
    
    
    printf("num1 = %ld num2 = %ld *pnum = %ld *pnum + num2 = %ld\n",
           num1, num2, *pnum, *pnum + num2);
           
    return 0;
}