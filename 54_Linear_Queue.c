#include <stdio.h>
#include <conio.h>

// this value controls array length
#define MAX 10

int queue[MAX];

int front = -1;
int rear = -1;

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
    int option, val;
    
    do
    {
        printf("\n\n ** Main Menu **");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. Exit");
        
        printf("\n Enter your option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                insert();
                break;
            case 2:
                val = delete_element();
                if(val != -1)
                {
                    printf("\n The number deleted is: %d", val);
                }
                break;
            case 3:
                val = peek();
                if(val != -1)
                {
                    printf("\nThe first value in the queue is: %d", val);
                }
                break;
            case 4:
                display();
                break;
        }
    }
    while(option != 5);
    getch();
    return 0;
}

void insert(void)
{
    int num;
    printf("\n Enter the number to be inserted in the queue: ");
    scanf("%d", &num);
    
    if(rear == MAX - 1)
    {
        printf("\n Overflow");
    }
    
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    
    else
    {
        rear++;
    }
    
    queue[rear] = num;
}

int delete_element()
{
    int val;
    
    if(front == -1 || front > rear)
    {
        printf("\n Underflow");
        return -1;
    }
    
    else
    {
        val = queue[front];
        front++;
        
        if(front > rear)
        {
            front = rear = -1;
            return val;
        }
    }
}

int peek(void)
{
    if(front == -1 || front > rear)
    {
        printf("\n Queue is empty");
        return -1;
    }
    
    else
    {
        return queue[front];
    }
}

void display()
{
    int i;
    
    printf("\n");
    
    if(front == -1 || front > rear)
    {
        printf("\n Queue is empty");
    }
    else
    {
        for(i = front; i <= rear; i++)
        {
            printf("\t %d", queue[i]);
        }
        
    }
}