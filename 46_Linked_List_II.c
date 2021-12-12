// NOTES: We create a linked list without
// dynamic memory allocation we don't
// need to set aside memory to allocate
// a heap
#include <stdio.h>
#include <conio.h>

// we add an additional byte to determine if
// a location is available
// when we create the node structure
// for each element in the linked list

// pragma pack(1) can be ommitted on
// microchip mcu device
#pragma pack(1)
struct Node
{
    // used to determine if location is
    // available
    short locationIsAvailable;
    
    // due to structure padding size of
    // a structure becomes more than the
    // size of the structure which causes
    // memory to get wasted
    int __attribute__((packed))val;
    struct __attribute__((packed))Node *nxtPtr;
};

struct Node *currentPointer;
struct Node *previousPointer;
struct Node *newNode;
struct Node *headNode;

#define TOTAL_NODES 25

int main()
{
    int i;
    // we use an array to allocate memory
    // reserve memory for 25 nodes
    // this array is only for memory allocation
    struct Node listReservedMemory[TOTAL_NODES];
    
    // create two pointers that will be used
    // to search the linked list and add
    // or delete nodes
    struct Node *currentPointer;
    struct Node *previousPointer;
    
    // create new node that will be used
    // to place data within the list
    struct Node *newNode;
    
    // create node designation for the
    // first node in the list
    struct Node *headNode;
    
    printf("Size of Packed Node struct: ");
    // print the size of node
    printf("%d", sizeof(struct Node));
    printf("\n");
    
    // variable for node found once we
    // search the linked list to find what
    // we are looking for
    short nodeFound;
    
    // establsit the link list search pointer
    // set to first element of the array
    currentPointer = &listReservedMemory[0];
    
    
    // initialize all list locations
    for(int i = 0; i < TOTAL_NODES; i++)
    {
        currentPointer -> locationIsAvailable = 1;
        currentPointer -> val = 0;
        currentPointer -> nxtPtr = NULL;
        currentPointer++;
    }
    
    //initialize some nodes to demonstrate the search
    currentPointer = &listReservedMemory[0];
    headNode = &listReservedMemory[0];
    
    headNode -> val = 2;
    headNode -> locationIsAvailable = 0;
    headNode -> nxtPtr = ++currentPointer;
    
    currentPointer -> val = 3;
    currentPointer -> locationIsAvailable = 0;
    currentPointer -> nxtPtr = ++currentPointer;
    
    currentPointer -> val = 5;
    currentPointer -> locationIsAvailable = 0;
    currentPointer -> nxtPtr = NULL;
    
    newNode = NULL;
    
    printf("Initial List: ");
    printList(headNode);
    printf("\n");
    
    
    //find the first unused location in the list to use as the newNode
    // Search through up to TOTAL_NODES of nodes and will always be located in the
    // allocated array memory
    currentPointer = &listReservedMemory[0];
    
    for(i = 0; i < TOTAL_NODES; i++)
    {
        if(currentPointer ->locationIsAvailable)
        {
            newNode = currentPointer;
            newNode -> locationIsAvailable = 0;
            break;
        }
        
        currentPointer++;
    }
    
    
    //only place the newNode if a valid pointer was returned from the search
    if(newNode != NULL)
    {
        //create a new node with a value of 4.  It is not placed in the list yet.
        newNode -> val = 4;
        
        
        //add the node in numerical order in the linked list.  Initialize the node pointers.
        currentPointer = headNode;
        previousPointer = headNode;
        nodeFound = 0;
        
        
        //step through the linked list and search for the position to place the newNode value of 4
        // so that the list stays in numerical order.
        
        //the algorithm looks at the value in the location of the currentPointer and compares it
        // to the value in newNode.  If it is less than the value, the iteration of this search stops.
        // previousPointer is set equal to currentPointer and currentPointer is set equal to the
        // location pointed to by the nextPtr value in that location.  So this algorithm just steps
        // through the list.  If the currentPointer value is greater than the newNode value, then the
        // newNode value will be placed before the currentPointer.  Since previousPointer points to the
        // location before the currentPointer, the nextPtr value of the previousPointer is set equal
        // to the newNode pointer.  The newNode pointer is set to point to the currentPointer location.
        
        //For every iteration of the loop, the previousPointer is set equal to the currentPointer and
        // the currentPointer is incremented.  So there are pointers to the current node and previous
        // node at all times.
        
        //If the value to be placed is less than the first location in the list, the newNode pointer
        // is set to be the headPointer.  If the value to be placed is greater than the last location,
        // this search will fall through without placing the node in the list.  nodeFound is used to
        // signify that a node was placed.  If this value is 0, then the previousPointer is set to point
        // to the newNode and the newNode pointer is set to NULL.
        while(previousPointer -> nxtPtr != NULL)
        {
            if((currentPointer -> val) > (newNode -> val))
            {
                nodeFound = 1;
                newNode -> nxtPtr = currentPointer;
                
                if(currentPointer != headNode)
                    previousPointer -> nxtPtr = newNode;
                    
                else
                    headNode = newNode;
                    
                break;
            }
            
            previousPointer = currentPointer;
            currentPointer = currentPointer -> nxtPtr;
        }
        
        //Check if a node was found.  If not, put the value at the end of the list
        if(!nodeFound)
        {
            previousPointer -> nxtPtr = newNode;
            newNode -> nxtPtr = NULL;
            nodeFound = 0;
        }
        
        nodeFound = 0;
    }
    
    printf("After Insertion: ");
    printList(headNode);
    printf("\n");
    
    //Delete the node with a value of 3.
    //This search is very similar to the previous search.  When the node value is found, the
    // previousPointer is set to point to the value pointed by currentPointer.  Then the node
    // value is set to 0 and the locationIsAvailable is set to 1.
    // If the node to be deleted is the head node, then the headNode is set equal to the location
    // pointed to by the current head node.  If the location is pointing to NULL, then it must be
    // the last node, so the previousPointer is set to point to NULL since it will now be the last node.
    currentPointer = headNode;
    previousPointer = headNode;
    
    while(previousPointer -> nxtPtr != NULL)
    {
        if((currentPointer -> val) == 3)
        {
            if(currentPointer == headNode)
            {
                headNode = currentPointer -> nxtPtr;
            }
            
            else if(currentPointer -> nxtPtr == NULL)
            {
                previousPointer -> nxtPtr = NULL;
            }
            
            else
            {
                previousPointer -> nxtPtr = currentPointer -> nxtPtr;
            }
            
            currentPointer -> locationIsAvailable = 1;
            currentPointer -> nxtPtr = NULL;
            break;
        }
        
        previousPointer = currentPointer;
        currentPointer = currentPointer -> nxtPtr;
    }
    
    printf("After deletion: ");
    printList(headNode);
    
    
    
    return 0;
}

void printList(struct Node *head)
{
    struct Node *tmp = head;
    
    while(tmp != NULL)
    {
        if(tmp->nxtPtr == NULL)
        {
            printf("%d", tmp->val);
        }
        
        else
        {
            printf("%d, ", tmp->val);
        }
        
        tmp = tmp->nxtPtr;
    }
}