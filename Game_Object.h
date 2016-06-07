#include "Cart_Point.h"

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
class Game_Object
{

public:
	Game_Object();
	Game_Object(char);
	Game_Object(char, int, Cart_Point);
	Cart_Point get_location();
	int get_id();
	virtual void show_status();
	void drawself(char *);
	virtual bool update()=0;
	virtual ~Game_Object();
	virtual bool is_alive();

protected:
	Cart_Point location;
	char display_code;
	char state;

private:
	int id_num;
};
#endif

