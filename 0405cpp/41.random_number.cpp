#include <stdlib.h>
#include <time.h>
// c언어에서의 random 선언

#include <iostream>
#include <random>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++) {
		printf("%d ", rand() % 10);
	}
	// random 을 c언어에서 사용하는것
	printf("\n");
	random_device rd;

	mt19937 messenne(rd());

	uniform_int_distribution<> randNUJm(1, 10); // 동일한 확률로 1에서 10까지 나타나겠다는 의미

	for (int i = 0; i < 10; i++)
		cout << randNUJm(messenne) << " ";
		// 시드값에 따라 랜덤함수를 출력하는 방법이다.
	cout << endl;

	return 0;
}