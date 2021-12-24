//NOTES: Encapsulation is the ability to package data
// into classes, both variables and methods
// We look at how we can do this in C.

#include <stdio.h>
#include <conio.h>
#include <stdint.h>

/*********************Encapsulation**********************/
/* declaring a class in c */
typedef struct
{
    int16_t x;
    int16_t y;
} Shape;


/* interface in C */
/* *const me corresponds to self or this */
void Shape_ctor(Shape * const me, int16_t x, int16_t y);
void Shape_moveBy(Shape * const me, int16_t dx, uint16_t dy);
int16_t Shape_getX(Shape * const me);
int16_t Shape_getY(Shape * const me);

/* shape class definition in c*/

/* constructor implementation */
void Shape_ctor(Shape * const me, int16_t x, int16_t y)
{
    me->x = x;
    me->y = y;
}

/* method */
void Shape_moveBy(Shape * const me, int16_t dx, uint16_t dy)
{
    me->x += dx;
    me->y += dy;
}

/* getter operations */
int16_t Shape_getX(Shape * const me)
{
    return me->x;
}
int16_t Shape_getY(Shape * const me)
{
    return me-> y;
}


int main()
{
    /* create instances of the class in c*/
    Shape s1, s2;
    
    /* this is automatic in OOP languages */
    Shape_ctor(&s1, 0, 1);
    Shape_ctor(&s2, -1, 2);
    
    /* get current x and y coordiantes */
    printf("Shape s1(x=%d,y=%d)\n", Shape_getX(&s1), Shape_getY(&s1));
    printf("Shape s2(x=%d,y=%d)\n", Shape_getX(&s2), Shape_getY(&s2));
    
    /* apply move class method */
    Shape_moveBy(&s1, 2, -4);
    Shape_moveBy(&s2, 1, -2);
    
    /* get changed x and y cordinates */
    printf("Shape s1(x=%d,y=%d)\n", Shape_getX(&s1), Shape_getY(&s1));
    printf("Shape s2(x=%d,y=%d)\n", Shape_getX(&s2), Shape_getY(&s2));
    return 0;
}