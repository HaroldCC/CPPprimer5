/*************************************************************************
> File Name       : 9.51.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月11日  08时18分34秒
************************************************************************/
#include <iostream>
#include <string>

class Date
{
private:
    unsigned year;
    unsigned month;
    unsigned day;

public:
    Date(const std::string &str);
    ~Date() {}

    void print()
    {
        std::cout << "day:" << day << " "
                  << "month: " << month << " "
                  << "year: " << year << std::endl;
    }

private:
    void string_conversion_date_version1(const std::string &s)
    {
        convert_month(s);
        day = std::stoi(s.substr(s.find_first_of("123456789"), s.find_first_of(",") - s.find_first_of("123456789")));
        year = std::stoi(s.substr(s.find_last_of(",") + 1, 4));
    }

    void string_conversion_data_version2(const std::string &s)
    {
        convert_month(s);
        day = std::stoi(s.substr(s.find_first_of("123456789"), s.find_first_of(" ") - s.find_first_of("123456789")));
        year = std::stoi(s.substr(s.find_last_of(" ") + 1, 4));
    }

    void string_conversion_data_version3(const std::string &s)
    {
        day = std::stoi(s.substr(0, s.find_first_of("/")));
        month = std::stoi(s.substr(s.find_first_of("/") + 1, s.find_last_of("/") - s.find_first_of("/")));
        year = std::stoi(s.substr(s.find_last_of("/") + 1, 4));
    }

    void convert_month(const std::string &s)
    {
        if (s.find("Jan") < s.size())
            month = 1;
        if (s.find("Feb") < s.size())
            month = 2;
        if (s.find("Mar") < s.size())
            month = 3;
        if (s.find("Apr") < s.size())
            month = 4;
        if (s.find("May") < s.size())
            month = 5;
        if (s.find("Jun") < s.size())
            month = 6;
        if (s.find("Jul") < s.size())
            month = 7;
        if (s.find("Aug") < s.size())
            month = 8;
        if (s.find("Sep") < s.size())
            month = 9;
        if (s.find("Oct") < s.size())
            month = 10;
        if (s.find("Nov") < s.size())
            month = 11;
        if (s.find("Dec") < s.size())
            month = 12;
    }
};

Date::Date(const std::string &str)
{
    if (str.find_first_of(",") != std::string::npos)
        string_conversion_date_version1(str);
    else if (str.find_first_of("/") != std::string::npos)
        string_conversion_data_version3(str);
    else if (str.find_first_of(" ") != std::string::npos)
        string_conversion_data_version2(str);
    else
        year = 1990, month = 1, day = 1;
}

int main(int argc, char const *argv[])
{
    Date d1("9/5/1990");
    Date d2("January 7,1970");
    Date d3("Jan 11 1942");

    d1.print();
    d2.print();
    d3.print();

    system("pause");
    return 0;
}