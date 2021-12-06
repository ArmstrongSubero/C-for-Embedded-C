// NOTES:enumerations are integer data types that you can
// create with a limited range of values.

// they may only contain a specified list of values
// these values are symbolic constans
#include <stdio.h>
#include <conio.h>

// enum typename {label0, label1, labeln}
// SUN = 0, MON =1 ... SAT = 6
enum weekday {SUN, MON, TUE, WED, THR, FRI, SAT};

// you can also increment from the assignemnt that is made
// create instance when declearing the enum
enum people {Rob, Steve, Paul = 7, Bill, Gary} mypeople;

int main()
{
    // create the variable of type weekday
    enum weekday day;
    
    // varName = labeln
    day = 6;
    day = WED;
    
    if(day == WED)
    {
        printf("today is wednesday");
    }
    return 0;
}