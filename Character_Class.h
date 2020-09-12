#include <string>
#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H


class Character
{
public:
	//constructor
	Character(std::string char_name, int char_hp, int char_dmg);
	//destructor
	~Character(); 
	//setters
	void setName(std::string char_name);
	void setHp(int char_hp);
	void setDamage(int char_dmg);
	//getters
	std::string getName();
	int getHp();
	int getDamage();

private:
	int hp, damage;
	std::string name;
};



#endif
