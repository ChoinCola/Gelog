#include <iostream>

int add(int a, int b) { return a + b; }
// C++에서는 함수의 이름을 중복하여 사용하는것이 가능하다.
float add(float a, float b) { return a + b; }
// 그러나, 매개변수를 다르게 사용하여 구분해야만 한다.
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }
// 인자의 개수가 다르기 때문에 위와 같은 방법 또한 가능하다.

// c언어는 함수의 이름을 중심으로 찾는다.
// c++는 객체지향 이기 때문에 함수의 이름이 아닌 함수의 인수를 기준으로 찾는다. 그래서 함수의 이름이
// 중첩되어도 동작한다.

using integer = int;
// integer add(integer a, integer b) { return a + b; } 는 불가능하다. 컴파일러가 보기에는 3번과 같이 보기 때문,
using namespace std;

void output(int value) {}
void output(unsigned int value) {}
void output(float value) {}

int main()
{
	auto result1 = add(10, 20);
	auto result2 = add(10.1f, 20.1f);
	auto result3 = add(10, 20, 30);
	// add라는 함수의 리턴값이 다양함으로 auto로 일일이 지정하지 않아도 되기 때문에 더 편하다.

	output(1); // 모호성이 발생했다.  int와 unsigned int가 둘다 해당되기 때문,
	output(1.0f); // 모호성이 발생하지 않는다, float을 호출했기 때문,

	output('c'); // 자기와 일치하는 변수를 찾지 못했을 경우,가장 일치하는 변수로 형변환하며 찾는다.
	// char, usigned char, short, int 이런 순 으로.
	

	return 0;
}