//NOTES: Inheritance also called generalization
// is the ability to define new classes based on
// existing classes in order to get code reuse and
// organization

#include <stdio.h>
#include <conio.h>
#include <stdint.h>

/*********************Encapsulation**********************/
/* This class is our super class */
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


/*******************Inherritance**********************/

/* we can make a base class from our super class */
typedef struct
{
    /* inherits shape */
    /* Takes advantage of our ability to get pointer
     * to first memory location through object */
    Shape super;
    
    /* attributes added by this subclass */
    uint16_t width;
    uint16_t height;
} Rectangle;

/* constructor prototype */
void Rectangle_ctor(Rectangle * const me, int16_t x,
                    int16_t y,
                    uint16_t width, uint16_t height);

/* subclass methods implementaiton */

/* constructor implementation */
void Rectangle_ctor(Rectangle * const me, int16_t x, int16_t y,
                    uint16_t width, uint16_t height)
{
    /* first call superclass? ctor */
    Shape_ctor(&me->super, x, y);
    /* next, you initialize the attributes added by this subclass... */
    me->width = width;
    me->height = height;
}


int main()
{
    /* create instances of the subclass in c*/
    Rectangle r1, r2;
    
    /* this is automatic in OOP languages instantiation*/
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);
    
    /* print current coordinate calues */
    printf("Rect r1(x=%d,y=%d,width=%d,height=%d)\n",
           r1.super.x, r1.super.y, r1.width, r1.height);
           
    printf("Rect r2(x=%d,y=%d,width=%d,height=%d)\n",
           r2.super.x, r2.super.y, r2.width, r2.height);
           
    /* re-use inherited function from the superclass Shape */
    Shape_moveBy((Shape *)&r1, -2, 3);
    Shape_moveBy(&r2.super, 2, -1);
    
    /* print new coordinate values */
    printf("Rect r1(x=%d,y=%d,width=%d,height=%d)\n",
           r1.super.x, r1.super.y, r1.width, r1.height);
    printf("Rect r2(x=%d,y=%d,width=%d,height=%d)\n",
           r2.super.x, r2.super.y, r2.width, r2.height);
           
    return 0;
}