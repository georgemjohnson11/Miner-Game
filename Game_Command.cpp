#include "Game_Command.h"
//moves a miner or soldier
void Game_Command::move_function(Model& model)
		{
			int person_num;
			Cart_Point moveto;
			cin>> person_num>> moveto.x>> moveto.y;
			if (person_num>4||person_num<0)
			{
				cout<< "ERROR: Please enter a valid command"<< endl;
			}
		else
		{			
			(model.get_Person_ptr(person_num-1)->start_moving(moveto)); 
		}
}
// lets soldiers attack others
void Game_Command::attack_function(Model& model)
{
	int predator, prey;
	cin>> predator>> prey;
	if (predator>4||predator<0|| prey>4|| prey<0)
	{
		cout<< "ERROR: Please enter a valid command"<< endl;
	}
	else
	{
		model.get_Person_ptr(predator-1)->start_attack(model.get_Person_ptr(prey-1));
	}
}
//lets miners work
void Game_Command::work_function(Model& model)
{
	int gold_num, th_num, person_num;
	cin>>person_num>> gold_num>> th_num;
	if (person_num>4||person_num<0|| gold_num>2|| gold_num<0||th_num!=1)
	{
		cout<< "ERROR: Please enter a valid command"<< endl;
	}
	else 
	{
		(model.get_Person_ptr(person_num-1))->start_mining(model.get_Gold_Mine_ptr(gold_num-1), model.get_Town_Hall_ptr(th_num-1));
	}
}
//stops moving persons
void Game_Command::stop_function(Model& model)
	{
		int person_num;
		cin>> person_num;
		if (person_num>4||person_num<0)
		{
			cout<< "ERROR: Please enter a valid command"<< endl;
		}
		else
		model.get_Person_ptr(person_num-1)->stop();
}
//updates time and makes things the board move  5 times
void Game_Command::run_function(Model& model)
{
	int counter;
	counter=1;
	while ( (model.update()) & (counter<5))
	{	
		counter++;
	}			
	model.show_status();
}
//updates the entire board once
void Game_Command::go_function(Model& model)
{
	model.update();
}
//makes show status
void Game_Command::list_function(Model& model)
{
	model.show_status();
}



