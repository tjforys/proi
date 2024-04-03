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

class Date {
    unsigned int day, year;
    Months month;
    bool isValidDate(int, Months, int) const;
    bool isLeapYear(int) const;
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
friend bool operator==(const Date& lhs, const Date& rhs){
    return (lhs.day == rhs.day and lhs.month == rhs.month and lhs.year == rhs.year);
}
};