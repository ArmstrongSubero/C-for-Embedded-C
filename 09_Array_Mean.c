#include <stdio.h>
#include <conio.h>

int main()
{
    int i, n, arr[20], sum = 0;
    
    float mean = 0.0;
    
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    
    // intake numbers and fill the array
    for(i = 0; i < n; i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    // sum the elements of the array
    for(i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    // calculate the mean of the array
    mean = (float)sum / n;
    
    printf("\n The sum of the array = %d", sum);
    printf("\n The mean of the array = %.2f", mean);
    
    return 0;
}