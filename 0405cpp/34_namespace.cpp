#include <iostream>

using namespace std;

int ii = 10;

namespace A
{
    void exFunc()
    {
        std::cout << "A가 정의한 함수\n" << std::endl;
    }
}

namespace B
{
    void exFunc()
    {
        std::cout << "B가 정의한 함수\n" << std::endl;
    }
}

namespace myNamespace1
{
    int a;

    void doSomething() {}

    namespace AA
    {
        namespace BB
        {
            namespace CC
            {
                int c;
            }
        }
    }
}

namespace myNamespace1
{
    int hello;
}

namespace myNamespace2
{
    int a;
    void doSomething() {}
}

int main()
{
    A::exFunc();
    B::exFunc();

    myNamespace1::AA::BB::CC::c;

    {
        using namespace myNamespace1;
        //using namespace myNamespace2;

        a = 10; //ambiguity

        myNamespace2::a = 20;
    }

    //using std::cin;
    //using std::cout;
    //using std::endl;

    cout << "hello" << endl;

    int ii = 0;

    ii++;
    cout << ii << endl;

    ::ii++;
    cout << ::ii << endl;

    float f1 = 1.1f;
    cout << static_cast<int>(f1) << endl;

    return 0;
}