//NOTE: In a double buffer system the back buffer
// is filled with information while the
// front buffer is displayed
// when the back buffer is finished updating
// the whole buffer or just the updated part is
// transferred to the front buffer
// here the buffer swap is given since filling options
// and transferring operations may differ by
// device

#include <stdio.h>
#include <conio.h>
#include <string.h>

int buf1[] = {1, 1, 1, 1, 1};
int buf2[] = {1, 0, 2, 0, 1};


void swapBuffer(int * sourceBuf, int * destBuf, int size)
{
    // Pointer to last element of source array
    int * sourceBufEnd = (sourceBuf + (size - 1));
    
    // Pointer to last element of destination array
    int * destBufEnd   = (destBuf + (size - 1));
    
    int temp = 0;
    
    
    // Swap individual element of both arrays
    // XOR swap is slower, using temp variable
    while(sourceBuf <= sourceBufEnd && destBuf <= destBufEnd)
    {
        temp = *sourceBuf;
        *sourceBuf = *destBuf;
        *destBuf  = temp;
        
        // Increment source array to point to next element
        sourceBuf++;
        
        // Increment destination array to point to next element
        destBuf++;
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        printf("%d", buf1[i]);
    }
    printf("\n");
    
    swapBuffer(buf1, buf2, 5);
    
    for(int i = 0; i < 5; i++)
    {
        printf("%d", buf1[i]);
    }
    
    
    return 0;
}