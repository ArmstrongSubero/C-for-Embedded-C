//NOTES: you can create a union inside of a structure
// it is useful when you have choices you want a user to
// specify
#include <stdio.h>
#include <conio.h>


struct student
{
    union
    {
        char name[20];
        int roll_no;
    };
    
    int marks;
};

int main()
{
    struct student stud;
    char choice;
    
    printf("\nYou can enter the name or roll number of the student");
    printf("\nDo you want to enter the name? (Y or N): ");
    
    scanf("%c", &choice);
    
    if(choice == 'y' || choice =='Y')
    {
        printf("\nEnter the name: ");
        scanf("%s", &stud.name);
    }
    
    else
    {
        printf("Enter the roll number: ");
        scanf("%d", &stud.roll_no);
    }
    
    printf("Enter the marks: ");
    scanf("%d", &stud.marks);
    
    if(choice == 'y' || choice == 'Y')
    {
        printf("\n Name: %s ", stud.name);
    }
    
    else
    {
        printf("\nRoll Number: %d ", stud.roll_no);
    }
    
    printf("\n Marks: %d", stud.marks);
    
    return 0;
}