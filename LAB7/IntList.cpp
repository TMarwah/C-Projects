#include <cstdlib>
#include <cmath>
#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    while (!empty()){
        pop_front();
    }
}

void IntList::push_front(int value){
    if (tail != nullptr){
        IntNode *tempNode = new IntNode(value);
        tempNode->next = head;
        head = tempNode;
    }
    else if(tail == nullptr) {
        IntNode *tempNode =  new IntNode(value);
        head = tempNode;
        tail = tempNode;
    }
    //check head and tail assignment
    //cout << "head: " << head << " tail: " << tail << endl;
}

void IntList::pop_front(){
    if(head == tail && tail != nullptr ) {
        IntNode *tempNode = head;
        head = nullptr;
        tail = nullptr;
        delete tempNode;
    } 
    else if (tail != nullptr){
        IntNode *tempNode = head;
        head = tempNode->next;
        delete tempNode;
    }
    //check head and tail assignment
    //cout << "head: " << head << " tail: " << tail << endl;
}

bool IntList::empty() const{
    if (tail == nullptr && head == nullptr){
        return true;
    }
    else{
        return false;
    }
}

const int & IntList::front() const{
    return head->value;
}

const int & IntList::back() const{
    return tail->value;
}

ostream & operator<<(ostream& out, const IntList & outputList){
    IntNode *outputNode = nullptr;
    outputNode = outputList.head;
    while (outputNode != nullptr){
        if(outputNode != outputList.tail){
            out << outputNode->value << " ";
        }
        if (outputNode == outputList.tail){
            out << outputNode->value;
        }
        outputNode = outputNode->next;
    }
    return out;
}