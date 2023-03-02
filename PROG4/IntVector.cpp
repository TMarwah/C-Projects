#include <cstdlib>
#include <cmath>
#include "IntVector.h"

IntVector::IntVector(unsigned capacity, int value){
    _size = 0;
    _capacity = capacity;
    _data = new int[_capacity];
    for (unsigned int i = 0 ; i < _capacity ; ++i){
        _data[i] = value;
        ++_size;
        }
    }


IntVector::~IntVector(){
    delete [] _data;
    _data = nullptr;
}

unsigned IntVector::size() const{
    return _size;

}

unsigned IntVector::capacity() const{
    return _capacity;

}

bool IntVector::empty() const{
    if (_size == 0){
        return true;
    }
    else{
        return false;
    }
}

const int & IntVector::at(unsigned index) const{
    if (index >= _capacity){
        throw out_of_range("IntVector::at_range_check");
    }else{
        return _data[index];
    }
}
 
void IntVector::insert(unsigned index, int value){
    if (index > _size){
        throw out_of_range("IntVector::insert_range_check");
    }
    ++_size;
    //IF SIZE WILL EXPCEED CAP, DOUBLE ARRAY SIZE
    if (_size > _capacity){
        expand();
    }

    
    for (unsigned int i = _size ; i > index ; --i){
        _data[i] = _data[i-1];
    }
    
    _data[index] = value;
}

void IntVector::erase(unsigned index){
    if (index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned int i = index ; i < _size - 1 ; ++i){
        _data[i] = _data[i+1];
    }
    _size -= 1;
}

void IntVector::push_back(int value){
    if (_size + 1 > _capacity){
        expand();
    }
    _size += 1;
    _data[_size - 1] = value;
}

void IntVector::pop_back(){
    _size -= 1;
}
void IntVector::clear(){
    _size = 0;
}

const int & IntVector::front() const{
    return _data[0];
}

int & IntVector::front(){
    return _data[0];
}
const int & IntVector::back() const{
    return _data[_size - 1];
}

int & IntVector::back(){
    return _data[_size - 1];
}

void IntVector::resize(unsigned size, int value){
    if (_capacity == 0){
        expand(size);
    }
    if(size > _capacity){
        if (_capacity * 2 > _capacity + (size - _capacity)){
            expand();
        }
        else{
            expand(size - _capacity);
        }
    }
    if (size < _size){
        _size = size;
    }
    else if (size > _size)
    {
        for (unsigned int i = _size ; i < size ; ++i){
            _data[i] = value;
        }
        _size = size;
    }
}

void IntVector::reserve(unsigned n){
    if (n > _capacity){
        _capacity = n;
    }
}

void IntVector::assign(unsigned n, int value){
    if (_capacity == 0){
        expand(n);
    }
    if(n > _capacity){
        if (_capacity*2 > _capacity + (n - _capacity)){
            expand();
        }
        else{ 
            expand(n - _capacity); 
        }
    }
    _size = n;

    for (unsigned int i = 0 ; i < _size ; ++i){
        _data[i] = value;
    }
}
int & IntVector::at(unsigned index){
    if (index >= _capacity){
        throw out_of_range("IntVector::at_range_check");
    }else{
        return _data[index];
    }
}

void IntVector::expand(){
    if (_capacity == 0){
        delete _data;
        _capacity = 1;
        _data = new int[_capacity];
    }
    else{
        _capacity *= 2; //double cap
        int* expData = new int[_capacity]; //create new sized array
        for (unsigned int i = 0 ; i < _size ; ++i){
            expData[i] = _data[i]; //copy data to new array
        }
        delete [] _data;
        _data = expData;
        expData = nullptr; //remove dangle
    }
}
void IntVector::expand(unsigned amount){
        _capacity += amount; //increase cap
        int* expData = new int[_capacity]; //create new sized array
        for (unsigned int i = 0 ; i < _size ; ++i){
            expData[i] = _data[i]; //copy data to new array
        }
        delete [] _data;
        _data = expData;
        expData = nullptr; //remove dangle
}