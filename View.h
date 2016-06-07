#include "Cart_Point.h"
#include "Game_Object.h"

#ifndef View_H
#define View_H
class View
{
private:
	static const int view_maxsize=20;
	int size;
	double scale;
	Cart_Point origin;
	char grid[view_maxsize][view_maxsize][2];
	bool get_subscripts(int &,int &, Cart_Point);

public:
	View();
	void clear();
	void plot(Game_Object *);
	void draw();


};
#endif
