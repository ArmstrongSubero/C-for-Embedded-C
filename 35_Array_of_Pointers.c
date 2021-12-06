//NOTES: Sometimes we need an array of pointers 
// this is how we can create it 
#include <stdio.h>
#include <conio.h>

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    
    // integer pointer array
    // used to store memory addresses
    // either of elements within the a array
    // or memory addresses of other arrays
    int * p[5];
    
    // we can use a loop to do this
    for(int i = 0; i < 5; i++)
    {
        //p[i] = &a[i]; or
        *(p+i) = a + i;
    }
    
    for(int x = 0; x < 5; x++)
    {
        // print the address and values
        printf("%d \t %d \n", p[x], *p[x]);
    }
    
    return 0;
}