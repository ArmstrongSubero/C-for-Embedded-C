//NOTES: We can modify the contents of an array using a pointer to
// an array

// arr[i], *(arr+i), *(i+arr) all give the same value
#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr, i;
    ptr = &arr[2];
    
    *ptr = -1;
    *(ptr + 1) = 0;
    *(ptr - 1) = 1;
    
    printf("\n Array is: ");
    
    for(i = 0; i < 5; i++)
    {
        printf(" %d", *(arr + i));
    }
    return 0;
}