#include "Cart_Point.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Cart_Vector.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Person.h"

#ifndef MINER_H
#define MINER_H
class Miner: public Person
{
private:
double amount;
Gold_Mine* mine;
Town_Hall* home;

public:
Miner();
Miner (int, Cart_Point);
bool update();
void start_mining(Gold_Mine*, Town_Hall*);
void show_status();
~Miner();
};
#endif

