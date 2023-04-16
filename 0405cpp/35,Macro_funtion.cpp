#include <iostream>

using namespace std;

#define PLUS(a, b) a + b
// define에서도 함수를 매크로로 선언하여 사용할 수 있다.
// 매크로 함수를 선언하면, CODE 영역에서 함수를 저장하여 연산하기에 더 빠른 연산처리가 가능하다.

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
// 최대값을 구하는 매크로 함수.
inline int max(int a, int b)
{
	return (a + b);
}

int main()
{
	cout << PLUS(1, 2) << endl;
	cout << PLUS(1, 2) * PLUS(1, 2) << endl;
	// 함수를 매크로로 변환하여 사용하는것은 괄호가 들어가지 않아서, 1 + 2 * 1 + 2 와 같이 출력되기에
	// 5가 나타나게 된다.

	cout << (PLUS(1, 2)) * (PLUS(1, 2)) << endl;
	// 위와 같이 써야 9 가 나타난다.
	cout << MAX(1, 2) << endl;

	return 0;
}