#include "Model.h"

//a default gameboard for the user to play on
Model::Model()
{
	time=0;
	
	Miner* m1= new Miner(1, Cart_Point(5,1));
	object_ptrs[0]=  m1;
	person_ptrs[0]= m1;
	
	Miner* m2= new Miner(2, Cart_Point(10,1));
	object_ptrs[1]= m2;
	person_ptrs[1]= m2;
	
	Gold_Mine* g1= new Gold_Mine( 1, Cart_Point(1,20));
	object_ptrs[2]= g1;
	mine_ptrs[0]=g1;
	
	Gold_Mine* g2= new Gold_Mine(2, Cart_Point(10,20));
	object_ptrs[3]= g2;
	mine_ptrs[1]=g2;
	
	Town_Hall* t1= new Town_Hall();
	object_ptrs[4]= t1;
	hall_ptrs[0]=t1;

	Soldier * s3= new Soldier(3, Cart_Point(5,15));
	object_ptrs[5]=s3;;
	person_ptrs[2]=s3;

	Soldier * s4= new Soldier(4, Cart_Point(10,15));
	object_ptrs[6]=s4;;
	person_ptrs[3]=s4;
	
	num_persons=4;
	num_mines=2;
	num_halls=1;
	num_objects=7;
	cout<< "Model default constructed"<< endl;
}

Model::~Model()// deconstructs all pointers
{
	cout<< "Model destructed."<< endl;
}

//gets the ID of a person
Person* Model::get_Person_ptr(int id)
{
	if (person_ptrs[id])
	return person_ptrs[id];
	else
		return 0;
}

//gets the id of a gold mine
Gold_Mine* Model::get_Gold_Mine_ptr(int id)
{
	if (mine_ptrs[id])
	return mine_ptrs[id];
	else
		return 0;
}

//gets the id of a town hall
Town_Hall* Model::get_Town_Hall_ptr(int id)
{
	if (hall_ptrs[id])
	return hall_ptrs[id];
	else
		return 0;
}

bool Model::update()// updates everything after it updates on the system (if it updates)
{
	time++;
	if (person_ptrs[0]->update() & person_ptrs[1]->update() & person_ptrs[2]->update() & person_ptrs[3]->update())
	{
		mine_ptrs[0]->update();
		mine_ptrs[1]->update();
		hall_ptrs[0]->update();
		return true;}
	else
		return false;
	}

//causes the objects to all be plotted on the grid and the time of the game (number of moves)
void Model::display(View &view)
{
	cout<<"Time: "<< time<< endl;
	view.clear();
	for (int j=0; j< num_persons; j++)
	{
	if (person_ptrs[j]->is_alive())
	{
		view.plot(person_ptrs[j]);
	}
	}
	for (int k=0; k< num_mines; k++)
	{
		view.plot(mine_ptrs[k]);
	}
	for (int l=0; l< num_halls; l++)
	{
		view.plot(hall_ptrs[l]);
	}
view.draw();
}

//shows all the objects on the game
void Model::show_status()
{
	for (int i=0; i<num_objects; i++)
	{
		object_ptrs[i]->show_status();
	}
}

