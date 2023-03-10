#include <cstdlib>
#include <cmath>
#include "IntList.h"
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}
//testing
IntList::~IntList(){
    while (!empty()){
        pop_front();
    }
}

IntList::IntList(const IntList& cpy):
head(nullptr),
tail(nullptr)
{
    for(const IntNode* origList = cpy.head; origList != nullptr ; origList = origList->next){
        push_back(origList->value);
    }
}
void IntList::push_front(int value){
    if (tail != nullptr){
        IntNode *tempNode = new IntNode(value);
        tempNode->next = head;
        head = tempNode;
        tempNode = nullptr;
    }
    else if(tail == nullptr) {
        IntNode *tempNode =  new IntNode(value);
        head = tempNode;
        tail = tempNode;
        tempNode = nullptr;
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

void IntList::push_back(int value){
    //if non-empty list
    if (tail != nullptr){
        IntNode *tempNode = new IntNode(value); //new node
        tail->next = tempNode; //assign node to back using ->next on tail
        tempNode->next = nullptr; //assign new tail ->next with nullptr, marking end of list
        tail = tempNode; //assign new tail
        tempNode = nullptr;
    }
    //if empty list
    else if(tail == nullptr) {
        IntNode *tempNode = new IntNode(value); //new node
        head = tempNode; //head and tail both equal new node as it is the only element
        tail = tempNode;
        tempNode->next = nullptr; //mark end of list with nullptr
        tempNode = nullptr;
    }
    


}
void IntList::clear(){
    while (tail != nullptr){
        pop_front();
        //testing head and tail reassignments
        //cout << "current head = " << head << " current tail = " << tail << endl;
    }
}

void IntList::selection_sort(){
    unsigned int numOfNodes = 0;

    IntNode* counter = head;
    
    while(counter != nullptr){
        ++numOfNodes;
        counter = counter->next;
    }
    //count test
    //cout << numOfNodes << endl;
    IntNode* subPoint = head;
    IntNode* min = head;
    IntNode* currentNode = subPoint;
    for (unsigned int i = 0 ; i < numOfNodes ; ++i){
        currentNode = subPoint;
        for (unsigned int k = i ; k < numOfNodes ; ++k){
            //checkpoint test
           //cout << subPoint->value << " " << currentNode->value << endl;
            if (currentNode->value < min->value){
                min = currentNode;
                //min val test
                //cout << min->value << endl;
            }
            currentNode = currentNode->next;
        }
        int temp = subPoint->value;
        subPoint->value = min->value;
        min->value = temp;
        //move min and subpoint pointers to exclude head aka min val
        subPoint = subPoint->next;
        min = subPoint;
    }

    //check node counter
    //cout << numOfNodes << endl;
    //remove dangling
    subPoint = nullptr;
    min = nullptr;
    currentNode = nullptr;
    counter = nullptr;


}

void IntList::insert_ordered(int value){
    IntNode* insertNode = new IntNode(value);
    if (head == nullptr && tail == nullptr){
        head = insertNode;
        tail = insertNode;
        insertNode->next = nullptr;
        insertNode = nullptr;
        return;
    }
    else if(head == tail){
        if(head->value > value){
            push_front(value);
        }else{
            push_back(value);
        }
    }
    else{
        if (head->value >= value){
            push_front(value);
            return;
        }else if (tail->value <= value){
            push_back(value);
            return;
        }
        for(IntNode* lowNode = head ; lowNode != nullptr ; lowNode = lowNode->next){
            IntNode* highNode = lowNode->next;
            if (lowNode->value < value && highNode->value >= value){
                IntNode* temp = highNode;
                lowNode->next = insertNode;
                insertNode->next = temp;
                temp = nullptr;
                lowNode = nullptr;
                highNode = nullptr;
                return;
            }
        }
    }
}

void IntList::remove_duplicates(){
    //cout << "HEAD IS " << head << endl;
    //cout << "TAIL IS " << tail << endl;
    if (head == nullptr && tail == nullptr){
        //edge case test
        //cout << "THIS LIST IS EMPTY" << endl;
        return;
    }
    else if(head == tail){
        //edge case test
        //cout << "THIS LIST HAS 1 VALUE" << endl;
        return;
    }
    else{
        for(IntNode* subpoint = head ; subpoint != nullptr ; subpoint = subpoint->next){
            IntNode* lowNode = subpoint;
            //cout << "subpoint is currently: " << subpoint->value << " compared to";
            for(IntNode* highNode = subpoint->next ; highNode != nullptr ; highNode = lowNode->next){
                //cout << " " << highNode->value << endl;
                //cout << "low node is: " << lowNode->value << endl;
                //cout << subpoint->value << " "<< lowNode->value << " " << highNode->value << endl;
                if (highNode->value == subpoint->value){
                    IntNode* temp = highNode;
                    if (highNode->next == nullptr){
                        lowNode->next = nullptr;
                        tail = lowNode;
                        delete temp;
                        temp = nullptr;
                    }else{
                        lowNode->next = highNode->next;
                        delete temp;
                        temp = nullptr;
                    }
                }else{
                    lowNode = lowNode->next;
                }
               
            }
            if ( subpoint->next == nullptr){
                //remove dangling
                lowNode = nullptr;
            }
        }
    }
}
IntList & IntList::operator =(const IntList& rhs){
    //check for empty list aka head is nullptr
    if(rhs.head == nullptr){ 
        head = nullptr;
        tail = nullptr;
        return *this; //assign new list pointer to null
    }
    //ensure new list is not the old list
    if(this != &rhs){
        clear();
        for(const IntNode* currentNode = rhs.head ; currentNode != nullptr ; currentNode = currentNode->next){
            push_back(currentNode->value);
        }
    }
    return *this; //assign new pointer to lhs list
}

ostream & operator<<(ostream& out, const IntList & outputList){
    //start at null
    IntNode *outputNode = nullptr;
    //assign head
    outputNode = outputList.head;

    //head/tail assignment tests
    //cout << "current head: " << outputList.head << " current tail: " << outputList.tail << endl;
    //while not at the end, print out values
    while (outputNode != nullptr){
        //if not last value, print spaces
        if(outputNode != outputList.tail){
            out << outputNode->value << " ";
        }
        //if last value, do not print space
        if (outputNode == outputList.tail){
            out << outputNode->value;
        }
        //move pointer to next value
        outputNode = outputNode->next;
    }
    outputNode = nullptr;
    return out;
}