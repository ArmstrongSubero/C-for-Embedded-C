//NOTE:In a union the fields share the same memory
// space so new data replaces any existing data
// They are also collection of variables of
// different types but in a union you can
// only store infromation in one field at any time
#include <stdio.h>
#include <conio.h>

typedef struct POINT1
{
    int x, y;
};

typedef union POINT2
{
    int x;
    int y;
};

int main()
{
    struct POINT1 P1 = {2, 3};
    // POINT2 P2 = {4, 5} illegal to use in unions
    union POINT2 P2;
    P2.x = 4;
    P2.y = 5;
    
    printf("\n The cooridantes of P1 are %d %d", P1.x, P1.y);
    
    // will have the same output since memory is shared
    printf("\n The cooridantes of P2 are %d %d", P2.x, P2.y);
    
    // to get the same output we must do
    P2.x = 4;
    printf("\nThe x coordiante of P2 is %d", P2.x);
    
    P2.y = 5;
    printf("\n The y coordinate of P2 is %d", P2.y);
    
    return 0;
}