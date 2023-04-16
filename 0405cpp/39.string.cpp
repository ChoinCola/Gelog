#include <iostream>
#include <string>
using namespace std;



int main()
{
	char myStr[] = "Hello C";
	// C에서의 문자열은 배열로 하나하나 지정하여 문장을 저장하였다.
	//char* myStr2 = "Hello C"; // c의 경우에는 허용이 되는 방식이다.
	// 선언을 하면 문자열을 변경할 수 없기 떄문에, readonly 메모리 이기 때문에, 엄격하게 const를 붙여야
	// C++에서 사용이 가능하다.
	const char* myStr2 = "Hello C";

	string str = "Hello c++";

	cout << str.size() << endl; // 문장의 사이즈
	cout << str.length() << endl; // 문자열의 사이즈

	string a("Hello, ");
	string b("C++!!");

	string C = a + b; // 문장을 붙여서 붙이는 연산이 가능하다.

	cout << C << endl;
	C += ", good!!"; // 다음과 같은 연산 또한 가능하다.
	cout << C << endl;

	cout << C[4] << endl; // 배열처럼 또한 사용이 가능하다. 이와같이 사용하면 1부터 4까지의 5번째 문자가 출력된다.

	return 0;
}