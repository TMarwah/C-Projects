//include any standard libraries needed
#include <iostream>
#include <fstream>

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize){
   double sum = 0;
   for ( int i = 0 ; i < arraySize ; ++i){
      sum += array[i];
   }
   return sum / arraySize;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){
   double temp = array[arraySize - 1];
   if (index == arraySize - 1){
      arraySize -= 1;
   }else{
      for ( int i = index ; i < arraySize ; ++i){
         array[i] = array[i+1];
      }
      arraySize -= 1;

      array[arraySize - 1] = temp;
   }
   
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
   for ( int i = 0 ; i < arraySize ; ++i){
      if (!(i == arraySize -1)){
         cout << array[i] << ", ";
      }
      else{
         cout << array[i];
      }
   }
}


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   string filename = argv[1];

   // open file and verify it opened
   ifstream inFS(filename);
   if (!inFS.is_open()){
      cout << "Failed to open file " << filename;
   }
   // Declare an array of doubles of size ARR_CAP.
   double array[ARR_CAP];

    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   double VAL = 0.0;
    int i = 0;
   while(inFS >> VAL){
      array[i] = VAL;
      ++i;
   }
    
   // Call the mean function passing it this array and output the 
   // value returned.
    int arraySize = i;
    cout << "Mean: "<< mean(array, arraySize) << endl;
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   cout << endl;
   cout << "Enter index of value to be removed (0 to " << arraySize - 1 <<") :" << endl;
   unsigned int indexToRemove;
   cin >>indexToRemove;

	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(array, arraySize);
   cout << endl;
   cout << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(array, arraySize, indexToRemove);
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(array, arraySize);
   cout << endl;
   cout << endl;
   
   // Call the mean function again to get the new mean
   cout << "Mean: " << mean(array,arraySize) << endl;
   
	return 0;
}