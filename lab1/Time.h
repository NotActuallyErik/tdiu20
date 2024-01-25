#include <string>
#include <vector>
#include <iostream>

class Time
{

private: 

    void parse_time(std::string); 
    void eval_time();
    int hour;
    int minute;
    int second;
    int seconds_tot; 

public:
    
    Time();
    Time(int hour, int minute, int second);
    Time(std::string);
    Time(int seconds);

    int get_hour();
    int get_minute();
    int get_second();
    int to_seconds();
    bool is_am();
    std::string to_string(bool hr_format = false);

    bool operator<(Time& t1);   
    bool operator>(Time& t1);
    bool operator<=(Time& t1);
    bool operator>=(Time& t1);
    bool operator==(Time& t1);
    bool operator!=(Time& t1);

    Time  operator++(int);
    Time  operator--(int);
    Time& operator++();
    Time& operator--();
    //std::ostream& operator<<(std::ostream& os) const;

};

    std::ostream& operator<<(std::ostream&, Time& t);
