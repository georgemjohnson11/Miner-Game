#include "Cart_Point.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Cart_Vector.h"
#include <cmath>
#include <iostream>
#include <cctype>
#include "Miner.h"
using namespace std;

Miner::Miner() : Person('M')
{
amount=0;
cout<< "Miner default constructed"<< endl;
}

Miner::Miner(int inputx, Cart_Point inputLoc) : Person('M', inputx,  inputLoc)
{
	amount=0;
	cout<< "Miner constructed"<< endl;
}


bool Miner::update()
{
switch (state)
{
case 'x':
	return false;
case 's': 
return false;
// moves the miner
case 'm': 
	if(!update_location())
	{//<< "Moving "<< get_id()<< " to "<< destination<< endl;
	return false;
	}
else 
{//if the miner is at the location, stops the miner
	state='s';
	return true;
}
case 'o': 
	if(update_location())
{
	state='g';
	return true;}
	{return false;}
case 'g': 
	amount=mine->dig_gold();
	cout<< display_code<< get_id()<< ":Got "<< amount<< " gold."<< endl;
	setup_destination((*home).get_location());
	state='i';
	return true;
case 'i':
	if (update_location())
	{
		state='d';
		return true;
	}
	else 
	{
		return false;}

case 'd':
	home->deposit_gold(amount);
	amount=0;
	if (mine->is_empty())
	{state='s';
	cout<< display_code<<get_id()<< ":More work?"<< endl;
	return true;}
	else
	{state='o';
	cout<< display_code<< get_id()<< ":Going back for more."<< endl;
	start_mining(mine, home);
	return true;}
}}

//moves the miner to gold mine and back to town hall
void Miner::start_mining(Gold_Mine* fakemine, Town_Hall* fakehome)
{
mine=fakemine;
home=fakehome;
if (state='x')
	{cout<< "Dead can't mine"<< endl;}
else if ((mine->get_location()).x != location.x && (mine->get_location()).y != location.y)
{
	state='o';
	setup_destination((mine->get_location()));
	cout<< "Yes, my Lord"<< endl;
}
else
{
	state='g';
}
}

void Miner::show_status() 
{
Person::show_status();
if (state=='o')
{cout<< "Outbound to mine"<< endl;}
else if (state=='g')
{cout<< "Getting gold from mine"<< endl;}
else if (state=='i')
{cout<< "Inbound to home with load:" << amount<< endl;}
else if (state== 'd')
{cout<< "Depositing gold"<< endl;}
}

Miner::~Miner()
{
	cout<< "Miner deconstructed"<< endl;
}

