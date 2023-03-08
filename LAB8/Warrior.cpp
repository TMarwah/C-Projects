#include <iostream>
using namespace std;
#include "Warrior.h"

//constructor character with warrior typing, add allegiance
Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance)
:Character(WARRIOR, name, health, attackStrength) , allegiance(allegiance){}

void Warrior::attack(Character &enemy){
    if(enemy.getType() == WARRIOR){
        Warrior &enemyWarrior = dynamic_cast<Warrior &>(enemy);

        //if the enemy allegiance is the same as attacker allegiance
        if (enemyWarrior.allegiance == allegiance){
            cout << "Warrior " << name << " does not attack Warrior " << enemy.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;

        }
        else{
            double damage = (health / MAX_HEALTH) * attackStrength;
            enemy.damage(damage);
            cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
            cout << enemy.getName() <<  " takes " << damage << " damage." << endl;
            
        }
    }
    else
    {
        double damage = (health / MAX_HEALTH) * attackStrength;
        enemy.damage(damage);
        cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
        cout << enemy.getName() <<  " takes " << damage << " damage." << endl;

    }
}