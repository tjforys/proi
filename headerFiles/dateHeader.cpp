#include <iostream>
#include "dateHeader.hpp"

using std::cout;
using std::endl;

Date::Date(int inputDay, Months inputMonth, int inputYear) {
    if (isValidDate(inputDay, inputMonth, inputYear)) {
        day = inputDay;
        month = inputMonth;
        year = inputYear;
    }
    else {
        throw std::invalid_argument("invalid initial date");
    }
};


unsigned int Date::getDay() const {
    return day;
}


Months Date::getMonth() const {
    return month;
}


unsigned int Date::getYear() const {
    return year;  
}


bool Date::isLeapYear(int inputYear) const{
    return (inputYear % 400 == 0 or (inputYear % 100 != 0 and inputYear % 4 == 0));
}


bool Date::isValidDate(int inputDay, Months inputMonth, int inputYear) const{
    if (inputDay<1 or inputDay>31)
        return false;
    if (inputYear < 0)
        return false;
    if (inputMonth == Months::April or inputMonth == Months::June or inputMonth == Months::September or inputMonth == Months::November)
        return !(inputDay > 30);
    if (inputMonth == Months::February) {
        if (Date::isLeapYear(inputYear))
            return !(inputDay > 29);
        else
            return !(inputDay > 28);
    }
    return true;
}

void Date::setDay(int inputDay) {
    if (isValidDate(inputDay, getMonth(), getYear()))
        day = inputDay;
    else
        throw std::invalid_argument("invalid new day");
}


void Date::setMonth(Months inputMonth) {
    if (isValidDate(getDay(), inputMonth, getYear()))
        month = inputMonth;
    else
        throw std::invalid_argument("invalid new month");
}


void Date::setYear(int inputYear) {
    if (isValidDate(getDay(), getMonth(), inputYear))
        year = inputYear;
    else
        throw std::invalid_argument("invalid new year");
}


void Date::setDate(int inputDay, Months inputMonth,int inputYear) {
    if (isValidDate(inputDay, inputMonth, inputYear)) {
        setDay(inputDay);
        setMonth(inputMonth);
        setYear(inputYear);
    }
    else
        throw std::invalid_argument("invalid new date");
}


void Date::displayDate() const{
    cout << "The date is " << getDay() << "/" << static_cast<int>(getMonth()) << "/" << getYear() << endl;
}
