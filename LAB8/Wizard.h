#include <string>
#pragma once
#include "Character.h"
using namespace std;

class Wizard : public Character{
    private:
        //rank attribute
        int rank;

    public:
        //construct with family attribute
        Wizard(const string&name, double health, double attackStrength , int rank);
        void attack(Character &);



};