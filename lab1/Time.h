#include <string>

class TIME
{
public:

int SECONDS_TOT;
  int hour;
  int minute;
  int second;
  
  TIME(){
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
  }


TIME(int hour, int minute, int second)
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

int to_seconds()
{
    SECONDS_TOT = this->hour * 3600 + this->minute * 60 + this->second;
    return SECONDS_TOT;
}

bool is_am()
{
    if (this->hour >= 12)
    {return false;
}
else return true;
}

int Get_hour()
{
    return this->hour;
}

int Get_minute()
{
    return this->minute;
}

int Get_second()
{
    return this->second;
}

bool operator<(TIME& t1)
{
if (this->to_seconds() < t1.to_seconds())
{return true;
}
else return false;
}

bool operator>(TIME& t1)
{
if (this->to_seconds() > t1.to_seconds())
{return true;
}
else return false;
}

bool operator<=(TIME& t1)
{
if (this->to_seconds() <= t1.to_seconds())
{return true;
}
else return false;
}

bool operator>=(TIME& t1)
{
if (this->to_seconds() >= t1.to_seconds())
{return true;
}
else return false;
}

bool operator==(TIME& t1)
{
if (this->to_seconds() == t1.to_seconds())
{return true;
}
else return false;
}

bool operator!=(TIME& t1)
{
if (this->to_seconds() == t1.to_seconds())
{return false;
}
else return true;
}

int operator++(int)
{
this->second ++;

    if (this->second == 60)
    {this->second = 0;
    this->minute ++;
    }

 if (this->minute == 60)
    {this->minute = 0;
    this->hour ++;
}

 if (this->hour == 24)
    {this->hour = 0;
    }
}

int operator--(int)
{
this->second --;

    if (this->second == -1)
    {this->second = 59;
    this->minute --;
    }

 if (this->minute == -1)
    {this->minute = 59;
    this->hour --;
}

 if (this->hour == -1)
    {this->hour = 23;
    }
}

std::string to_string()
{
std::string return_string;

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

};
