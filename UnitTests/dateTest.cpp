#include "gtest/gtest.h"
#include "../headerFiles/dateHeader.hpp"
#include <sstream>
using std::invalid_argument;

TEST(testDate, getDayTest)
{
    Date test_date = Date(23, Months(2), 2005);
    EXPECT_EQ(23, test_date.getDay());
}

TEST(testDate, negativeDayTest)
{   
    EXPECT_THROW({
    Date test_date = Date(-5, Months(2), 2005);
    }, invalid_argument);
}

TEST(testDate, invalidDateTest)
{   
    EXPECT_THROW({
    Date test_date = Date(29, Months(2), 2005);
    }, invalid_argument);
}

TEST(testDate, getMonthTest)
{
    Date test_date = Date(23, Months(2), 2005);  
    EXPECT_EQ(Months(2), test_date.getMonth());	
}

TEST(testDate, getYearTest)
{
    Date test_date = Date(23, Months(2), 2005); 
    EXPECT_EQ(2005, test_date.getYear());
}

TEST(testDate, setDayTest)
{
    Date test_date = Date(23, Months(2), 2005);
    test_date.setDay(26);
    EXPECT_EQ(26, test_date.getDay());
}

TEST(testDate, setInvalidDayTest)
{   
    EXPECT_THROW({
    Date test_date = Date(23, Months(2), 2005);
    test_date.setDay(40);
    }, invalid_argument);
}

TEST(testDate, setMonthTest)
{
    Date test_date = Date(23, Months(2), 2005);
    test_date.setMonth(Months(6));
    EXPECT_EQ(Months(6), test_date.getMonth());
}

TEST(testDate, setInvalidMonthTest)
{
    EXPECT_THROW({
    Date test_date = Date(30, Months(3), 2005);
    test_date.setMonth(Months(2));
    }, invalid_argument);
}

TEST(testDate, setYearTest)
{
    Date test_date = Date(23, Months(2), 2005);
    test_date.setYear(2024);
    EXPECT_EQ(2024, test_date.getYear());
}

TEST(testDate, setInvalidYearTest)
{
    EXPECT_THROW({
    Date test_date = Date(30, Months(3), 2005);
    test_date.setYear(-30);
    }, invalid_argument);
}

TEST(testDate, setDateTest)
{
    Date test_date = Date(23, Months(2), 2005);
    test_date.setDate(26, Months(4), 2007);
    EXPECT_EQ(26, test_date.getDay());
    EXPECT_EQ(Months(4), test_date.getMonth());	
    EXPECT_EQ(2007, test_date.getYear());   
}

TEST(testDate, displayDateTest)
{
    Date test_date = Date(23, Months(2), 2005);
    std::ostringstream oss;
    std::streambuf* cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    test_date.displayDate();
    EXPECT_EQ(oss.str(), "The date is 23/2/2005\n" );
    std::cout.rdbuf(cout_buffer);
}
