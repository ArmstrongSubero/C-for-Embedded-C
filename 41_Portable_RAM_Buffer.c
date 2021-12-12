#include <stdio.h>
//NOTES:This function shows embedded code
// portability using a RAM buffer
// we access two ram buffers with the
// exact same interface
#include <conio.h>

//Variable declarations
unsigned short u16buffer1[16];
unsigned short u16buffer2[16];
unsigned short u16dataBufferRead;


//Two 16-bit buffers will be accessed.  The names are BUFFER1 and BUFFER2.  There
// are three functions for each buffer.  The _Initialize function will load 16
// values into the buffer.  All values are the same and are defined by u16bufferFill.
// The second function will read one location of the buffer.  The third function will
// write one location of the buffer.

//Write 16 integer values to BUFFER1 as defined by u16bufferFill
void BUFFER1_Initialize(unsigned short u16bufferFill)
{
    unsigned char i;
    
    for(i = 0; i <= 15; i++)
    {
        u16buffer1[i] = u16bufferFill;
    }
}


//Read one 16-bit value from BUFFER1 at the address specified by u8index
unsigned short BUFFER1_Read(unsigned char u8index)
{
    return u16buffer1[u8index];
}


//Write one 16-bit value to BUFFER1 at the address specified by u8index
void BUFFER1_Write(unsigned char u8index, unsigned short u16value)
{
    u16buffer1[u8index] = u16value;
}


//Write 16 integer values to BUFFER2 as defined by u16bufferFill
void BUFFER2_Initialize(unsigned short u16bufferFill)
{
    unsigned char i;
    
    for(i = 0; i <= 15; i++)
    {
        u16buffer2[i] = u16bufferFill;
    }
}


//Read one 16-bit value from BUFFER2 at the address specified by u8index
unsigned short BUFFER2_Read(unsigned char u8index)
{
    return u16buffer2[u8index];
}


//Write one 16-bit value to BUFFER2 at the address specified by u8index
void BUFFER2_Write(unsigned char u8index, unsigned short u16value)
{
    u16buffer2[u8index] = u16value;
}



//Enumeration for two different buffers.  This enumeration will be used to select
// which buffer to access
enum { BUFFER1, BUFFER2} buffer_configurations_t;


//Create three function pointers within a typedef structure.  These three function pointers
// will initialize, read, and write the two buffers.  The *DataInit pointer performs
// the buffer initialization.  The *DataWrite pointer writes to the buffer.  The *DataRead
// pointer reads the buffer.
typedef struct
{
    void (*DataInit)(unsigned short bufferFill);
    void (*DataWrite)(unsigned char index, unsigned short value);
    unsigned short(*DataRead)(unsigned char index);
} buffer_functions_t;


//The buffer_access[ ] array contains the addresses for both of the buffer
// initialize, read and write functions.  This array is placed in flash but could
// be placed in RAM instead.

// Line 1 accesses BUFFER1 and line 2 accesses BUFFER2.
// Each line has the addresses for each function (initialize, read, write).

//The BUFFER1_Initialize address corresponds to the *DataInit function pointer.
//The BUFFER1_WRITE address corresponds to the *DataWrite function pointer.
//The BUFFER1_READ address corresponds to the *DataRead function pointer.
const buffer_functions_t buffer_access[] =
{
    {BUFFER1_Initialize, BUFFER1_Write, BUFFER1_Read },
    {BUFFER2_Initialize, BUFFER2_Write, BUFFER2_Read }
};


//Main function
int main(void)
{
    //Initialize both buffers
    buffer_access[BUFFER1].DataInit(0x55);
    buffer_access[BUFFER2].DataInit(0xAA);
    
    while(1)
    {
        //Access the functions for each buffer using the buffer_access[ ] array
        buffer_access[BUFFER1].DataWrite(4, 0x1234);
        u16dataBufferRead = buffer_access[BUFFER1].DataRead(4);
        
        buffer_access[BUFFER2].DataWrite(8, 0x9876);
        u16dataBufferRead = buffer_access[BUFFER2].DataRead(8);
        
        printf("%d", u16dataBufferRead);
        
        while(1);
        
    }
}




