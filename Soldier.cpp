#include "Game_Object.h"
#include "View.h"
#include "Person.h"
#include "Soldier.h"

//creates a soldier as a person with range and attack_strength variables
Soldier::Soldier() : Person('S')
{
	range=2.0;
	attack_strength=2;
	state='s';
	cout<< "default soldier constructed"<< endl;
}

//creates a soldier with an id number, and location
Soldier::Soldier(int id_num, Cart_Point location):Person('S', id_num, location)
{
		range=2.0;
	attack_strength=2;
	state='s';
	cout<< "soldier constructed"<< endl;
}
//has the soldier to start attacking if not dead and notifies the status of the attack when updated
void Soldier::start_attack(Person* in_target)
{
	if (state=='x')
	{
		cout<< "Dead can't attack"<< endl;
	}
	else if (cart_distance((in_target->get_location()), location)<=2)
	{
		if (in_target->is_alive())
		{
			cout<< "Clang!"<< endl;
			state='a';
			in_target-> take_hit(attack_strength);		
		}
		else
		{
			cout<< "I triumph!"<< endl;
			state='s';
		}
	}
	else
	{
		cout<< "Target is out of range"<< endl;
		state='s';
	}
}

//updates the soldier class
bool Soldier::update()
{switch (state)
{
case 'x':
	{return false;}
case 's': 
	{return false;}
// moves the soldier
case 'm': 
	if(update_location()!=true)
	{return false;
	}
else 
{//if the soldier is at the location, stops the miner
	state='s';
	return true;
}
case 'a':
	if (state=='s')
		{return true;}
	else
	{return false;}
}
}

//shows what the soldier is doing
void Soldier::show_status()
{
	cout<< "Soldier status:";
	Person::show_status();
	if (state=='a')
		cout<< "Attacking"<< endl;
	else
		cout<< " is not attacking"<< endl;
}

