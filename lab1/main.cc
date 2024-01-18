#include "Time.h"
#include "iostream"

int main(int argc, char const *argv[])
{

    TIME t0{00,00,00};
    TIME t1{22,33,44};

        TIME empty{};
        empty.hour;
        empty.minute;
        empty.second;

        t0--;

    std::cout << (t0.to_string())  << std::endl;

    return 0;
}
