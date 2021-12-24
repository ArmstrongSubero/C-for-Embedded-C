//NOTES: Polymorphism is the ability to
// subsitute objects of matching interfaces for
// one another at runtime

#include <stdio.h>
#include <conio.h>
#include <stdint.h>

/*********************Encapsulation**********************/
/* This class is our super class */
/* declaring a class in c */
typedef struct
{
    /* for polymorphism we need to add a vtable */
    /* so we add a virtual pointer to vtable */
    struct ShapeVtable const *vptr;
    
    int16_t x;
    int16_t y;
} Shape;


/*****************Polymorphism**************************/
/* vtable needed to support run time method binding */
struct ShapeVtable
{
    uint32_t(*area)(Shape * const me);
    void (*draw)(Shape const * const me);
};

/* interface in C */
/* *const me corresponds to self or this */
void Shape_ctor(Shape * const me, int16_t x, int16_t y);
void Shape_moveBy(Shape * const me, int16_t dx, uint16_t dy);
int16_t Shape_getX(Shape * const me);
int16_t Shape_getY(Shape * const me);

/* virtual calls (late binding) */
static inline void Shape_draw_vcall(Shape const * const me)
{
    (*me->vptr->draw)(me);
}

static inline uint32_t Shape_area_vcall(Shape const * const me)
{
    return (*me->vptr->area)(me);
}

/* for C89 cpmpilers */
#define SHAPE_DRAW_VCALL(me) (*(me)->vptr->draw)((me))
#define SHAPE_AREA_VCALL(me) (*(me)->vptr->area)((me))


/* shape class definition in c*/
static void Shape_draw(Shape const * const me);
static uint32_t Shape_area(Shape const * const me);

void Shape_ctor(Shape * const me, int16_t x0, int16_t y0)
{
    static const struct ShapeVtable vtable =
    {
        &Shape_draw,
        &Shape_area
    };
    me->vptr = &vtable;
    me->x = x0;
    me->y = y0;
}

void Shape_moveBy(Shape * const me, int16_t dx, uint16_t dy)
{
    me->x += dx;
    me->y += dy;
}

uint16_t Shape_distanceFrom(Shape const * const me,
                            Shape const * other)
{
    int16_t dx = me->x - other->x;
    int16_t dy = me->y - other->y;
    if(dx < 0)
    {
        dx = -dx;
    }
    if(dy < 0)
    {
        dy = -dy;
    }
    return dx + dy;
}

static void Shape_draw(Shape const * const me)
{
    (void)me; /* unused parameter */
}

static uint32_t Shape_area(Shape const * const me)
{
    (void)me; /* unused parameter */
    return 0U;
}

/* draw all shapes in a given array graph[] */
void drawGraph(Shape const *graph[])
{
    uint8_t i;
    for(i = 0; graph[i] != (Shape *)0; ++i)
    {
        Shape_draw_vcall(graph[i]); /* polymorphism! */
    }
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
void Rectangle_ctor(Rectangle * const me, int16_t x0,
                    int16_t y0,
                    uint16_t w0, uint16_t h0);

void Rectangle_draw(Rectangle const * const me);
uint32_t Rectangle_area(Rectangle const * const me);

/* subclass methods implementaiton */

/* constructor implementation */
void Rectangle_ctor(Rectangle * const me, int16_t x0, int16_t y0,
                    uint16_t w0, uint16_t h0)
{
    static const struct ShapeVtable vtable =
    {
        (void (*)(Shape const * const me))&Rectangle_draw,
        (uint32_t (*)(Shape const * const me))&Rectangle_area
    };
    
    Shape_ctor(&me->super, x0, y0); /* base class ctor */
    me->super.vptr = &vtable;
    
    /* init attributes added in this class */
    me->width = w0;
    me->height = h0;
}

void Rectangle_draw(Rectangle const * const me)
{
    printf("Draw rectangle");
}

uint32_t Rectangle_area(Rectangle const * const me)
{
    return (uint32_t)me->width * (uint32_t)me->height;
}


int main()
{
    /* create instances of the subclass in c*/
    Rectangle r1, r2;
    
    Shape const *shapes[] =   /* collection of shapes */
    {
        &r2.super,
        &r1.super
    };
    
    Shape const *s;
    
    /* instantiate rectangles... */
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);
    
    drawGraph(shapes);
    
    
    return 0;
}