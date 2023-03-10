#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    vector<string> message{"i am test", "ing this thing", "wow"};
    cout << message.at(2) << endl;
    for (unsigned int i = 0 ; i < message.size() ; ++i) cout <<message.at(i) << " ";
    cout << endl;
    return 0;
}