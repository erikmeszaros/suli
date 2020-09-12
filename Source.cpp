#include <iostream>
#include <sstream>
#include "Character_Class.h"

using namespace std;

void stat_kiir(Character* player){  //const??
	cout << player->getName() << "\t HP: " << player->getHp() << " , DMG: " << player->getDamage() << endl;
}

bool isDead(Character* player){ //const??
	return player->getHp()<=0;
}

void game_master(Character* player1, Character* player2){
	int turn=1;
	bool dead=false;
	while (!dead){
		stat_kiir(player1);stat_kiir(player2);
		switch (turn){
			case 1:
				cout<<player1->getName()<<" -> "<<player2->getName()<<endl;
				player2->setHp(player2->getHp() - player1->getDamage());
				turn=2;
				if (isDead(player2)){
					dead=true;
					cout<< player2->getName()<<" died. "<< player1->getName()<<" wins.\n";
				}
				break;
			case 2:
				cout<<player2->getName()<<" -> "<<player1->getName()<<endl;
				player1->setHp(player1->getHp() - player2->getDamage());
				turn=1;
				if (isDead(player1)){
					dead=true;
					cout<< player1->getName()<<" died. "<< player2->getName()<<" wins.\n";
				}
				break;
			default: cerr<<"Turn can only be 1 or 2!";
		}	
	}
}

int main(int argc, char* argv[]) {
	cout << "Program running: " << argv[0] << endl;
	cout << "2 characters with 3 parameters each (name, HP, dmg)\n";
	if (argc != 7) {
		cout << argv[0] << " 2 characters with 3-3 parameters\n";
	}
	else {
		// command prompt parameters
		stringstream ss;
		ss << argv[1] << " " << argv[2] << " " << argv[3] << " " << argv[4] << " " << argv[5] << " " << argv[6];
		string name1, name2;
		int hp1, hp2, dmg1, dmg2;
		ss >> name1 ; ss >> hp1; ss >> dmg1; ss >> name2; ss >> hp2; ss >> dmg2;
		
		Character player1(name1, hp1, dmg1);
		Character player2(name2, hp2, dmg2);
		
		game_master(&player1,&player2);

	}

	return 0;
}