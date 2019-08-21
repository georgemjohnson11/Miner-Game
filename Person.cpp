#include "Cart_Point.h"
#include "Person.h"
#include <iostream>
#include "Game_Object.h"
#include <cmath>
using namespace std;

Person::Person(): Game_Object()
{
	health=5;
	speed=5;
	cout<< "Person default constructed"<< endl;
	state='s';
} 

Person::Person(char in_code) : Game_Object('P')
{speed=5;
display_code=in_code;
cout<< "Person constructed"<< endl;
state='s';
health=5;
}

Person::Person(char in_code, int in_id, Cart_Point in_loc) : Game_Object('P', in_id, in_loc)
{speed=5;
display_code=in_code;
cout<< "Person constructed"<< endl;
state='s';
location=in_loc;
health=5;
}

void Person::start_moving(Cart_Point dest)
{if (state!='x')
{setup_destination(dest);
state='m';}
else
	{cout<< "Dead can't move"<< endl;}
}

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

void Person::stop()
{
	if (state!='s')
	state='s';

}

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

void Person::setup_destination(Cart_Point dest)
{  
	destination= dest;
}

void Person::start_mining(Gold_Mine* mine, Town_Hall* home)
{
	cout<< "Sorry, I can't work a mine."<< endl;
}

Person::~Person()
{
	cout<< "Person deconstructed"<< endl;
}

bool Person::is_alive()
{
	if (state=='x')
	{
		return false;
	}
	else
		{return true;}
}

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

void Person::start_attack(Person* target)
{
	cout<< "I can't attack."<< endl;
}
