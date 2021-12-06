#include <stdio.h>
#include <conio.h>

int main()
{
    int i, n, pos, arr[10];
    
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter postion from which number has to be deleted: ");
    scanf("%d", &pos);
    
    for(i = pos; i < n-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    n--;
    
    printf("\nThe array after deletion is: ");
    
    for(i = 0; i < n; i++)
    {
        printf("\n arr[%d] = %d", i, arr[i]);
    }
    
    getch();
    
    return 0;
}