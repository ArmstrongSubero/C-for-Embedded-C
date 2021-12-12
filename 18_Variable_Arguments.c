#include <stdio.h>
#include <conio.h>
#include <stdarg.h>

double average(double v1, double v2, ...);

int main()
{
    double v1 = 10.5, v2 = 2.5;
    
    int num1 = 6, num2 = 5;
    long num3 = 12L, num4 = 20L;
    
    printf("average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0.0));
    printf("average = %.2lf\n", average(v1, 1.0, 2.0, 0.0));
    printf("average = %.2lf\n", average((double)num2, v2, (double) num1, (double) num4, (double)num3, 0.0));
    return 0;
}


// function to calculate average of two of more arguments
double average(double v1, double v2, ...)
{
    // pointer for variable arguemtn list
    va_list parg;
    
    // acumulate sum of arguments
    double sum = v1 + v2;
    
    // arguemnt value
    double value = 0.0;
    
    // count number of arguments
    int count = 2;
    
    // initiialize argument pointer
    va_start(parg, v2);
    
    
    while((value = va_arg(parg, double)) != 0.0)
    {
        sum += value;
        ++count;
    }
    
    // end argument process
    va_end(parg);
    
    return sum / count;
}