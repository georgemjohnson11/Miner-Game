#include <iostream>
using namespace std;
#ifndef CART_VECTOR_H
#define CART_VECTOR_H
using namespace std;
class Cart_Vector
{
public:
double x;
double y;
Cart_Vector();
Cart_Vector(double, double);
friend ostream &operator<<(ostream &out, const Cart_Vector &Cart_Vector);

};
#endif
Cart_Vector operator /(Cart_Vector, double);
Cart_Vector operator *(Cart_Vector, double);

