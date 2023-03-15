#pragma once
#include "IntList.h"
using namespace std;

class SortedSet : public IntList {
    public:
    //constructors and destructors
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();

    //accessors
    const bool in(int value) const;
    const SortedSet operator|(const SortedSet &rhs) const;
    const SortedSet operator&(const SortedSet &rhs) const;

    //mutators
    void add(int value);
    void push_front(int value);
    void push_back(int value);
    void insert_ordered(int value);
    SortedSet & operator|=(const SortedSet &rhs);
    SortedSet & operator&=(const SortedSet &rhs);
};