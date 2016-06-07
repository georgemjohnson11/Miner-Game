#include <iostream>
#include <cmath>
#include "Cart_Vector.h"
using namespace std;

//generates a cart vector of default 0,0
Cart_Vector::Cart_Vector()
{
x=0.0;
y=0.0;
}
//generates a cart vector of the user's choice
Cart_Vector::Cart_Vector(double inputx, double inputy)
{
x=inputx;
y=inputy;
}

//allows cart vectors to be divided by a scalar double
Cart_Vector operator /(Cart_Vector C1, double d)
{
Cart_Vector tempx, tempy;
tempx.x= C1.x/d;
tempy.y= C1.y/d;
return Cart_Vector(tempx.x, tempy.y);
}

//allows cart vectors to be multiplied by a scalar double
Cart_Vector operator *(Cart_Vector C1, double d)
{
Cart_Vector tempx, tempy;
tempx.x= C1.x*d;
tempy.y= C1.y*d;
return Cart_Vector(tempx.x, tempy.y);
}

//overloads the stream operator to have cart vectors be input as < <x,y> >
ostream &operator << (ostream &out, const Cart_Vector &Cart_Vector)
{
out<< "<"<< Cart_Vector.x<<","<< Cart_Vector.y<<">";
return out;
}

