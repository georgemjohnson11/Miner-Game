#include "Person.h"
#include "Cart_Point.h"

#ifndef Soldier_H
#define Soldier_H
class Soldier: public Person
{
private:
	int attack_strength;
	double range;
	Person * target;

public:
	Soldier();
	Soldier(int, Cart_Point);
	void start_attack(Person *);
	bool update();
	void show_status();

};
#endif
