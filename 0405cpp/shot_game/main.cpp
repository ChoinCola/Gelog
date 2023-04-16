#include "head.h"

int main()
{
	int* map = nullptr;

	int point = 0;

	bool boomnow = false;

	Fly Umain = {1,1,0,0};

	Make_map(map, &Umain, MAP_WIDTH, MAP_LENGTH); // 맵 생성

	// 랜덤변수로, 별을 생성할 위치좌표를 구함.
	std::random_device rd;
	std::mt19937 messenne(rd());
	std::uniform_int_distribution<int> randNUJm(1, MAP_WIDTH - 2);
	
	while (true) {
		// 현재 포인트, 유저의 XY좌표, HP를 표출.
		std::cout << "Point " << point << " user X: " << Umain.x << " Y: " << Umain.y << " HP :" << Umain.hp << "\n";

		Print_map(map, MAP_WIDTH, MAP_LENGTH); // 맵 출력
		if (HPchack(&Umain)) { // 체력 채크. 체력이 부족하면 패배.
			if (_kbhit()) // 키보드의 아무 키를 입력하였을 시,
				User_move(&Umain, MAP_WIDTH, map); // 유저의 입력을 받음.
			StarFall(map, &Umain, MAP_WIDTH, MAP_LENGTH, &point, STARFALL, randNUJm(messenne)); // 별 떨어지는 코드
			Sleep(DELAYTIME); // 너무 빠르면 딜레이 설정가능
			system("cls"); // 화면초기화
		}
		else {
			std::cin.clear(); // 입력버퍼 초기화
			Print_DEAD(map, &Umain, boomnow, MAP_WIDTH, MAP_LENGTH); // 패배 이벤트를 출력함.
			boomnow = !boomnow; // 폭파종류 2개. 반짝반짝!
			
			if (_kbhit()) { // 키를 입력 하였다는것 을 확인하면,
				system("cls"); // 화면 초기화
				std::cout << "Point " << point << std::endl;// 포인트 출력
				exit(1); // 이벤트 종료.
			}
			Sleep(1000);// 반짝반짝은 1초간격으로 출력한다.
			system("cls"); // 화면 초기화
		}
	}
	free(map);
	return 0;
}