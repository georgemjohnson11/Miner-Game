#include "Game_Object.h"
#include "Cart_Point.h"
#include "Person.h"
#include <iostream>
using namespace std;

Game_Object::Game_Object()
{
	display_code=' ';
	state='s';
	id_num=0;
	cout<< "Game_Object default contructed"<< endl;

}

Game_Object::Game_Object(char in_code)
{display_code=in_code;
	id_num=0;
	state='s';
	cout<< "Game_Object contructed"<< endl;
}

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{display_code=in_code;
	state='s';
	id_num=in_id;
	location= in_loc;
	cout<< "Game_Object contructed"<< endl;
}

Cart_Point Game_Object::get_location()
{
	return location;
}

int Game_Object::get_id()
{
	return id_num;
}

void Game_Object::show_status()
{
	cout<< display_code<< id_num<< location;
}

 void Game_Object::drawself(char * ptr)
{	
		ptr[0]=display_code;
		char g= id_num+'0';
		ptr[1]=g;
}

 Game_Object::~Game_Object()
 {
	 cout<< "Game_Object deconstructed"<< endl;
 }

 bool Game_Object::is_alive()
 {
	 return true;
 }
