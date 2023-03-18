#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool rCopy(const string&, const string& ); 
bool rCopyH(ifstream& , ofstream& );

int main(int argc, char* argv[]){
    //set file names
    string inputFile = argv[1];
    string outputFile = argv[2];
    rCopy(inputFile, outputFile);

    return 0;
}
bool rCopyH(ifstream& inputFile, ofstream& outputFile){
    bool copycont = false;
    char ch;
    if (inputFile.get(ch)){
        //if chars are still read then keep copying
        copycont = rCopyH(inputFile, outputFile);
        outputFile << ch;
        copycont = true;
        
    }
    //done copying
    return copycont;
}
bool rCopy(const string& inputFile, const string& outputFile){
    bool toCopy;
    ifstream inFS;
    ofstream outFS;

    inFS.open(inputFile);
    if (!inFS.is_open()){
        //fail check
        cout << "Error opening " << inputFile << endl;
        cout << "Copy not completed" << endl;
        return toCopy = false;
    }

    //fail check
    outFS.open(outputFile);
    if (!outFS.is_open()){
        //outstream fail check
        cout << "Error opening " << outputFile << endl;
        cout << "Copy not completed" << endl;
        return toCopy = false;
    }
    //grab values if opened properly
    toCopy = rCopyH(inFS, outFS);

    inFS.close();
    outFS.close();

    return toCopy;
}