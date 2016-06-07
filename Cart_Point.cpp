#include <cmath>
#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
using namespace std;

//creates a point on the map as default of 0,0
Cart_Point::Cart_Point()
{
x= 0.0;
y=0.0;
}

//creates a point based on the user input
Cart_Point::Cart_Point(double inputx, double inputy)
{
x= inputx;
y= inputy;
}

//creates a distance between two points and returns that
double cart_distance(Cart_Point p1, Cart_Point p2)
{
double totalx;
double totaly;
totalx= (p1.x-p2.x)*(p1.x-p2.x);
totaly= (p1.y-p2.y)*(p1.y-p2.y);
double total;
total=sqrt(totalx+totaly);
return total;
}

//overloads the default stream operator to take points as <(x,y)>
ostream &operator<<(ostream &out, const Cart_Point &Cart_Point)
{out<< "("<< Cart_Point.x<<","<< Cart_Point.y<<")";
return out;}

//overloads the default addition symbol to add cart points to cart vectors to generate a cart point
Cart_Point Cart_Point::operator +(Cart_Vector V1)
{
Cart_Point temp; 
temp.x= x+V1.x;
temp.y= y+V1.y;
return temp;
}

//overloads the default subtraction symbol to subtract cart points to generate a cart vecctor
Cart_Vector Cart_Point::operator- (Cart_Point C1)
{
	Cart_Vector temp;
	temp.x= x-C1.x;
	temp.y= y-C1.y;
	return (temp);
}

