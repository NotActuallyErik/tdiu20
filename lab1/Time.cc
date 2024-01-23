#include "Time.h"
#include <stdexcept>

// Compiler flags: -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast

using namespace std; // Tror inte man får göra detta egentligen >:) 
/* 
     /\_/\
   ~( o.o )~ 
     > ^ <
*/

Time::Time() :
    hour{0},
    minute{0},
    second{0},
    seconds_tot{to_seconds()}
{
    eval_time(); // Behövs egentligen inte, men det är bra att vara konsekvent.
}

Time::Time(int hour, int minute, int second) : 
    hour{hour},
    minute{minute},
    second{second},
    seconds_tot{to_seconds()}
{
    eval_time();
}

Time::Time(std::string time) :
    hour{0},
    minute{0},
    second{0},
    seconds_tot{0}
{
    if(time.size() != 10 && time.size() != 8){
        // om inget av ovanstående så är strängen felformaterad -> kasta fel.
        throw logic_error("string len not correct format");
    }
    if(time.size() == 10){
        // Antag 12-timmarsformat
        string time_suffix = time.substr(2,2); // extrahera "am" eller "pm" delen av strängen, spara i ny sträng
        time.erase(2,2); // ta bort "am" eller "pm" så att vi kan få den på formatet parse_time förväntar sig. 
        try
        {
            parse_time(time);
            if(time_suffix == "pm")
            {
                this->hour += 12;
            } 
        } 
        catch (logic_error& e) 
        {
            cout << e.what() << endl;
        }
        // Kan kanske vara värt att ta hand om kantfall då det inte står "am" eller "pm"
        // tänker typ om nån skulle vara lite rolig och skriva "07ma" eller nått liknande 

    } 
    else if(time.size() == 8) 
    {
        // Antag 24-timmarsformat
        try
        {
            parse_time(time);
        }
        catch(std::logic_error& e)
        {
            std::cout << e.what() << std::endl;
        }

    };
    eval_time();
}


void Time::parse_time(std::string time_string)
{
    // Läs in tiderna från strängen & konvertera till int.
    if(time_string[2] != ':' || time_string[5] != ':')
    {
        throw std::logic_error("incorrect format");
    }
    this->hour = std::stoi(time_string.substr(0,2));
    this->minute = std::stoi(time_string.substr(3,2));
    this->second = std::stoi(time_string.substr(6,2));
    this->seconds_tot = to_seconds();
}

void Time::eval_time()
{
    // tl;dr: kasta fel om det inte är en riktig tid.
    if(hour < 0 || hour > 23){
        throw logic_error("Hour value incorrect");
    }
    if(minute < 0 || minute > 59){
        throw logic_error("minute value incorrect");
    }
    if(second < 0 || second > 59){
        throw logic_error("Hour value incorrect");
    }
}


int Time::to_seconds()
{
    return this->hour * 3600 + this->minute * 60 + this->second;
}

bool Time::is_am()
{
    if (this->hour >= 12)
    {
        return false;
    }
    else
        return true;
}

std::string Time::to_string()
{
    std::string hh = std::to_string(this->hour);
    std::string mm = std::to_string(this->minute);
    std::string ss = std::to_string(this->second);

    if (this->hour <= 9)
    {
        hh = "0" + hh;
    }

    if (this->minute <= 9)
    {
        mm = "0" + mm;
    }

    if (this->second <= 9)
    {
        ss = "0" + ss;
    }

    return hh + ":" + mm + ":" + ss;
}

int Time::get_hour()
{
    return this->hour;
}

int Time::get_minute()
{
    return this->minute;
}

int Time::get_second()
{
    return this->second;
}

bool Time::operator<(Time&  t1)
{
    return (this->to_seconds() < t1.to_seconds());
}

bool Time::operator>(Time&  t1)
{
    return (this->to_seconds() > t1.to_seconds());
}

bool Time::operator<=(Time&  t1)
{
    return (this->to_seconds() <= t1.to_seconds());
}

bool Time::operator>=(Time&  t1)
{
    return (this->to_seconds() >= t1.to_seconds());
}

bool Time::operator==(Time&  t1)
{
    return (this->to_seconds() == t1.to_seconds());
}

bool Time::operator!=(Time&  t1)
{
    return (this->to_seconds() != t1.to_seconds());
}

Time& Time::operator++(int)
{
    this->second++;

    if (this->second == 60)
    {
        this->second = 0;
        this->minute++;
    }

    if (this->minute == 60)
    {
        this->minute = 0;
        this->hour++;
    }

    if (this->hour == 24)
    {
        this->hour = 0;
    }
    return *this; // osäker på denna, borde nog fråga labbass
}


Time& Time::operator--(int)
{
    this->second--;

    if (this->second == -1)
    {
        this->second = 59;
        this->minute--;
    }

    if (this->minute == -1)
    {
        this->minute = 59;
        this->hour--;
    }

    if (this->hour == -1)
    {
        this->hour = 23;
    }
    return *this; //Samma här
}



