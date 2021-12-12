//NOTES: This program creates an array based stack
// machine and does push, pop and peek operations
#include <stdio.h>
#include <conio.h>

// this value controls the size
// of the stack
# define MAX 3

int st[MAX], top = -1;

void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main()
{
    int val, option;
    
    do
    {
        printf("\n *** Main Menu ***");
        printf("\n. 1. Push");
        printf("\n. 2. Pop");
        printf("\n. 3. Peek");
        printf("\n. 4. Display");
        printf("\n. 5. Exit");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("Enter value to be pushed on stack: ");
                scanf("%d", &val);
                push(st, val);
                break;
                
            case 2:
                val = pop(st);
                if(val != -1)
                {
                    printf("\n Value deleted from stack is: %d", val);
                }
                break;
            case 3:
                val = peek(st);
                if(val != -1)
                {
                    printf("\n Value stored at top is %d", val);
                    break;
                }
            case 4:
                display(st);
                break;
                
        }
    }
    
    while(option != 5);
    return 0;
}

void push(int st[], int val)
{
    if(top == MAX - 1)
    {
        printf("\n Stack Overflow");
    }
    
    else
    {
        top ++;
        st[top] = val;
    }
}

int pop(int st[])
{
    int val;
    
    if(top == -1)
    {
        printf("\n Stack Underflow");
        return -1;
    }
    
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

void display(int st[])
{
    int i;
    
    if(top == -1)
    {
        printf("\n Stack is empty");
    }
    
    else
    {
        for(i = top; i >= 0; i--)
        {
            printf("\n %d", st[i]);
            
            // added for formatting
            printf("\n");
        }
    }
}

int peek(int st[])
{
    if(top == -1)
    {
        printf("\n Stack is empty");
        return -1;
    }
    
    else
    {
        return (st[top]);
    }
}
