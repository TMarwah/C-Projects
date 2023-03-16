#include "IntList.h"
#include <cstdlib>
using namespace std;


bool IntList::bubbleUp() {
   IntNode *curr = head;
   if (curr == nullptr){
      return false;
   }
   return bubbleUp(curr);
}

bool IntList::bubbleUp(IntNode *curr) {    
   bool shouldSwap = false;  //if node is the last one, value is not 
   //if not at tail  
   if (curr->next){   
      //recursive call on next node      
      shouldSwap = bubbleUp(curr->next);
      //if value after curr is smaller than curr, swap them (bubble up minimum)
      if (curr->next->value < curr->value){
         //swap
         swap(curr->next->value, curr->value);
         //return true after swapping occurs
         return true;    
     }
   }
   return shouldSwap;    
}     
     
     
