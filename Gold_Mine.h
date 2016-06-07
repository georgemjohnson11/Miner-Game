#include "Cart_Point.h"
#include "Game_Object.h"

#ifndef GOLD_MINE_H
#define GOLD_MINE_H
class Gold_Mine: public Game_Object
{
private:
double amount;

public:
Gold_Mine();
Gold_Mine(int, Cart_Point);
bool is_empty();
double dig_gold(double amount_to_dig=35);
bool update();
void show_status();
~Gold_Mine();
};
#endif

