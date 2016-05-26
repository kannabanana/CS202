#include "shape.h"

Point Point::operator + (const Point& p) const
{
  int num = x+p.x;
  int num2 = y+p.y;
  return Point(num,num2);
}



Point& Point::operator += (const Point& p)
{
    x+=p.y;
    y+=p.y;
    return *this;
}

bool Point::operator == (const Point& p) const
{
   if(x == p.x && y == p.y)
       return true;
   else
    return false;    
}

ostream& operator << (ostream& out, const Point& p)
{
    out << p.x;
    out << p.y;
    return out; //<< p.x << p.y
}

Shape& Shape::operator = (const Shape& s)
{
    if (s != s)
    {
        s = new char[strlen(s.color)+1];
        strcpy(s,s.color);
    }
    return *this; 
}

Shape& Shape::operator += (const Point& p)
{
/*    center;
    return *this;    
*/
}

Shape operator + (const Point& p, const Shape& s)
{

}

Shape operator + (const Shape& s, const Point& p)
{

}

Circle operator + (const Point& p, const Circle& c)
{
}

Circle operator + (const Circle& c, const Point& p)
{
}

Circle& Circle::operator = (const Circle& c)
{
}

ostream& operator << (ostream& out, const Shape& s)
{
}

