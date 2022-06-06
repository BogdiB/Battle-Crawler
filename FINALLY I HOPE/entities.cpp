#include "entities.h"
#include <cstdlib>
#include <ctime>

entities::entities() {}

void entities::attack(entities enemy)
{
	srand(time(NULL));
	short r = rand() % 101;
	if (r >= 0 && r <= this->critChance)
		enemy.takeDamage(this->damage + 5);
	else
		enemy.takeDamage(this->damage);
}

void entities::heal()
{
	if (this->maxHeals > 0)
	{
		srand(time(NULL));
		this->HP += 25 + (rand() % 10);
		if (this->HP > 100) this->HP = 100;
		--(this->maxHeals);
	}
	// else output a "Heal used the maximum amount of times for this fight!" message 
}

void entities::takeDamage(short dmg)
{
	if (dmg > 0)
		this->HP -= dmg;
	if (HP < 1)
		this->die();
}

void entities::die()
{
	this->HP = 100;
	this->maxHeals = 1;
	this->~entities();
}

entities::~entities() {}