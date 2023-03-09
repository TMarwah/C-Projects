#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString(string&s){
   if (s.size() <= 1) {
      return;
   }
   else{
   char temp = s.at(0);
   s.at(0) = s.at(s.size() - 1);
   s.at(s.size() - 1) = temp;
   string subStr = s.substr(1, s.size()-2);
   flipString(subStr);
   s = s.at(0) + subStr + s.at(s.size() - 1);
   }
}
