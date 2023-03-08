#include <iostream>
using namespace std;
#include "Elf.h"

Elf::Elf(const string&name, double health, double attackStrength , string family)
: Character(ELF, name, health, attackStrength) , family(family){}

void Elf::attack(Character &enemy){
    if(enemy.getType() == ELF){
        Elf &enemyElf = dynamic_cast<Elf &>(enemy);

        //if the enemy family is the same as attacker family
        if (enemyElf.family == family){
            cout << "Elf " << name << " does not attack Elf " << enemy.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;

        }
        else{
            double damage = (health / MAX_HEALTH) * attackStrength;
            enemy.damage(damage);
            cout << "Elf " << name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
            cout << enemy.getName() <<  " takes " << damage << " damage." << endl;
            
        }
    }
    else{
        double damage = (health / MAX_HEALTH) * attackStrength;
        enemy.damage(damage);
        cout << "Elf " << name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
        cout << enemy.getName() <<  " takes " << damage << " damage." << endl;

    }

}
