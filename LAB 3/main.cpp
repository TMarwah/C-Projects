#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int ); 
      Rational(int , int ); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int , int ) const;
};

// Implement Rational class member functions here
Rational::Rational(){
   numerator = 0;
   denominator = 1;
}
Rational::Rational(int n){
   numerator = n;
   denominator = 1;
}
Rational::Rational(int n, int d){
   numerator = n;
   denominator = d;
}

Rational Rational::add(const Rational &number) const{
   Rational additionResult;
   additionResult.numerator = (numerator*number.denominator + denominator*number.numerator);
   additionResult.denominator = (denominator*number.denominator);
   return additionResult;
}

Rational Rational::subtract(const Rational &number) const{
   Rational subtractionResult;
   subtractionResult.numerator = (numerator*number.denominator - denominator*number.numerator);
   subtractionResult.denominator = (denominator*number.denominator);
   return subtractionResult;
}

Rational Rational::multiply(const Rational &number) const{
   Rational multiplicationResult;
   multiplicationResult.numerator = (numerator*number.numerator);
   multiplicationResult.denominator = (denominator*number.denominator);
   return multiplicationResult;
}

Rational Rational::divide(const Rational &number) const{
   Rational divisionResult;
   divisionResult.numerator = (numerator*number.denominator);
   divisionResult.denominator = (denominator*number.numerator);
   return divisionResult;
}
int Rational::gcd(int numA, int numB) const{
   int greatestdivisor;
   while (numA != numB){
      if (numB > numA){
         numB = numB - numA;
         greatestdivisor = numB;

      } else {
         numA = numA - numB;
         greatestdivisor = numA;
      }
   }
   return greatestdivisor;
}
void Rational::simplify(){
   int divisor = gcd(numerator, denominator);

   numerator = numerator / divisor;
   denominator = denominator / divisor;

}

void Rational::display() const{
   cout << numerator << " / " << denominator;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

