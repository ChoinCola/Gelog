#include <iostream>

// std라는 공간이 있고 그곳에 ::로 데이터를 들어간다는것.
// 변수의 이름공간으로 정해서 데이터를 접근한다.
// 코드를 합칠 때 변수의 이름이 겹치는 경우를 피하는 방법이다.
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
		std::cout << "A가 정의한 함수\n" << std::endl;
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

namespace myNamespace2
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

int main()
{
	A::exFunc();
	B::exFunc();

	myNamespace1::AA::BB::CC::c;

	{
		using namespace myNamespace1;
		// using namespace myNamespace2;

		a = 10; // ambiguity 모호성 문제, 두개의변수가 같아져서 사용할 수 없다.

		myNamespace2::a = 20;
	}

	using std::cin;
	using std::cout;
	using std::endl; // std를 안붙이고 쓰고싶다면, 위와같이 하나하나 써도되고,

	using namespace std; // std를 안붙이고 쓰고싶다면, 한방에 붙여도된다.

	cout << "hello" << endl;

	int ii = 0;
	ii++;

	cout << ii << endl;
	// 지역변수가 선언되었을 때 전역변수를 가려서 지역변수가 우선되서 나타난다.
	// 전역변수를 사용하고 싶다면, 밑과같이 활용할 수 있다.
	::ii++;
	cout << ::ii << endl;

	return 0;
}