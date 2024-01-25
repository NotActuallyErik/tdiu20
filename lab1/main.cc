#include "Time.cc"
#include "iostream"

int main(int argc, char const *argv[])
{
    (void)argc; //Supress compiler warning
    (void)argv; //Supress compiler warning

    //Time t0{00,00,00};
    //Time t1{22,33,44};
    Time t2{"11pm:59:59"};
    //Time empty{};
    Time ts{3600};
    std::cout << ts.to_string()  << std::endl;

    return 0;
}
