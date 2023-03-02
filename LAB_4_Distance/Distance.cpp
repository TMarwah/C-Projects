#include "Distance.h"
#include <cstdlib>
#include <cmath>

void Distance::init(){
    _feet = fabs(_feet);
    if (_inches < 0){
        _inches = -_inches;
    }
    
    while (_inches >=12) {
        _inches -= 12.0;
        ++_feet;
    }
    
}

Distance::Distance(){
    _feet = 0;
    _inches = 0.0;
}


Distance::Distance(unsigned ft, double in){
    _feet = ft;
    _inches = in;
    init();
}

Distance::Distance(double in){
    _feet = 0;
    _inches = in;
    init();
}

unsigned Distance::getFeet() const{
    return _feet;
}

double Distance::getInches() const{
    return _inches;
}

double Distance::distanceInInches() const{
    double disInInch = 0.0;
    disInInch += _feet * 12.0;
    disInInch += _inches;

    return disInInch;
}

double Distance::distanceInFeet() const{
    double disInFeet = 0.0;
    disInFeet += _feet * 1.0;
    disInFeet += _inches / 12.0;

    return disInFeet;
}

double Distance::distanceInMeters() const{
    double disInMeters = 0.0;
    //find inches
    disInMeters += distanceInInches();
    //convert to meters
    disInMeters = disInMeters * 0.0254;

    return disInMeters;
}

Distance Distance::operator+(const Distance &rhs) const{
    Distance addedDistance;
    addedDistance._inches = distanceInInches() + rhs.distanceInInches();
    addedDistance.init();

    return addedDistance;
}

Distance Distance::operator-(const Distance &rhs) const{
    Distance subtractedDistance;
    subtractedDistance._inches = distanceInInches() - rhs.distanceInInches();
    subtractedDistance.init();

    return subtractedDistance;
}

ostream & operator<<(ostream &out, const Distance &rhs){

    out << rhs._feet << "' " << rhs._inches << "\"";
    return out;
}
