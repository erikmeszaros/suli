#include "Character_Class.h"
#include <iostream>

using namespace std;

	//constructor
	Character::Character(string char_name,  int char_hp, int char_dmg ) {
		setName(char_name);
		setHp(char_hp);
		setDamage(char_dmg);
	}
	//destructor
	Character::~Character() {
		cout << getName() << " destroyed. \n";
	};
	//setters
	void Character::setName(string char_name) {
		name = char_name;
	}
	 void Character::setHp(int char_hp) {
		hp = char_hp;
	}
	void Character::setDamage(int char_dmg) {
		damage = char_dmg;
	}
	//getters
	string Character::getName() {
		return name;
	}
	int Character::getHp() {
		return hp;
	}
	int Character::getDamage() {
		return damage;
	}
