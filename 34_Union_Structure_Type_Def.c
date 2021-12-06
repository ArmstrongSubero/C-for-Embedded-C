//NOTES: Using pointers to structues of structures
// or to structures of unions we can keep
// all functionality together and include
// functionality subsets
#include <stdio.h>
#include <conio.h>

// LED_ROTATE_Type Typedef
typedef union
{
    unsigned long reg;
    
    struct
    {
        unsigned char uBrotateForwardSpeed;
        unsigned char uBrotateReverseSpeed;
        unsigned char uBspeedRateChange;
        unsigned char b1rotateStatusFlags: 2;
    } member;
} LED_ROTATE_Type;

// LED_BREATHE_Type Typedef
typedef union
{
    unsigned long reg;
    
    struct
    {
        unsigned short u16pwmLightIntensity;
        unsigned short u16breateSpeed;
    } member;
} LED_BREATHE_Type;

// LED_PATTERN_Type Typedef
typedef union
{
    unsigned long reg;
    struct
    {
        unsigned char u8pattern[4];
    }
} LED_PATTERN_Type;

// include the three unions in one structure
// one super structure
typedef struct
{
    volatile LED_ROTATE_Type ledRotation;
    volatile LED_PATTERN_Type ledPattern;
    volatile LED_BREATHE_Type ledBreathe;
    
} STRUCT_LEDVariables;

int main()
{
    // create an instance of the super
    // structure that holds the unions
    // of structures
    
    // declare all variables by declaring
    // the variable for the
    // STRUCT_LEDVariables union
    // the instance of the structure is
    // called STRUCT_allLEDVariables
    STRUCT_LEDVariables STRUCT_allLEDVariables;
    
    // declare a pointer to the structure
    // STRUCT_LEDVariables is the typename of the structure
    // *pSTRUCT_LEDVariables is the name of the pointer
    // &STRUCT_allLEDVariables initializes the pointer to
    // point to the address of struct all LED variables
    STRUCT_LEDVariables *pSTRUCT_LEDVariables = &STRUCT_allLEDVariables;
    
    // for example in an embedded system we can do
    // Write to full 32-bit value of the ledRotation variable
    //pStruct_LEDVariables -> ledRotation.reg = 0xABCDECFF;
    
    // Write to one member of the ledRotation variable
    //pStruct_LEDVariables -> ledRotation.member.u8roateForwardSpeed = 0x11;
    
    return 0;
}