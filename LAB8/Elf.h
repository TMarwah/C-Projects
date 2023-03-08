#include <string>
#pragma once
#include "Character.h"
using namespace std;

class Elf : public Character{
    private:
        //family attribute
        string family;
    
    public:
        //construct with family attribute
        Elf(const string&name, double health, double attackStrength , string family);
        void attack(Character &);

};