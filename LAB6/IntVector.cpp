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

const int & IntVector::front() const{
    return _data[0];
}

const int & IntVector::back() const{
    return _data[_capacity - 1];
}