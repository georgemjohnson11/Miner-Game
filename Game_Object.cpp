#include "Game_Object.h"
#include "Cart_Point.h"
#include "Person.h"
#include <iostream>
using namespace std;

//default object that defines all other classes as a default constructor
Game_Object::Game_Object()
{
	display_code=' ';
	state='s';
	id_num=0;
	cout<< "Game_Object default contructed"<< endl;

}

//Defines the type of object and the default constructor for a state and id number if none are specified
Game_Object::Game_Object(char in_code)
{
	display_code=in_code;
	id_num=0;
	state='s';
	cout<< "Game_Object contructed"<< endl;
}

//gives a type of object to the game object, an id number, and location on the board that the user can specify
Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{
	display_code=in_code;
	state='s';
	id_num=in_id;
	location= in_loc;
	cout<< "Game_Object contructed"<< endl;
}

//allows the location of an object to be retrieved
Cart_Point Game_Object::get_location()
{
	return location;
}

//allows the id of an object to be retrieved
int Game_Object::get_id()
{
	return id_num;
}

//displays the objects type and id
void Game_Object::show_status()
{
	cout<< display_code<< id_num<< location;
}

//generates the object on the game board
 void Game_Object::drawself(char * ptr)
{	
		ptr[0]=display_code;
		char g= id_num+'0';
		ptr[1]=g;
}

 //deconstructor for object to prevent overloading
 Game_Object::~Game_Object()
 {
	 cout<< "Game_Object deconstructed"<< endl;
 }

 //checks if object is alive (utilized for persons
 bool Game_Object::is_alive()
 {
	 return true;
 }
