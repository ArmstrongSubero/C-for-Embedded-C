//NOTE:In C array's are bound ot pointers. Array
// notation is a form of pointer notation. The name
// of the array is the starting address of the array
// in memory

// when using pointers arr[i] can b written *(arr+i)
// we can write ptr = &arr[0]
#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printf("\n Address of array = %p %p %p", arr, &arr[0], &arr);
    
    // ptr is mad to point to the first element in the array
    int *ptr = &arr[0];
    
    // since the ptr variable holds thr address of the first
    // element in the array then successive elements can
    // be calculated by writing ptr++
    ptr++;
    
    printf("\n Value of second element is %d", *ptr);
    return 0;
}