//NOTES: This program creates a list based stack
// machine and does push, pop and peek operations
#include <stdio.h>
#include <conio.h>


struct stack
{
    int data;
    struct stack *next;
    
};

struct stack *top = NULL;
struct stack *push(struct stack*, int);
struct stack *display(struct stack*);
struct stack *pop(struct stack *);
int peek(struct stack*);

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
                top = push(top, val);
                break;
                
            case 2:
                top = pop(top);
                if(val != -1)
                {
                    printf("\n Value deleted from stack is: %d", val);
                }
                break;
            case 3:
                val = peek(top);
                if(val != -1)
                {
                    printf("\n Value stored at top is %d", val);
                    break;
                }
            case 4:
                top = display(top);
                break;
                
        }
    }
    
    while(option != 5);
    return 0;
}

struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    
    ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr -> data = val;
    
    if(top == NULL)
    {
        ptr -> next = NULL;
        top = ptr;
    }
    
    else
    {
        ptr -> next = top;
        top = ptr;
    }
    
    return top;
}

struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    
    if(top == NULL)
    {
        printf("\n Stack is Empty");
        
    }
    
    else
    {
        while(ptr != NULL)
        {
            printf("\n %d", ptr -> data);
            ptr = ptr -> next;
        }
    }
    
    return top;
}

struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    
    if(top == NULL)
    {
        printf("\n Stack Underflow");
        
    }
    
    else
    {
        top = top -> next;
        printf("\n The value being deleted is: %d", ptr -> data);
        free(ptr);
    }
    
    return top;
}

int peek(struct stack *top)
{
    if(top == NULL)
    {
        return -1;
    }
    
    else
    {
        return top -> data;
    }
}