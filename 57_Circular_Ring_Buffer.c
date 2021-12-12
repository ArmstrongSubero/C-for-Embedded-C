// NOTES: A Cricular or ring buffer is best suited for
// use as a FIFO structure while a non-circular buffer
// is well as a LIFO
#include <stdio.h>
#include <conio.h>

// constants
#define SIZE_OF_BUFFER 8
#define MAX_LENGTH_OF_STRING 81
#define SUCCESS 0
#define FAILURE -1
#define EXIT_LOOP 1


void displayMainMenu(void);
int getnumber(int * pnumber);

int main()
{
    // empty circular buffer
    int circularBuffer[SIZE_OF_BUFFER] = {0};
    
    // user input option
    int optionNumber = 0;
    
    // index of read pointer
    int readIndex = 0;
    
    // index of write pointer
    int writeIndex = 0;
    
    // number of values in circular buffer
    int bufferLength = 0;
    
    // loop condition variable
    int loopStatus = 0;
    
    while(loopStatus != EXIT_LOOP)
    {
        displayMainMenu();
        getNumber(&optionNumber);
        /* ---------------------------- OPTION 1 - WRITE --------------------------- */
        
        if(optionNumber == 1)
        {
            // Check if buffer is full
            if(bufferLength == SIZE_OF_BUFFER)
            {
                printf("\n    Buffer is full!\n\n    ");
                getchar();
                continue;
            }
            
            printf("\n    Please input an integer to store in the array\n\n    ");
            getNumber(&circularBuffer[writeIndex]);	 // Write number to address of buffer index
            
            bufferLength++;	 //	Increase buffer size after writing
            writeIndex++;	 //	Increase writeIndex position to prepare for next write
            
            // If at last index in buffer, set writeIndex back to 0
            if(writeIndex == SIZE_OF_BUFFER)
            {
                writeIndex = 0;
            }
        }
        
        /* ---------------------------- OPTION 2 - READ ---------------------------- */
        
        else if(optionNumber == 2)
        {
            // Check if buffer is empty
            if(bufferLength == 0)
            {
                printf("\n    Buffer is empty!\n\n    ");
                getchar();
                continue;
            }
            
            printf("\n    The output value is %d\n\n    ", circularBuffer[readIndex]);
            getchar();
            
            bufferLength--;	 //	Decrease buffer size after reading
            readIndex++;	 //	Increase readIndex position to prepare for next read
            
            // If at last index in buffer, set readIndex back to 0
            if(readIndex == SIZE_OF_BUFFER)
            {
                readIndex = 0;
            }
        }
        
        /* ---------------------------- OPTION 3 - EXIT ---------------------------- */
        
        else if(optionNumber == 3)
        {
            printf("\n    Thanks for using the circular buffer!\n\n");
            loopStatus = EXIT_LOOP;
            continue;
        }
        
        /* ----------------------------- INVALID OPTION ---------------------------- */
        
        else
        {
            printf("\n    Invalid option number!\n\n    ");
            getchar();
        }
    }
    
    
    return 0;
}

// Clears screen then displays main menu
void displayMainMenu(void)
{
    printf("\n======================= CIRCULAR BUFFER ======================\n\n");
    printf("    Please choose from the following options:\n\n");
    printf("        1    Input  Value\n");
    printf("        2    Output Value\n");
    printf("        3    Exit Program\n");
    printf("\n==============================================================\n\n    ");
}

// gets single integer as user input
int getNumber(int* pNumber)
{
    // An array of char to store the string
    char userInput[MAX_LENGTH_OF_STRING]	=	{ 0 };
    
    // Get user input
    fgets(userInput, MAX_LENGTH_OF_STRING, stdin);
    
    // Parse the user input for an integer and store it in the pNumber parameter
    if(sscanf(userInput, "%d", pNumber) != 1)
    {
        return FAILURE;
    }
    
    return SUCCESS;
}