// NOTES: In this program we find the largest value
// of an array using pointers
#include <stdio.h>
#include <conio.h>

// this macro defines array size
#define max 100

int main()
{
    int p[max], i, n, *ptr, *mx;
    
    // number of elements in array
    scanf("%d", &n);
    
    // get number of elements
    printf("Enter %d elements\n", n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    
    // the two pointers point to the first
    // element of the array
    mx = p;
    ptr = p;
    
    for(i = 1; i < n; i++)
    {
        if(*mx < *ptr)
        {
            mx = ptr;
        }
        
        ptr++;
    }
    printf("Largest value is %d\n", *mx);
    
    return 0;
}