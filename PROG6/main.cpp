#include "IntList.h"
#include "SortedSet.h"
#include <random>
//testing github push
#include <iostream>
using namespace std;
//testing command line push
int main() {
   string spacer = "------------------------------------------";
   srand(15);
   IntList testList;
   cout << "Created empty test list" << testList << endl;

   //INITIALIZE NEW TEST LIST WITH UNSORTED VALUES//
   cout << spacer << endl;
   for ( unsigned int i = 0 ; i < 5 ; ++i){
      int num = rand() % 25;
      testList.push_back(num);
   }
   cout << "Random pushback list: " << testList << endl;
   SortedSet sset1;
   cout << "Empty SortedSet created" << endl;
   cout << endl;

   //INTLIST COPY CONSTRUCTOR TEST//
   cout << spacer << endl;
   sset1 = testList;
   cout << "Copy testList to sset1 results in: " << sset1 << endl;
   cout << endl;

   //SORTEDSET COPY CONSTRUCTOR TEST//
   cout << spacer << endl;
   SortedSet sset2;
   sset2 = sset1;
   cout << "Copy sset2 to sset1 results in: " << sset2 << endl;
   cout << endl;

   //ADD FUNCTION TEST//
   cout << spacer << endl;
   cout << "Adding 3, 5, 2 into sset1" << endl;
   sset1.add(3);
   sset1.add(5);
   sset1.add(2);
   cout << "New sset1: " << sset1 << endl;
   cout << endl;

   //DUPE IGNORE TEST//
   cout << spacer << endl;
   cout << "Adding 3, 5, 2 into sset1 again, checking for dupe ignore" << endl;
   sset1.add(3);
   sset1.add(5);
   sset1.add(2);
   cout << "New sset1: " << sset1 << endl;
   cout << endl;

   //CHECKING IN FUNCTION//
   cout << spacer << endl;
   cout << "Checking IN function" << endl;
   cout << "sset1.in(5) returns " << sset1.in(5) << endl;
   cout << "sset1.in(20) returns " << sset1.in(20) << endl;
   cout << "sset1.in(400) returns " << sset1.in(400) << endl;
   cout << endl;

   //PUSH FRONT, PUSH BACK, INSERT ORDERED TEST//
   cout << spacer << endl;
   cout << "Attempting to push 100 to front" << endl;
   sset1.push_front(100);
   cout << "New sset1: " << sset1 << endl;

   cout << "Attempting to push -100 to back" << endl;
   sset1.add(-100);
   cout << "New sset1: " << sset1 << endl;

   cout << "Attempting to insert 210 ordered" << endl;
   sset1.add(210);
   cout << "New sset1: " << sset1 << endl;
   cout << endl;

   //EMPTY SET TESTS
   cout << spacer << endl;
   SortedSet ssetempty;
   cout << "Adding into empty set" << endl;
   ssetempty.add(15);
   cout << "ssetempty now contains " << ssetempty << endl;
   cout << endl;

   //OPERATOR TESTS//
   cout << spacer << endl;
   SortedSet unionset1;
   unionset1.add(5);
   unionset1.add(47);
   unionset1.add(10);
   unionset1.add(8);
   unionset1.add(142);

   cout <<"Unionset 1: " << unionset1 << endl;
   
   SortedSet unionset2;
   unionset2.add(15);
   unionset2.add(1);
   unionset2.add(142);
   unionset2.add(10);
   unionset1.add(47);

   cout <<"Unionset 2: " << unionset2 << endl;


   cout << "Union of both sets: " << (unionset1 | unionset2) << endl;

   cout << "Intersection of both sets: " << (unionset1 & unionset2) << endl;

   cout << "Applying unionset1 |= unionset2" << endl;
   unionset1 |= unionset2;
   cout << "New unionset1: " << unionset1 << endl;

   SortedSet intersectset1;
   intersectset1.add(5);
   intersectset1.add(12);
   intersectset1.add(15);
   intersectset1.add(140);
   intersectset1.add(142);
   cout << "Created new set intersectset1: " << intersectset1 << endl;
   cout << "Will be intersected with unionset2: " << unionset2 << endl;
   cout << "Applying intersectset1 &= unionset2" << endl;
   
   intersectset1 &= unionset2;
   cout << "New intersectset1: " << intersectset1 << endl;

   cout << endl;

   return 0;
}
