#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//FUNCTION PROTOS//
void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char *argv[]) {

    //VAR DEFINITIONS//
    string datafile;
    vector <double>FPAVec; //flight path angle data
    vector <double>COLVec; //coefficient of lift data
    double inputFPA;
    bool repeat = true;
    string response;

    //take and read input files
    datafile = argv[1];
    readData(datafile, FPAVec, COLVec);

    //check if FPA vals are ordered
    if (isOrdered(FPAVec)){
        //FPA is ordered
    }else{
        reorder(FPAVec, COLVec);
    }
    while (repeat){
        cout << "Enter a flight-path angle: ";
        cin >> inputFPA;
        cout << "Interpolated Coefficient of Lift is: " << interpolation(inputFPA, FPAVec, COLVec) << endl;

        cout << "Would you like to enter another angle? (Yes/No): ";
        cin >> response;
        if (response== "Yes"){
            repeat = true;
        }
        else if(response == "No"){
            repeat = false;
        }
    }
}

void readData(const string &datafile , vector<double> &FPAVec, vector<double> &COLVec){
    ifstream inFS;
    double value;
    inFS.open(datafile);
    if (!inFS.is_open()){
        cout << "Error opening " << datafile << endl;
        exit(1);
    }

    while (inFS >> value){
        FPAVec.push_back(value);
        inFS >> value;
        COLVec.push_back(value);
    }
    inFS.close();
}

double interpolation(double inputFPA, const vector<double> &FPAVec, const vector<double> &COLVec){
    bool inputInSet = false;
    int inSetIndex;
    int lowerBoundIndex;
    for (unsigned int i = 0; i < FPAVec.size() ; ++i)
    {
        if (inputFPA == FPAVec.at(i)){
            inputInSet = true;
            inSetIndex = i;
            break;
        }
    }
    if (inputInSet){
        return COLVec.at(inSetIndex);
    }else{
        for (unsigned int i = 0; i < FPAVec.size() - 1 ; ++i){
            if (inputFPA > FPAVec.at(i)){
                lowerBoundIndex = i;
                break;
            }
        }

        double interpolatedLift = 0.0;
        int upperBoundIndex = lowerBoundIndex + 1;

        //f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))
        interpolatedLift = COLVec.at(lowerBoundIndex) + ((inputFPA - FPAVec.at(lowerBoundIndex)) / (FPAVec.at(upperBoundIndex) - FPAVec.at(lowerBoundIndex))) * (COLVec.at(upperBoundIndex) - COLVec.at(lowerBoundIndex));
        return interpolatedLift;


    }
}

bool isOrdered(const vector<double> &FPAVec){
    bool isOrdered = true;
    for (unsigned int i = 1 ; i < FPAVec.size() ; ++i){
        if (FPAVec.at(i) >= FPAVec.at(i-1)){
            isOrdered = true;
        }else{
            isOrdered = false;
            break;
        }
    }
    return isOrdered;

}

void reorder(vector<double> &FPAVec, vector<double> &COLVec){
    //BUBSORT//
    double temp;
    for (unsigned int i = 0 ; i < FPAVec.size() ; ++i){
        for ( unsigned int k = 0 ; k < FPAVec.size() - 1 ; ++k){
            if (FPAVec.at(k) > FPAVec.at(k+1)){
                temp = FPAVec.at(k);
                FPAVec.at(k) = FPAVec.at(k+1);
                FPAVec.at(k+1) = temp;

                temp = COLVec.at(k);
                COLVec.at(k) = COLVec.at(k+1);
                COLVec.at(k+1) = temp;
            }
        }
    }
}
