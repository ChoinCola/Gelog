#include <iostream>

int main()
{

	int* ptr = NULL; // c언어의 방식 포인터 초기화
	int* ptr1 = nullptr;
	int* ptr2(nullptr);
	int* ptr3{ nullptr }; // C++방식의 포인터 초기화

	std::nullptr_t  nptr; // 초기화 하지 않았음에도 무조건 NULL만 받는 포인터.



	return 0;
}