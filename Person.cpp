#include "Cart_Point.h"
#include "Person.h"
#include <iostream>
#include "Game_Object.h"
#include <cmath>
using namespace std;

//default person constructor
Person::Person(): Game_Object()
{
	health=5;
	speed=5;
	cout<< "Person default constructed"<< endl;
	state='s';
} 

//makes a specific type of person based on the in code (i.e. miner or soldier)
Person::Person(char in_code) : Game_Object('P')
{speed=5;
display_code=in_code;
cout<< "Person constructed"<< endl;
state='s';
health=5;
}

//gives the person a location and ID along with type
Person::Person(char in_code, int in_id, Cart_Point in_loc) : Game_Object('P', in_id, in_loc)
{speed=5;
display_code=in_code;
cout<< "Person constructed"<< endl;
state='s';
location=in_loc;
health=5;
}

//has the person setup to move if possible
void Person::start_moving(Cart_Point dest)
{if (state!='x')
{setup_destination(dest);
state='m';}
else
	{cout<< "Dead can't move"<< endl;}
}

//updates the persons location if they have moved
bool Person::update_location()
{
	delta = ((destination-location)*(speed/cart_distance(destination, location)));
if((fabs((destination-location).x)> fabs(delta.x)) && (fabs((destination-location).y)>fabs(delta.y)))
	{
	location=location + delta;
	cout<< "Moving "<< get_id()<< " to "<< destination<< endl;
	return false;
	}
else if ((fabs((destination-location).x)<= fabs(delta.x)) && (fabs((destination-location).y)<= fabs(delta.y)))
	{
	location=destination;
	cout<< "I'm there!"<< endl;
	return true;
	}

}

//stops the movement of a person
void Person::stop()
{
	if (state!='s')
	state='s';

}

//shows what the person is doing
void Person::show_status() 
{ 
	cout<<display_code<< get_id()<< " at "<< get_location()<< " moving at speed of "<< speed<< " towards "<< destination<< "at each step <X,Y> of "<< delta<< endl;
	if (state=='s')
	{
		cout<< "Stopped"<< "\nHealth: "<< health<< endl;
	}
	else if (state=='x')
		{cout<< "is dead"<< endl;}
}

//has a destination setup so it is not accidentally changed
void Person::setup_destination(Cart_Point dest)
{  
	destination= dest;
}

//makes default person unable to mine but if a miner, then it will be overridden
void Person::start_mining(Gold_Mine* mine, Town_Hall* home)
{
	cout<< "Sorry, I can't work a mine."<< endl;
}

//default deconstructor to prevent overloading
Person::~Person()
{
	cout<< "Person deconstructed"<< endl;
}

//checks if person is alive
bool Person::is_alive()
{
	if (state=='x')
	{
		return false;
	}
	else
		{return true;}
}

//allows a person to be attacked by a soldier
void Person::take_hit(int attack_strength)
{
	if (attack_strength>health)
		{
			health=0;
			cout<<"Arrggh!"<<endl;
			state='x';
	}
	else
	{health=(health-attack_strength);
	cout<< "Ouch!"<<endl;}
}

//allows a person  to attack if they are a soldier
void Person::start_attack(Person* target)
{
	cout<< "I can't attack."<< endl;
}
