#include <iostream>
#include "classes.hpp"
#include <string>
using std::cout;
using std::endl;


int main() {
    //initializing invalid date
    Date today(-1, Months::March, 2024);
    cout << today.getDay()<<endl;
    cout << static_cast<int>(today.getMonth()) << endl;
    cout << today.getYear() << endl;
    today.displayDate();
    //setting valid date
    today.setDate(15, Months::April, 2025);
    cout << today.getDay() << endl;
    cout << static_cast<int>(today.getMonth()) << endl;
    cout << today.getYear() << endl;
    today.displayDate();
    //settinh valid day, month, year
    today.setDay(16);
    today.setMonth(Months::May);
    today.setYear(2026);
    cout << today.getDay() << endl;
    cout << static_cast<int>(today.getMonth()) << endl;
    cout << today.getYear() << endl;
    today.displayDate();
    //setting invalid day and year
    today.setDay(-32);
    today.setYear(-30);
    cout << today.getDay() << endl;
    cout << static_cast<int>(today.getMonth()) << endl;
    cout << today.getYear() << endl;
    today.displayDate();
    //set valid date with 31 day month
    today.setDate(31, Months::January, 2025);
    cout << today.getDay() << endl;
    cout << static_cast<int>(today.getMonth()) << endl;
    cout << today.getYear() << endl;
    today.displayDate();
    //setting invalid month with 30 days
    today.setDate(31, Months::April, 2025);
    cout << today.getDay() << endl;
    cout << static_cast<int>(today.getMonth()) << endl;
    cout << today.getYear() << endl;
    today.displayDate();
}