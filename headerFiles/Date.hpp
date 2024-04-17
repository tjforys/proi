#pragma once
enum class Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};


bool isValidDate(int, Months, int);


bool isLeapYear(int);


class Date {
    unsigned int day, year;
    Months month;
public:
    //constructor
    Date(int, Months,int);
    Date(){};

    //getters
    unsigned int getDay() const;
    Months getMonth() const;
    unsigned int getYear() const;

    //setters
    void setDay(int);
    void setMonth(Months);
    void setYear(int);
    void setDate(int, Months, int);

    //other
    void displayDate() const;
    std::string dateToString() const;

friend bool operator==(const Date& lhs, const Date& rhs){
    return (lhs.day == rhs.day and lhs.month == rhs.month and lhs.year == rhs.year);
}
};


struct Time{
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    Time(int h, int m, int s){
        if ((h<0 or m<0 or s<0) or (h>23 or m>59 or s>59)) throw(std::invalid_argument("invalid time"));
        hours = std::move(h);
        minutes = std::move(m);
        seconds = std::move(s);
    };

    Date addTime(Date date, Time time);

    std::string timeToString();
};
