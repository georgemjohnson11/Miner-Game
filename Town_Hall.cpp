//Town_Hall was declared as private
#include "Cart_Point.h"
#include "Town_Hall.h"
#include "Game_Object.h"

Town_Hall::Town_Hall():Game_Object()
{display_code='t';
state='o';
amount=0;
location=Cart_Point();
cout<< "Town_Hall default constructed"<< endl;
}

Town_Hall::Town_Hall(int Inputid, Cart_Point InputLoc):Game_Object('T', Inputid, InputLoc)
{
display_code='t';
location=InputLoc;
state='o';
amount=0;
	cout<< "Town_Hall constructed"<< endl;
}


void Town_Hall::deposit_gold(double deposit_amount)
{amount+= deposit_amount;
}
bool Town_Hall::update()
{if ((amount>50) && (display_code == 't'))
{state='u';
display_code='T';
cout<< "Town_Hall" << get_id()<< " has been upgraded."<< endl;
return true;}
else
{return false;}
}

void Town_Hall::show_status()
{
	cout<<"Town_Hall ";
	cout<<display_code<< (get_id()+1)<< " at " << location<< endl;
cout<< "Contains "<< amount<< "."<<  endl;
if (display_code=='t')
{cout<< "Not Yet Upgraded."<< endl;}
else if(display_code=='T')
{cout<< "Upgraded"<< endl;}
}

Town_Hall::~Town_Hall()
{
	cout<< "Town_Hall deconstructed"<< endl;
}

