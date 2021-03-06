//Town_Hall was declared as private
#include "Cart_Point.h"
#include "Town_Hall.h"
#include "Game_Object.h"

//creates the town hall so that miners can deposit gold
Town_Hall::Town_Hall():Game_Object()
{
	display_code='t';
	state='o';
	amount=0;
	location=Cart_Point();
	cout<< "Town_Hall default constructed"<< endl;
}

//puts the town hall at a certain location
Town_Hall::Town_Hall(int Inputid, Cart_Point InputLoc):Game_Object('T', Inputid, InputLoc)
{
	display_code='t';
	location=InputLoc;
	state='o';
	amount=0;
	cout<< "Town_Hall constructed"<< endl;
}

//allows more gold to be added to the town hall
void Town_Hall::deposit_gold(double deposit_amount)
{
	amount+= deposit_amount;
}

//updates the town halls and upgrades if need be
bool Town_Hall::update()
{
	if ((amount>50) && (display_code == 't'))
	{
		state='u';
		display_code='T';
		cout<< "Town_Hall" << get_id()<< " has been upgraded."<< endl;
		return true;
	}
	else
	{
		return false;
	}
}

//shows the location and whether the Town Hall has been upgraded
void Town_Hall::show_status()
{
	cout<<"Town_Hall ";
	cout<<display_code<< (get_id()+1)<< " at " << location<< endl;
	if (display_code=='t')
	{
		cout<< "Not Yet Upgraded."<< endl;
	}
	else if(display_code=='T')
	{
		cout<< "Upgraded"<< endl;
	}
}
//default deconstructor for town hall
Town_Hall::~Town_Hall()
{
	cout<< "Town_Hall deconstructed"<< endl;
}

