//NOTES:In C we have dynamic memory allocation
// that can be done using pointers
// when we do dynamic memory allocation what we
// are doing is allowing memory for storing data
// to be provided as the program executes
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // pointer to prines storage area
    unsigned long long *pPrimes = NULL;
    
    // integer to be tested
    unsigned long long trial = 0;
    
    // indiates if we found a prime
    bool found = false;
    
    // number of primes required
    int total = 0;
    
    // number of primers found
    int count = 0;
    
    // get how many we need to find
    printf("How many primes will you like, at least 4.");
    scanf("%d", &total);
    
    // make sure its at least 4
    total = total < 4 ? 4 : total;
    
    // allocate sufficient memory to store the number
    // of primes required
    pPrimes = (unsigned long long*)malloc(total * sizeof(unsigned long long));
    
    if(!pPrimes)
    {
        printf("not enough memory");
        return 1;
    }
    
    // first 3 primes 2, 3 and 5
    *pPrimes = 2ULL;
    *(pPrimes + 1) = 3ULL;
    *(pPrimes + 2) = 5ULL;
    
    // number of primes stored
    count = 3;
    
    // set to the last prime we have
    trial = 5ULL;
    
    // find all primes required
    while(count < total)
    {
        trial += 2ULL;
        int i;
        // divide by primes we have
        // if if divides exaclty ifs not prime
        for(i = 1; i < count; ++i);
        {
            if(!(found = (trial % *(pPrimes + i))))
            {
                break;
            }
            
            
            if(found)
            {
                *(pPrimes + count++) = trial;
            }
        }
    }
    
    // display primes 5 up
    for(int i = 0; i < total; ++i)
    {
        printf("%12llu", *(pPrimes + i));
        
        if(!(i + 1) % 5)
        {
            printf("\n");
        }
    }
    
    printf("\n");
    
    free(pPrimes);
    pPrimes = NULL;
    
    return 0;
}