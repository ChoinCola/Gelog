#include <iostream>

//stream : << >>

int main()
{
    // << : output operator
    // >> : input operator

    int a;
    std::cin >> a;
    std::cout << "입력한 숫자 : " << a << std::endl << std::endl;

    /*
        조정자(mainpulator)
    */
    int num = 100;

    std::cout << std::oct << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;

    std::cout << std::showbase << std::showpos;
    std::cout << std::oct << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::noshowbase << std::noshowpos;

    bool is_true = true;
    bool is_false = false;

    std::cout << std::boolalpha;
    std::cout << is_true << std::endl;
    std::cout << is_false << std::endl;

    std::cout << std::noboolalpha;
    std::cout << is_true << std::endl;
    std::cout << is_false << std::endl;

    return 0;
}