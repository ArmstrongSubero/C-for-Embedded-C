//NOTES:
//  Can create a 2 dim array with int arr[3][5]
//  [][][][][]\
//  [][][][][] |  First Dimension 3 rows
//  [][][][][]/
//  \-----/ \
//  Second Dimension 5 columns
#include <stdio.h>
#include <conio.h>

int main()
{
    // you can create a 2 dimensional array
    int marks[2][3] = {90, 87, 78, 68, 62, 61};
    
    // this can also be written as
    // int marks [2][3] = {{90, 87, 78}, {68, 62, 71}};
    
    
    // we can access the elements of a 2D array
    int arr[2][2] = {12, 34, 56, 32};
    int i, j;
    
    for(i = 0; i < 2; i++)
    {
        printf("\n");
        
        for(j = 0; j < 2; j++)
        {
            printf("%d\t", arr[i][j]);
        }
    }
    
    return 0;
}