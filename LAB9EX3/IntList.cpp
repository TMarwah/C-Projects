#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

bool IntList::exists(int value) const{
   //empty list case, no values exist
   if (head == nullptr){
      return false; 
   }
   //if the head is the data, then it must exist
   if (head->value == value) {
      return true;
   }
   //check next value
   return exists(head->next, value);
}

bool IntList::exists(IntNode *temp, int value) const{
   //temp takes on the value of head->next
   if (temp == nullptr){
      //if next is null, and head is not value, value must not exist
      return false;
   }
   //check current value
   if (temp->value == value){
      return true;
   }
   //recursively check all values in list by calling exists(next value)
   return exists(temp->next, value);
}
ostream &operator<<(ostream &out, const IntList &rhs){
   //no val
   if (rhs.head == nullptr){
      return out;
   }
   operator<<(out,rhs.head);
   return out;
}

ostream &operator<<(ostream &out, IntNode * rhs){
   //no list, no print
   if (rhs == nullptr){
      return out;
   }
   out << rhs->value;
   if (rhs->next != nullptr){
      //put a space on each value except the last
      out << " ";
   }
   //call again using next value beginning at start node
   operator<<(out, rhs->next);
   return out;
}
