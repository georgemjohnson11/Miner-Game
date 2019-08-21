#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include <cmath>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <cctype>
#include "Model.h"
#include "Game_Object.h"
#include "View.h"
#include "Person.h"
#include "Game_Command.h"
#include <iostream>
using namespace std;
#include <string>



int main()
{
	char terminator;
	terminator='k';

	Game_Command m, w, s, r, g, a, l;
	View v1;
	v1=View();
	Model model=Model();
	model.show_status();
	
	while (terminator != 'q')
	{
		model.display(v1);
	cout<< "\nEnter command: ";
	cin>>terminator;
	if ((isalpha(terminator)) && (cin.good()))
		{switch (terminator)
		{case 'm':
			m.move_function(model);
		break;
		case 'w':
			w.work_function(model);
			break;
		case 's':
			s.stop_function(model);
			break;
		case 'r':
			{
			r.run_function(model);
			break;
			}
		case 'g':
			g.go_function(model);
			break;
		case 'a':
			a.attack_function(model);
			break;
		case 'l':
			l.list_function(model);
			break;
		case 'q':
			terminator='q';
			cout<< "Terminating program."<< endl;
			model.~Model();
			break;
		default: 
		cout<< "That command doesn't exist\n"<< endl;
			break;
		}
	}
	else if (cin.fail())
	{cin.clear();
	cout<< "Not a valid command"<< endl;}
	else
			{cout<< "Not a valid command."<< endl;}
	}
	return 0;
	}

