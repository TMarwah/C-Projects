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
    //cout << "Out of range is: " << withparam.at(12) << endl;

    //TEST EMPTY
    cout << "Check if noparam is empty: " << noparam.empty() << endl;
    cout << "Check if withparam is empty: " <<withparam.empty() << endl;

    //TEST FRONT RETURN
    cout << "Withparam object front is: " << withparam.front() << endl;

    //TEST BACK RETURN
    cout << "Withparam object back is: " << withparam.back() << endl;

    //INSERT TEST
    withparam.insert(5,5);

    for (unsigned int i = 0 ; i < withparam.size() ; ++i){
        cout << withparam.at(i) << " ";
    }
    cout << endl;
    cout << "inserted 5 at index 5. currently index 5 holds: " << withparam.at(5) << endl;
    cout << endl;
    cout <<"current size is " << withparam.size() << endl << "current capacity is " << withparam.capacity() << endl;

    //OUT OF RANGE INSERT TEST
    //withparam.insert(21,21);
    
    //ERASE TEST
    cout << "erasing index 5, new array is" << endl;
    withparam.erase(5);
    for (unsigned int i = 0 ; i < withparam.size() ; ++i){
        cout << withparam.at(i) << " ";
    }
    cout << endl;

    //PUSH_BACK TEST
    cout << "pushing back '25' , new array is" << endl;
    withparam.push_back(25);
    for (unsigned int i = 0 ; i < withparam.size() ; ++i){
        cout << withparam.at(i) << " ";
    }
    cout << endl;

    //POP_BACK TEST
    cout << "popping off 25" << endl;
    withparam.pop_back();

    //RESIZE TEST
    cout << "resizing array to size 5" << endl;
    withparam.resize(5);

    for (unsigned int i = 0 ; i < withparam.size() ; ++i){
        cout << withparam.at(i) << " ";
    }
    cout << endl;

    cout << "resizing array to size 15, filling new elements with '11'" << endl;
    withparam.resize(15, 11);

    for (unsigned int i = 0 ; i < withparam.size() ; ++i){
        cout << withparam.at(i) << " ";
    }
    cout << endl;
   

    //RESERVE TEST
    cout << "reserving 20 addresses (changing cap to 20)" << endl;
    withparam.reserve(20);
    cout << "new cap is " << withparam.capacity() << endl;

    //ASSIGN TEST
    cout << "assigning 5 array values to 40" << endl;
    withparam.assign(5, 40);
    for (unsigned int i = 0 ; i < withparam.size() ; ++i){
        cout << withparam.at(i) << " ";
    }
    cout << endl;   

    //FRONT BACK MUTATOR
    cout << "assigning front and back with 0" << endl;
    withparam.front() = 0;
    withparam.back() = 0;
    for (unsigned int i = 0 ; i < withparam.size() ; ++i){
        cout << withparam.at(i) << " ";
    }
    cout << endl; 

    cout << withparam.size() << endl;
    cout << withparam.capacity() << endl;

    //insert test
    cout << "inserting a value into index 4" << endl;
    withparam.insert(4, 5);
    cout << withparam.at(5) << endl;
    //check if added properly
    cout << "val at index 3 is: " << withparam.at(3) << endl;
    for (unsigned int i = 0 ; i < withparam.size() ; ++i){
        cout << withparam.at(i) << " ";
    }
    cout << endl; 

    //TESTING INSERT OUT OF RANGE
    cout << "erasing value in index 5" << endl;
    cout << withparam.size() << endl;

    //check if erased properly
    cout << "val at index 3 is: " << withparam.at(3) << endl;
    for (unsigned int i = 0 ; i < withparam.size() ; ++i){
        cout << withparam.at(i) << " ";
    }
    cout << endl; 

    //check empty array insert
    cout << "inserting 287 into empty array " << endl;
    cout << noparam.size() << endl; //size initial
    cout << noparam.capacity() << endl;
    noparam.insert(0,287);
    cout << noparam.size() << endl; //size post insert
    cout << noparam.capacity() << endl;
    cout << noparam.at(0) << endl;
    cout << endl; 
    return 0;
}