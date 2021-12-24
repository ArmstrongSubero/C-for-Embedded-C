//NOTES: At the heart of OOP are three pillars which are
// Encapsulation, Inheritance and Polymorphism
// OOP is all about seperating the what can be done
// from the implementation the how it can be done

// This example provides all three in C++, most notably
// polymorphism.
// Polymorphism allows you to write generic code at a
// higher level of abstraction
#include <iostream>
#include <conio.h>
#include <stdint.h>
#include <stdio.h>


using namespace std;


/*************Shape Encapsulation***********************/
/* shape class interface "what can be done" */
class Shape
{
  protected:    /* Shape's attributes... */
    int16_t x; /* x-coordinate of Shape's position */
    int16_t y; /* y-coordinate of Shape's position */
    
  public:    /* Shape's operations... */
    Shape(int16_t x0, int16_t y0);
    void moveBy(int16_t dx, int16_t dy);
    uint16_t distanceFrom(Shape const * other) const;
    
    /* for polymorphism */
    /* virtual allows selection based on the object
     * not on type of pointer */
    virtual void draw() const;
    virtual uint32_t area() const;
};

void drawGraph(Shape const *graph[]);

/**h**/

/* source */

Shape::Shape(int16_t x0, int16_t y0)
    : x(x0),
      y(y0)
{
}

void Shape::moveBy(int16_t dx, int16_t dy)
{
    this->x += dx;
    this->y += dy;
}

uint16_t Shape::distanceFrom(Shape const * other) const
{
    int16_t dx = x - other->x;
    int16_t dy = y - other->y;
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

void Shape::draw() const
{
    printf("shape draw");
}

/* For polymorphism */
uint32_t Shape::area() const
{
    //return (uint32_t)width * (uint32_t) height;
    return (uint32_t)0;
}

void drawGraph(Shape const *graph[])
{
    uint8_t i;
    
    for(i = 0; graph[i] != (Shape *)0; ++i)
    {
        /* polymorphism */
        /* selects draw on type of object not
         * type of the pointer */
        graph[i] -> draw();
    }
}


/*************Circle Interitance*****************************/
/* rectangle inherits from shape class */
/* "How it can be done */
class Circle : public Shape
{
  private: /* Circle's attributes... */
    /* attributes specific to this class */
    uint16_t radius;
    
  public:  /* Rectangle's operations... */
    Circle(int16_t x0, int16_t y0,
           uint16_t r0);
    virtual void draw() const;
    virtual uint32_t area() const;
};


/* implementation */
Circle::Circle(int16_t x0, int16_t y0,
               uint16_t r0)
    : Shape(x0, y0), /* base class ctor */
      
      /* init attributes added in this class */
      radius(r0)
{
}

void Circle::draw() const
{
    printf("circle draw\n");
}

uint32_t Circle::area() const
{
    return 3U * (uint32_t)radius * (uint32_t)radius;
}


/*************Rectangle Interitance*****************************/
/* rectangle inherits from shape class */
/* "How it can be done */
class Rectangle : public Shape
{
  private: /* Rectangle's attributes... */
    /* attributes specific to this class */
    uint16_t width;
    uint16_t height;
    
  public:  /* Rectangle's operations... */
    Rectangle(int16_t x0, int16_t y0,
              uint16_t w0, uint16_t h0);
    virtual void draw() const;
    virtual uint32_t area() const;
};


/* implementation */
Rectangle::Rectangle(int16_t x0, int16_t y0,
                     uint16_t w0, uint16_t h0)
    : Shape(x0, y0), /* base class ctor */
      
      /* init attributes added in this class */
      width(w0),
      height(h0)
{
}

void Rectangle::draw() const
{
    printf("rectangle draw\n");
}

uint32_t Rectangle::area() const
{
    return (uint32_t)width * (uint32_t)height;
}

/***********************Implementation**************/
Shape s1(1, 2); /* static allocation */
Rectangle r1(1, 2, 15, 10); /* static allocation */
uint32_t a;

/* circle */
Circle c1(3, 4, 10);


int main()
{
    Shape s2(3, 4); /* automatic allocation */
    Shape *ps3 = new Shape(5, 6); /* dynamic allocation */
    //Shape const *ps1 = &s1; /* const pointer to s1 */
    
    s1.moveBy(7, 8);
    s2.moveBy(9, 10);
    ps3->moveBy(-1, -2);
    //ps1->moveBy(-3, -4);
    
    r1.draw(); /* early binding */
    a = r1.area();
    r1.moveBy(7, 8);
    
    
    /* polymorphism */
    
    /* rectangle */
    /* upcasting */
    Shape *ps = &r1;
    
    ps->draw(); /* late or dynamic binding */
    a = ps -> area();
    
    // array of shape pointers
    Shape const *graph[] =
    {
        &c1,
        &r1,
        ps3,
        (Shape *)0
    };
    
    drawGraph(graph);
    
    return 0;
}