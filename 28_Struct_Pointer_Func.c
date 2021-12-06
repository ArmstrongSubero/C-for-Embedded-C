//NOTE: This program passes a pointer to a structure
// to a function
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct student
{
    int r_no;
    char name[20];
    char course[20];
    int fees;
};

void display(struct student *);

int main()
{
    struct student *ptr;
    ptr = (struct student *)malloc(sizeof(struct student));
    
    printf("Enter the data for the student: \n");
    
    printf("\nRoll No: ");
    scanf("%d", &ptr->r_no);
    
    printf("\n Name: ");
    scanf("%s", &ptr->name);
    
    printf("\n Course: ");
    scanf("%s", &ptr->course);
    
    printf("\n Fees: ");
    scanf("%d", &ptr->fees);
    
    display(ptr);
    getch();
    
    return 0;
}

void display(struct student *ptr)
{
    printf("\nDetails of student");
    
    printf("\n Roll No = %d", ptr->r_no);
    printf("\n Name = %s", ptr->name);
    printf("\n Course = %s ", ptr->course);
    printf("\n Fees = %d", ptr->fees);
}