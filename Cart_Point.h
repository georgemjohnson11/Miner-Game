#include <iostream>
using namespace std;
#include "Cart_Vector.h"
#ifndef CART_POINT_H
#define CART_POINT_H
class Cart_Point
{
public:
double x;
double y;
Cart_Point();
Cart_Point(double, double);
friend ostream &operator <<(ostream &out, const Cart_Point &Cart_Point);
Cart_Vector operator-(Cart_Point);
//Cart_Vector operator- (Cart_Vector);
Cart_Point operator+ (Cart_Vector);
};
double cart_distance(Cart_Point, Cart_Point);
//Cart_Vector operator -(Cart_Point, Cart_Point);

#endif

