//NOTES: Switch Case Based State Machines are
// easier to implement but using function
// pointers provide for more efficiency
// and simplicity because its easy
// to add and remove function without
// changing all the case statements

// A statemachine stores the status of
// something at any given time

// to avoid corruped ram when using on
// an embedded device its best to place
// the function pointers in program memory
// to improve robustness
#include <stdio.h>
#include <conio.h>

//brief An enumeration of all System States for plain-language reference in source code.
typedef enum
{
    STATE0 = 0,
    STATE1,
    STATE2
} SYSTEM_STATE;

SYSTEM_STATE gSystemState;


//These functions are called indirectly through a function pointer.  They are passed a
// value by the RunStateMachine function and return either the InputBits value that is
// passed to it or a literal value.  Each function also increments the state machine.
unsigned int function1(unsigned int InputBits, SYSTEM_STATE *State)
{
    (*State)++;
    
    if(InputBits == 0 && *State > 1)
        return InputBits;
    else
        return 99;
}


unsigned int function2(unsigned int InputBits, SYSTEM_STATE *State)
{
    (*State)++;
    
    if(InputBits == 2 && *State > 1)
        return InputBits * InputBits;
    else
        return 88;
}


unsigned int function3(unsigned int InputBits, SYSTEM_STATE *State)
{
    (*State)++;
    
    if(InputBits == 0 && *State > 1)
        return InputBits * InputBits * InputBits;
    else
        return 77;
}




/* Array of function pointers to functions of form
 * 'unsigned (int fName[ ])(unsigned int, *SYSTEM_STATE)'.
 * All functions implementing state logic must have a definition of this form. */
unsigned int (* pStateFunction[])(unsigned int InputBits, SYSTEM_STATE *State) =
{
    function1,
    function2,
    function3
};


//Function that is called to run the state machine.  It is called by the main( ) program
// and it calls the proper function based on the State variable.
unsigned int RunStateMachine(unsigned int InputBits)
{
    return (*pStateFunction[ gSystemState ])(InputBits, &gSystemState);
}


void main(void)
{
    volatile unsigned int result1;
    volatile unsigned int result2;
    volatile unsigned int result3;
    
    
    while(1)
    {
        gSystemState = STATE0;
        result1 = RunStateMachine(1);
        
        
        //gSystemState should be incremented by function
        result2 = RunStateMachine(2);
        
        
        //gSystemState should be incremented by function
        result3 = RunStateMachine(3);
        
    }
}