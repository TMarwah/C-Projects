#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

//DEFAULT DATE//
Date::Date(){
   day = 1;
   month = 1;
   year = 2000;
   monthName = "January";
}


//CREATE DATE OBJECT BASED ON NUMERIC MONTH//
Date::Date(unsigned m, unsigned d, unsigned y){
   bool isValid = true;
   vector <unsigned int>validDays{31,28,31,30,31,30,31,31,30,31,30,31};
   //INITIALIZE DATE//
   month = m;
   day = d;
   year = y;

   //SET LEAP YEAR DATE//
   if (isLeap(y)){
      validDays.at(1) = 29;
   }

   //CHECK MONTH VALIDITY//
   if (month > 12){
      isValid = false;
      month = 12;
   }
   if (month <= 0){
      isValid = false;
      month = 1;
   }
   //CHECK DAY VALIDITY//
   if (d > validDays.at(month-1)){
      isValid = false;
      day = validDays.at(month-1);
   }
   if (d <= 0){
      isValid = false;
      day = 1;
   }
   //SET MONTHNAME//
   if (month == 1){
      monthName = "January";
   }
   if (month == 2){
      monthName = "February";
   }
   if (month == 3){
      monthName = "March";
   }
   if (month == 4){
      monthName = "April";
   }
   if (month == 5){
      monthName = "May";
   }
   if (month == 6){
      monthName = "June";
   }
   if (month == 7){
      monthName = "July";
   }
   if (month == 8){
      monthName = "August";
   }
   if (month == 9){
      monthName = "September";
   }
   if (month == 10){
      monthName = "October";
   }
   if (month == 11){
      monthName = "November";
   }
   if (month == 12){
      monthName = "December";
   }

   if (!isValid){
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }

}

//CREATE DATE OBJECT BASED ON ALPHA MONTH//
Date::Date(const string &mn, unsigned d, unsigned y){
   bool monthPresent = false;
   string uppercaseMN = mn;
   vector <string>validMonths{"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
   vector <unsigned int>validDays{31,28,31,30,31,30,31,31,30,31,30,31};
   //SET LEAP YEAR//
   if (isLeap(y)){
      validDays.at(1) = 29;
   }

   //CONVERT MN TO UPPERCASE, ALLOWS FOR BOTH CASES TO WORK//
   for (unsigned int k = 0 ; k < uppercaseMN.length() ; ++k ){
      uppercaseMN[k] = toupper(uppercaseMN[k]);
   }

   //CHECK IF UPPERCASEMN IS PRESENT IN VECTOR OF ACCEPTABLE MONTHS//
   for (unsigned int i = 0 ; i < validMonths.size() ; ++i){
      if ( uppercaseMN == validMonths.at(i)){
         monthPresent = true;
         //set month number based on location in vector, offset by 1
         month = i+1;
      }
   }
   if (monthPresent){


      monthName = mn;
      day = d;
      year = y;
      if (day > validDays.at(month - 1)){
         day = validDays.at(month - 1);
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }
      if (day <= 0){
         day = 1;
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }
   }else{
      month = 1;
      monthName = "January";
      day = 1;
      year = 2000;
      cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << "." << endl;
   }



}
void Date::printNumeric() const{
   cout << month << "/" << day << "/" << year;

}

void Date::printAlpha() const{
   string upperName = monthName;
   upperName[0] = toupper(upperName[0]);


   cout << upperName << " " << day << ", " << year;

}

bool Date::isLeap(unsigned y) const{
   bool leap = false;
   if (y % 4 ==0){
      leap = true;
   }
   if(y % 100 == 0){
      leap = false;
   }
   if (y % 400 == 0){
      leap = true;
   }
   return leap;
}




// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
