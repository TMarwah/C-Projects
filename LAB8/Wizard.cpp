#include <iostream>
using namespace std;
#include "Wizard.h"

Wizard::Wizard(const string&name , double health, double attackStrength, int rank)
: Character(WIZARD, name, health, attackStrength) , rank(rank){}
//multi file gitpush test
void Wizard::attack(Character &enemy){
    if (enemy.getType() == WIZARD){
        Wizard &enemyWizard = dynamic_cast<Wizard &>(enemy);
        double damage = attackStrength * (rank * 1.0 / enemyWizard.rank);
        enemyWizard.damage(damage);
        cout << "Wizard " << name << " attacks " << enemyWizard.getName() << " --- POOF!!" << endl;
        cout << enemyWizard.getName() <<  " takes " << damage << " damage." << endl;
    }else{
        double damage = attackStrength;
        enemy.damage(damage);
        cout << "Wizard " << name << " attacks " << enemy.getName() << " --- POOF!!" << endl;
        cout << enemy.getName() <<  " takes " << damage << " damage." << endl;

    }
}
