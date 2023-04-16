#include <iostream>

using namespace std;

auto add(int x, int y) -> int; // 후위 반환타입 선언방식, 알아보기 쉬워서 많이 사용한다. int로 auto한다는 의미이다.

int main()
{
	int a = 10;
	float b = 3.14f;
	double c = 45.0;

	//float result = a + b;
	// 위에서 더하면 알아서 타입을 변경해서 int가 float로 바뀐 후 더해져서 출력된다.

	auto result = a + b;
	// 위 방법대로 진행하면 a 와 b를 더 했을 때 가장 순위가 높은 변수의 형태로 변환해서 출력해준다.
	// float가 가장 높음으로 float 으로 변환하여 출력함.




	return 0;
}

auto add(int x, int y) -> int
// 메개변수는 auto로 할 수 없다. 이는 들어오는 값을 자동으로 타입을 변환할 수 없기 때문이다.
{
	return x + y;
}
