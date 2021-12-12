//NOTES: In this program we use a pointer to
// reverse a string
#include <stdio.h>
#include <conio.h>

int main()
{
    char str[255], *ptr1, *ptr2, temp;
    int n, m;
    
    
    // enter a string and
    // assign to string var
    printf("Enter a string: ");
    scanf("%s", str);
    
    // set a pointer to point to the string
    // will point to memory address of string's
    // first character
    ptr1 = str;
    
    // find the lenght of the string by
    // initializing n to 1 and a while
    // loop to execute when the pointer
    // reaches the null character of the string
    n = 1;
    
    while(*ptr1 != '\0')
    {
        // when the pointer moves one character
        // forward, the value of n is
        // incremented by 1
        ptr1++;
        n++;
    }
    
    // move one step back from null to
    // the last character of the string
    ptr1--;
    
    // set another pointer to point to the
    // beginning of the string
    ptr2 = str;
    
    // exchange the characters equal to half the
    // length of the string.
    m = 1;
    while(m <= n/2)
    {
        // the characters pointed to by the pointers
        // are exchanged
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        
        // after set the second pointer to move forward 
        // to point to its next character, the second 
        // character of the string and move the first pointer 
        // backward to make it point at the second to last character 
        ptr1--;
        ptr2++;
        m++;
    }
    
    printf("Reverse string is %s", str);
    return 0;
}