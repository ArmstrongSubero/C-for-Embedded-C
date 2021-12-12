//NOTES: In a simple linked list there is
// one address in each node and the
// address points to the next node
// item navigation is forward only
// in this implementation we look at a
// linked list with dynamic memory allocation

// note in embedded systems more flash memory
// is required to use malloc and free

// if used in an embedded system remeber
// you may need to allocate heap memory
// using your ide
//
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
// simple linked list node
// a simple linked list node can be
// represented as a stuct with 2 members

struct Node
{
    // a data integer
    int data;

    // points to type node structues
    struct Node* next;

};
*/

/*
// actual implementation
struct DataList
{
    // node value
    int dataListValue;

    // pointer to next node
    struct DataList* nextNode;
};
*/

// creates the node structure for each element
// in the linked list
struct Node
{
    int val;
    struct Node *nextPtr;
};


// create two pointers that will be used
// to search the linked list and add or
// delete nodes
struct Node *currentPointer;
struct Node *previousPointer;

// create a variable that will be used
// as a flag to denot that the search
// found a node that we were looking for
int nodeFound;

// we also have a function prototype to
// print the linked list
void printList(struct Node *head);

int main()
{
    // define a pointer to the first item in the list
    // and initialize it to be null
    struct Node* headNode = NULL;
    
    // then we create instances of other nodes in the
    // linked list these are not necessary
    // but illustate the concept
    struct Node* secondNode = NULL;
    struct Node* thirdNode = NULL;
    
    // this is used to manipulate items in the list
    struct Node* newNode = NULL;
    
    // allocate memory for the first item and save it
    // as the "head" value
    headNode = (struct Node*)malloc(sizeof(struct Node));
    
    // allocate memory for other nodes in the heap
    secondNode = (struct Node*)malloc(sizeof(struct Node));
    thirdNode = (struct Node*)malloc(sizeof(struct Node));
    
    // initialize all nodes
    // and how they point
    headNode -> val = 2;
    headNode -> nextPtr = secondNode;
    
    secondNode -> val = 3;
    secondNode -> nextPtr = thirdNode;
    
    thirdNode -> val = 5;
    thirdNode -> nextPtr = NULL;
    
    // create a new node with value 4
    // it is not places in the list yet
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> val = 4;
    
    // add the node in numerical order in the
    // linked list and initialize the
    // node pointer
    currentPointer = headNode;
    previousPointer = headNode;
    nodeFound = 0;
    
    printf("List: ");
    // print the list
    printList(headNode);
    printf("\n");
    
    /*****************
     * Add Item to list
     * ******************/
    // use while loop to search though link list
    // we want to insert the newnode into the
    // list so that its value is in numerical
    // order with the other nodes in the
    // linked list
    
    // loop though until we find lst value
    while(previousPointer -> nextPtr != NULL)
    {
        if((currentPointer -> val) > (newNode -> val))
        {
            // set flag
            nodeFound = 1;
            
            
            newNode -> nextPtr = currentPointer;
            
            // insert new node between the
            // current pointer and previous pointer
            if(currentPointer != headNode)
            {
                previousPointer -> nextPtr = newNode;
            }
            
            // if the current pointer is the heead node
            // the new node becomes the head of the
            // linked list
            else
            {
                headNode = newNode;
            }
            
            break;
        }
        
        // we set the previous pointer to the current pointer
        previousPointer = currentPointer;
        
        // we set the current pointer equal to the
        // node that was pointed to
        currentPointer = currentPointer -> nextPtr;
        
    }
    
    // if no node was found we make out previous
    // pointer point to the new node
    if(!nodeFound)
    {
        // and make the new node point to NULL
        // because it is at the end of tthe list
        previousPointer -> nextPtr = newNode;
        newNode -> nextPtr = NULL;
        nodeFound = 0;
    }
    
    nodeFound = 0;
    
    printf("After Insert:\n");
    printList(headNode);
    printf("\n");
    
    /*****************
    * Delete Item to list
    * *******************/
    // delete item with value of 3
    
    // iniialize the node pointer
    // both pointers are pointing to head node
    currentPointer = headNode;
    previousPointer = headNode;
    
    // run while loop as long as we are not
    // at the last loop in the list
    while(previousPointer -> nextPtr != NULL)
    {
        // if value is 3
        if((currentPointer -> val) == 3)
        {
            // if it is headnode we delete it
            if(currentPointer == headNode)
            {
                headNode = currentPointer -> nextPtr;
            }
            
            // if its not the head node
            // we check to see if its the
            // last node in the list
            else if(currentPointer -> nextPtr == NULL)
            {
                previousPointer -> nextPtr = NULL;
            }
            
            // otherwise skip over current pointer
            // because we are going to delete it
            else
            {
                previousPointer -> nextPtr = currentPointer -> nextPtr;
            }
            
            // free memory for curren pointer
            free(currentPointer);
            break;
        }
        
        // happens every time we go over the
        // linked list
        previousPointer = currentPointer;
        currentPointer = currentPointer -> nextPtr;
    }
    
    printf("After deletion: \n");
    printList(headNode);
    return 0;
}

void printList(struct Node *head)
{
    struct Node *tmp = head;
    
    while(tmp != NULL)
    {
        if(tmp->nextPtr == NULL)
        {
            printf("%d", tmp->val);
        }
        
        else
        {
            printf("%d, ", tmp->val);
        }
        
        tmp = tmp->nextPtr;
    }
}