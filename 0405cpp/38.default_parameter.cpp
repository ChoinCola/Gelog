#include <iostream>

using namespace std;

// default parameter는 함수 선언시에 사용할  수 있다.

void print(int x = 7) // C와 다르게 함수호출 방식이 다르기 때문에 가능한 방식이다. C에서는 함수 이름을 중심으로 호출하고 봐야하기 때문에
// 매개변수에 기본값을 선언할 수 없지만, C++에서는 매개변수를 기준으로 찾기 때문에 매개변수를 지정하고 그 이후 함수이름을 찾아서, default선언이 가능하다.
{ // 아무것도 선언하지 않았을 때 그냥 7을 출력하고 싶다면, 위와같이 생성이 가능하다. 이것이 기본 파라미터 라고 한다.
	cout << x << endl;
}

void print(int x, int y = 7)
{
	cout << x << y << endl;
}
// 충돌이 날 수 있기 때문에 중첩방식과 default방식을 둘다 쓰는건 권장되는 방식은 아니다.

void test(int x = 10, int y = 10, int z = 10)
{

}
int main()
{
	print();
	print(2); //모호성 문제 발생.

	test(10,10,3); // 뒤의 값을 변경하고 싶어도, 할 수 있는 방법이 없기에 앞의 데이터 를 출력해서, 전부 넣어주어야 뒤를 수정 가능하다.


	return 0;
}