#include <iostream>

int main()
{
    int x = 10; //copy initialization
    int y(10); //direct initialization
    int z{ 10 }; //uniform initialization

    int a = 1.1; //warning
    //int b{ 1.1 }; //error
    char c = 500; //warning
    //char d{ 500 }; //error

    /*
        limits
    */
    std::cout << std::numeric_limits<short>::max() << std::endl;
    std::cout << std::numeric_limits<int>::min() << std::endl;
    std::cout << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::numeric_limits<float>::min() << std::endl;
    std::cout << std::numeric_limits<float>::max() << std::endl << std::endl;

    /*
        Casting
    */

    int i = 10;
    float k = 10.0f;

    std::cout << k << std::endl;
    std::cout << (int)k << std::endl;
    std::cout << int(k) << std::endl;
    std::cout << static_cast<int>(k) << std::endl;

    /*
        const vs constexpr
    */
    const int c1(123);

    int i1 = 10;
    const int c2 = i1;

    int arr1[c1];
    //int arr2[c2];

    constexpr float PI = 3.141592f;

    float PI2 = 3.141592f;
    //constexpr float PI3 = PI2;

    constexpr int arrSize = 10;
    int arr[arrSize];

    return 0;
}