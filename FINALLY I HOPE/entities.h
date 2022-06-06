#pragma once


class entities
{
	short HP = 100, damage = 7, critChance = 8, maxHeals = 1;
	public:
		entities();
		entities(const entities&) = default;
		void attack(entities enemy);
		void heal();
		void takeDamage(short dmg);
		void die();
		~entities();
};