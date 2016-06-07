#ifndef Model_H
#define Model_H
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "View.h"
#include "Person.h"
#include "Soldier.h"
class Model
{
private:
	int time;
	Game_Object * object_ptrs[10];
	int num_objects;
	Person * person_ptrs[10];
	int num_persons;
	Gold_Mine * mine_ptrs[10];
	int num_mines;
	Town_Hall * hall_ptrs[10];
	int num_halls;

public:
	Model();
	~Model(); //deconstructor
	Person *get_Person_ptr(int);
	Gold_Mine * get_Gold_Mine_ptr(int);
	Town_Hall * get_Town_Hall_ptr(int);
	virtual bool update();
	void display(View &);
	void show_status();
};
#endif

