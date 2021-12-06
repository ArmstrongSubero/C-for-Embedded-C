#include <stdio.h>
#include <conio.h>

int main()
{
    int i, n, arr[20], large, second_large;
    
    // fill array with numbers
    printf("\nEnter the number of elements in array: ");
    scanf("%d", &n);
    
    printf("\nEnter the elements: ");
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // get the largest element in the array
    large = arr[0];
    
    for(i = 0; i < n; i++)
    {
        if(arr[i] > large)
        {
            large = arr[i];
        }
    }
    
    // once largest is found 
    // find the second largest element 
    second_large = arr[1];
    
    for(i = 0; i < n; i++)
    {
        if(arr[i] != large)
        {
            if(arr[i] > second_large)
            {
                second_large = arr[i];
            }
        }
    }
    
    printf("\n The numbers you entered are: ");
    
    for(i = 0; i < n; i++)
    {
        printf("\t %d", arr[i]);
    }
    
    printf("\nThe largest of these numbers is: %d", large);
    printf("\n THe second largest is: %d", second_large);
    
    return 0;
}