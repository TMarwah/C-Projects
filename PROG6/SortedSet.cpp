#include "SortedSet.h"
#include <cstdlib>
#include <iostream>
#include <cmath>


SortedSet::SortedSet()
    :IntList(){
    //empty set using intlist no param constructor
}

SortedSet::SortedSet(const SortedSet& copy)
    :IntList(copy){
    //copied set using intlist copy constructor
}

SortedSet::SortedSet(const IntList& copy)
    :IntList(copy){
    remove_duplicates();
    selection_sort();
    //copied set using intlist parameter, converted to sorted set
}

SortedSet::~SortedSet(){
    while (!empty()){
        //explicit call does not matter
        pop_front();
    }
}
const bool SortedSet::in(int value) const{
    //for each value in the sortedset
    for (IntNode *currnode = head; currnode != nullptr ; currnode = currnode->next)
    {
        //if the value is found
        if (value == currnode->value){
            return true;
        }
    }
    //no value found
    return false;
}

void SortedSet::add(int value){
    //empty list case
    if (head == nullptr){
        //explicitly call direct push front and not sortedset overriden version
        IntList::push_front(value);
    }
    else{
        //if value is minimum (aka less than head) push front
        if (value < head->value){
            //explicitly call direct push front and not sortedset overriden version
            IntList::push_front(value);
        }
        //if value is maximum (aka greater than head) push back
        else if(value > tail->value){
            //explicity call direct push back and not sortedset overriden version
            IntList::push_back(value);
        }
        else{
            //last case, search through list to find where to input
            IntNode *lownode = head;
            IntNode *highnode= head->next;
            IntNode *temp = new IntNode(value);
            //empty list check included
            while (highnode != nullptr && highnode->next != nullptr){
                //exclusive search, >= not used to remove dupe
                //ex 2 4 5 inserting 4 never enters conditional as > will trigger, not <, then < will trigger but nullptr is highnode->next 
                if ( value > lownode->value && value < highnode->value){
                    temp->next = highnode;
                    lownode->next = temp;
                    lownode = highnode;
                    highnode = highnode->next;
                }
                lownode = highnode;
                highnode = highnode->next;
            }
            if ( value > lownode->value && value < highnode->value){
                    temp->next = highnode;
                    lownode->next = temp;
            }
            //highnode is already set to nullptr through iteration
            lownode = nullptr;
            temp = nullptr;

        }
    }
}

void SortedSet::push_front(int value){
    //add function already accounts for dupe and inserts in order
    add(value);

}

void SortedSet::push_back(int value){
    //add function already accounts for dupe and inserts in order
    add(value);
}

void SortedSet::insert_ordered(int value){
    //add function already accounts for dupe and inserts in order
    add(value);
}

//union operator
const SortedSet SortedSet::operator | (const SortedSet &rhs) const{
    // cout << "here" << endl; checking for call

    //set lhs to object on left hand of operator call
    SortedSet lhs = *this;

    for (IntNode *currentNode = rhs.head ; currentNode != nullptr ; currentNode = currentNode->next){
       //insert all values from rhs into lhs object (union)
       //add functiont takes care of dupe check
       lhs.add(currentNode->value);
    }
    return lhs;
}

//intersection operator
const SortedSet SortedSet::operator & (const SortedSet &rhs) const{
    IntNode* lhs_pointer = this->head;
    //protected access
    IntNode* rhs_pointer = rhs.head;
    IntNode* lhs_store = lhs_pointer;
    SortedSet intersectSet; // set of intersecting values

    while (rhs_pointer != nullptr){
       while (lhs_pointer != nullptr){
            if (rhs_pointer->value == lhs_pointer->value){
                //compile all equal values
                intersectSet.add(rhs_pointer->value);
            }
            lhs_pointer = lhs_pointer->next;
       }
       //once end of compare list is found, reset lhs pointer to start,
       if (lhs_pointer == nullptr){
            lhs_pointer = lhs_store;
       }
       //iterate to next val of rhs, repeat comparison with all lhs values
       rhs_pointer = rhs_pointer->next;
    }
    return intersectSet;
}

//union assignment operator
SortedSet & SortedSet::operator |= (const SortedSet &rhs){
    //values to be added
    IntNode *source_set = rhs.head;
    //lhs aka values to be added into destination set
    IntNode *assign_set = this->head;

    //add all source values into set (union)
    while (source_set != nullptr){
        add(source_set->value);
        source_set = source_set->next;
    }
    //add all desintation values into resulting set
    while (assign_set != nullptr){
        add(assign_set->value);
        assign_set = assign_set->next;
    }

    //returns resulting set pointer, essentially assigning the lhs to the united set
    return *this;
}

//intersect assignment operator
SortedSet & SortedSet::operator &= (const SortedSet &rhs){
    IntNode* lhs_pointer = this->head;
    //protected access
    IntNode* rhs_pointer = rhs.head;
    IntNode* lhs_store = lhs_pointer;

    //setup clean set, so that new heads and tails will be initilized through
    //push_back and push_front base cases present in add function
    head = 0;
    tail = 0;

    while (rhs_pointer != nullptr){
       while (lhs_pointer != nullptr){
            if (rhs_pointer->value == lhs_pointer->value){
                add(rhs_pointer->value);
            }
            lhs_pointer = lhs_pointer->next;
       }
       if (lhs_pointer == nullptr){
            lhs_pointer = lhs_store;
       }
       rhs_pointer = rhs_pointer->next;
    }
    //return value of set with all intersects added
    return *this;
}