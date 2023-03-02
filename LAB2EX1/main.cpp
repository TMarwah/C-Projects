#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename);

int main() {

   string filename;
   int sum = 0;
   fstream finstream(filename);
   cout << "Enter the name of the input file: ";
   cin >> filename;
   finstream.open(filename);
   cout << endl;
   if (!finstream.is_open()){
      cout << "Error opening " << filename << endl;
      return(0);
   }
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(string filename){
   int value;
   int sum = 0;
   fstream finstream(filename);

   while (finstream >> value){
      sum += value;
   }
   return sum;
}