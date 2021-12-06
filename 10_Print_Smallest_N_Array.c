#include <stdio.h>
#include <conio.h>

int main()
{
    int i, n, arr[20], small, pos;
    
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("\nEnter the elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    small = arr[0];
    pos = 0;
    
    for(i = 1; i < n; i++)
    {
        if(arr[i] < small)
        {
            small = arr[i];
            pos = i;
        }
        
    }
    
    printf("\nThe smalles element is: %d", small);
    printf("\nPos of smallest element: %d", pos);
    return 0;
}