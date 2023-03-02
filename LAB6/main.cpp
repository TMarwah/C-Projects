#include <iostream>
#include <stdexcept>
#include "IntVector.h"
using namespace std;

int main(){
    //TEST NO PARAM CONSTRUCTOR
    IntVector noparam;
    //TEST PARAM CONSTRUCTOR
    IntVector withparam(10, 10);

    //RETURN SIZES OF TEST OBJECTS
    cout << noparam.size() << endl;
    cout << withparam.size() << endl;

    //RETURN CAPACITY OF TEST OBJECTS
    cout << noparam.capacity() << endl;
    cout << withparam.capacity() << endl;

    //TEST OUT OF RANGE
    cout << "With param index 5 is: " << withparam.at(5) << endl;
    cout << "Out of range is: " << withparam.at(12) << endl;

    //TEST EMPTY
    cout << "Check if noparam is empty: " << noparam.empty() << endl;
    cout << "Check if withparam is empty: " <<withparam.empty() << endl;

    //TEST FRONT RETURN
    cout << "Withparam object front is: " << withparam.front() << endl;

    //TEST BACK RETURN
    cout << "Withparam object back is: " << withparam.back() << endl;

    return 0;
}