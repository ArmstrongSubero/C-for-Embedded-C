//NOTES: A struc is like a record. IT stores related
// information about an entity.
// structs can store information of many different
// data types
#include <stdio.h>
#include <conio.h>

struct student
{
    int r_no;
    char name[20];
    char course[20];
    float fees;
    
};


int main()
{
    // wr can set members of a structure using
    struct student stud1 = {01, "Rahul", "BCA", 45000};
    
    // we can also use the dot operator
    struct student stud2;
    
    stud2.r_no = 01;
    strcpy(stud2.name, "Rahul");
    strcpy(stud2.course, "BCA");
    stud2.fees = 45000;
    
    printf("Student Name: %s", stud2.name);
    
    
    
    
    
    
    return 0;
}