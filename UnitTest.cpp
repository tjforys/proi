#include "gtest/gtest.h"
#include "classes.hpp"
#include <sstream>

TEST(testDate, getDayTest)
{
    Date test_date = Date(23, Months(2), 2005);
    EXPECT_EQ(23, test_date.getDay());
}

TEST(testDate, negativeDayTest)
{   
    std::ostringstream oss;
    std::streambuf* cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    Date test_date = Date(-5, Months(2), 2005);
    EXPECT_EQ(oss.str(), "The initial date is invalid, set default date 1/1/2000\n");
    EXPECT_EQ(1, test_date.getDay());
    EXPECT_EQ(Months(1), test_date.getMonth());
    EXPECT_EQ(2000, test_date.getYear());
    std::cout.rdbuf(cout_buffer);
}

TEST(testDate, invalidDateTest)
{   
    std::ostringstream oss;
    std::streambuf* cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    Date test_date = Date(29, Months(2), 2005);
    EXPECT_EQ(oss.str(), "The initial date is invalid, set default date 1/1/2000\n");
    EXPECT_EQ(1, test_date.getDay());
    EXPECT_EQ(Months(1), test_date.getMonth());
    EXPECT_EQ(2000, test_date.getYear());
    std::cout.rdbuf(cout_buffer);
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
    std::ostringstream oss;
    std::streambuf* cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    Date test_date = Date(23, Months(2), 2005);
    test_date.setDay(40);
    EXPECT_EQ(oss.str(), "Invalid new day\n");
    EXPECT_EQ(23, test_date.getDay());
    std::cout.rdbuf(cout_buffer);
}

TEST(testDate, setMonthTest)
{
    Date test_date = Date(23, Months(2), 2005);
    test_date.setMonth(Months(6));
    EXPECT_EQ(Months(6), test_date.getMonth());
}

TEST(testDate, setInvalidMonthTest)
{
    std::ostringstream oss;
    std::streambuf* cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    Date test_date = Date(30, Months(3), 2005);
    test_date.setMonth(Months(2));
    EXPECT_EQ(oss.str(), "Invalid new month\n");
    EXPECT_EQ(Months(3), test_date.getMonth());
    std::cout.rdbuf(cout_buffer);
}

TEST(testDate, setYearTest)
{
    Date test_date = Date(23, Months(2), 2005);
    test_date.setYear(2024);
    EXPECT_EQ(2024, test_date.getYear());
}

TEST(testDate, setInvalidYearTest)
{
    std::ostringstream oss;
    std::streambuf* cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    Date test_date = Date(30, Months(3), 2005);
    test_date.setYear(-30);
    EXPECT_EQ(oss.str(), "Invalid new year\n");
    EXPECT_EQ(2005, test_date.getYear());
    std::cout.rdbuf(cout_buffer);
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