#include "View.h"
#include "Game_Object.h"
#include "Cart_Vector.h"
#include <iostream>
using namespace std;
//allows the board to be created
View::View()
{
	size=11;
	scale=2;
	origin=Cart_Point(0,0);
}

//prevents the object from being sent outside the board
bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
	if (location.x>20 || location.y>20)
	{
		cout<< "An object is outside the display"<< endl;
		return false;
	}
	else 
	{
		Cart_Point objectlocation;
			objectlocation.y= (location.x)/scale;
		objectlocation.x=(20-location.y)/scale;
		ix=int(objectlocation.x);
		iy=int(objectlocation.y);
		return true;
	}
}

//resets the board
void View::clear()
{
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			grid[i][j][0]='.';
			grid[i][j][1]=' ';
		}
	}
}

//plots all the objects that need to be plotted
void View::plot(Game_Object *ptr)
{
	int x, y;
	if (get_subscripts(x, y, ptr->get_location()))
	{
		if((grid[x][y][0]) != ('.'))
		{
			grid[x][y][0]= '*';
			grid[x][y][1]= ' ';
		}
		else
		{
		ptr-> drawself(grid[x][y]);
		}
	}
}

void View::draw()
{
	// draws the row numbers on the left and grid
	for (int g=0; g<size; g++)
	{
		if ((g==0)|| (g==2)||(g==4))
		{
			cout<< view_maxsize-g*2;
		}
		else if ((g==6) || (g==8) || (g==10))
		{
			cout<< view_maxsize-g*2<< ' ';
		}
		else
		{
			cout<< "  ";
		}
		for (int kaboom=0; kaboom<size; kaboom++)
		{
			cout<< grid[g][kaboom][0];
			cout<< grid[g][kaboom][1];
		}
		cout<< endl;
	}


	//draw the column numbers across the bottom
	cout<< "  ";
	for (int e=0; e<size; e++)
	{
		if ((e==0)|| (e==2)||(e==4))
		{
			cout<< e*2<< "   ";
		}
		else if ((e==6) || (e==8) ||(e==10))
		{
			cout<< e*2<< "  ";
		}
	}
}
