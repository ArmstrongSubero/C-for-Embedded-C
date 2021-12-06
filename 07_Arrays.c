// Notes:An array in C is a data structure containing a
// collection of similar of similar data elements
// it is used to create other data structures and
// algorithms in C
#include <stdio.h>
#include <conio.h>

int main()
{
    // create an array and set all elements to 1
    int i;
    int marks[10];
    
    for(i = 0; i < 10; i++)
    {
        marks[i] = 1;
    }
    
    // iterate over the array
    int arrlen = sizeof(marks)/sizeof(int);
    
    for(i = 0; i < arrlen; i++)
    {
        printf("%d\n", marks[i]);
    }
    
    // copy the array
    int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[10];
    
    for(i = 0; i < 10; i++)
    {
        arr2[i] = arr1[i + 1];
    }
    
    for(i = 0; i < arrlen; i++)
    {
        printf("%d\n", arr2[i]);
    }
    
    // fill an array with even numbers
    int arr[10];
    
    for(i = 0; i < 10; i++)
    {
        arr[i] = i*2;
    }
    
    
    return 0;
}