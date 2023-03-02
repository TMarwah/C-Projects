#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   int inputs;
   int sum = 0;
   int counter = 0;
   int avg;
   char junk;
   vector<int> inputNumsVec;

   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);
   // Verify file opened correctly.
   if (!inFS.is_open()){
      // Output error message and return 1 if file stream did not open correctly.
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
   // Read in integers from input file to vector.
   while (inFS >> inputs){
      inputNumsVec.push_back(inputs);
      inFS >> junk;
   }

   // Close input stream.
   inFS.close();
   // Get integer average of all values read in.
   for (unsigned int i = 0 ; i < inputNumsVec.size() ; ++i){
      sum += inputNumsVec.at(i);
      ++counter;
   }
   avg = sum / counter;
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0 ; i < inputNumsVec.size() ; ++i){
      inputNumsVec.at(i) = inputNumsVec.at(i) - avg;
   }
   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()){
      cout << "Error opening " << outputFile << endl;
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0 ; i < inputNumsVec.size() ; ++i){
      if (!(i == inputNumsVec.size() - 1)){
      outFS << inputNumsVec.at(i) << ",";
      }
      else{
         outFS << inputNumsVec.at(i);
      }
      
   }
   // Close output stream.
   outFS.close();
   return 0;
}