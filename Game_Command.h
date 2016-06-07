
#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H
#include "Model.h"
class Game_Command
{
public:
	void move_function(Model&);
void work_function(Model&);
void stop_function(Model&);
void run_function(Model&);
void go_function(Model&);
void attack_function(Model&);
void list_function(Model&);

};
#endif

