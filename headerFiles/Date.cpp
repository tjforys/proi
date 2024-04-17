#include <iostream>
#include <stdexcept>
#include "Date.hpp"

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
}


unsigned int Date::getDay() const {
    return day;
}


Months Date::getMonth() const {
    return month;
}


unsigned int Date::getYear() const {
    return year;  
}


bool isLeapYear(int inputYear) {
    return (inputYear % 400 == 0 or (inputYear % 100 != 0 and inputYear % 4 == 0));
}


bool isValidDate(int inputDay, Months inputMonth, int inputYear) {
    if (inputDay<1 or inputDay>31)
        return false;
    if (inputYear < 0)
        return false;
    if (inputMonth == Months::April or inputMonth == Months::June or inputMonth == Months::September or inputMonth == Months::November)
        return !(inputDay > 30);
    if (inputMonth == Months::February) {
        if (isLeapYear(inputYear))
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
    cout << "The date is " << dateToString() << endl;
}


std::string Date::dateToString() const{
    return std::to_string(day) + "/" + std::to_string(static_cast<int>(getMonth())) + "/" + std::to_string(year);
}


Date Time::addTime(Date date, Time time){
    hours += time.hours;
        minutes += time.minutes;
        seconds += time.seconds;
        if (seconds>59) {minutes++; seconds-= 60;}
        if (minutes>59) {hours++; minutes-=60;}
        if (hours>23) {
        hours-=24;
        if (isValidDate(date.getDay()+1, date.getMonth(), date.getYear())){
            return Date(date.getDay()+1, date.getMonth(), date.getYear());
        }
        if (date.getMonth() == Months(12)) return Date(1, Months(1), date.getYear()+1);
        else return Date(1, Months(static_cast<int>(date.getMonth())+1), date.getYear());
        }
        return date;
}


std::string Time::timeToString(){
    std::string hours_str = std::to_string(hours);
    std::string minutes_str = std::to_string(minutes);
    std::string seconds_str = std::to_string(seconds);
    if (hours_str.length() == 1) hours_str = "0" + std::move(hours_str);
    if (minutes_str.length() == 1) minutes_str = "0" + std::move(minutes_str);
    if (seconds_str.length() == 1) seconds_str = "0" + std::move(seconds_str);

    return hours_str +":" + minutes_str + ":"+ seconds_str;
}