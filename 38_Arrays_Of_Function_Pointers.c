//NOTES: Function pointers can be quite
// concise and easy to read, they can
// replace switch cases

// They are great when we have to call 
// a particular function at runtime
#include <stdio.h>
#include <conio.h>

/* Microchip technology example
int function1(int x);
int function2(int y);
int function3(int z);

int(*funcPtr[3])(int a) =
{
    &function1, &function2, &function3
};
*/

# define ops 4

// calculator functions
float sum(float a, float b) {return (a + b);}
float sub(float a, float b) {return (a - b);}
float mul(float a, float b) {return (a * b);}
float div(float a, float b) {return (a / b);}

int main()
{
    // declare array of pointers (*ptr2func[ops])
    // these point to functions (float, float) which return a float value
    // the name of the function sum, sub etc. passes the address of the function
    float (*ptr2func[ops])(float, float) = {&sum, &sub, &mul, &div};
    
    int choice;
    float a, b;
    
    // get the choice
    printf("Enter your choice: 0 for sum, 1 for sub, 2 for mul, 3 for div: \n");
    scanf("%d", &choice);
    
    // get the numbers
    printf("Enter two numbers: \n");
    scanf("%f %f", &a, &b);
    
    // use function pointer
    printf("%f", ptr2func[choice](a, b));
    return 0;
}
