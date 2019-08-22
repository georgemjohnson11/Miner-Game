// Gold_Mine() was declared as private and dig_gold function did not return amount
#include "Cart_Point.h"
#include <iostream>
#include "Gold_Mine.h"
#include "Game_Object.h"
using namespace std;

//generates a default gold mine
Gold_Mine::Gold_Mine():Game_Object()
{
	amount=100;
	location= Gold_Mine::get_location();
	cout<<"Gold_Mine default constructed"<< endl;
}

//generates a gold mine with the  user input location and ID
Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc):Game_Object('G', inputId, inputLoc)
{
	location=inputLoc;
	amount=100;
	cout<<"Gold_Mine constructed"<< endl;
}

//checks if the gold mine is empty
bool Gold_Mine::is_empty()
{
if (amount==0)
	{return true;}
else
	{return false;}
}

//allows gold to be dug for
double Gold_Mine::dig_gold(double amount_to_dig)
{
	if (amount>amount_to_dig)
	{
		amount=amount-amount_to_dig;
		return amount_to_dig;
	}
	else if (amount<amount_to_dig)
	{
		amount_to_dig=amount;
		amount=0;
		update();
		return amount_to_dig;
	}
	else if (amount ==0)
	{
		cout<<"There ain't any gold here"<< endl;}
		return amount;
}

//updates the mine
bool Gold_Mine::update()
{
	if (amount==0 && state=='g')
	{
		state='e';
		display_code='g';
		cout<< "Gold_Mine "<< get_id()<< " is depleted"<< endl;
		return true;
	}
	else
	{
		return false;
	}
}

//shows the status of the mine and amount of gold
void Gold_Mine::show_status()
{	
	cout<< "Gold_Mine ";
	Game_Object::show_status();
	cout<< " "<< amount<< endl;
}

//default deconstructor of mine
Gold_Mine::~Gold_Mine()
{
	cout<< "Gold_Mine deconstructed"<< endl;
}
