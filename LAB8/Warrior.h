#include <string>
#pragma once
#include "Character.h"
using namespace std;

class Warrior : public Character{
    private:
        //allegiance attribute
        string allegiance;

    public:
        //warrior construction is same as char, adds allegiance
        Warrior(const string &name, double health, double attackStrength, string allegiance);
        //diff attack style
        void attack(Character &);
};