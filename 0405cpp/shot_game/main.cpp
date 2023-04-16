#include "head.h"

int main()
{
	int* map = nullptr;

	int point = 0;

	bool boomnow = false;

	Fly Umain = {1,1,0,0};

	Make_map(map, &Umain, MAP_WIDTH, MAP_LENGTH); // �� ����

	// ����������, ���� ������ ��ġ��ǥ�� ����.
	std::random_device rd;
	std::mt19937 messenne(rd());
	std::uniform_int_distribution<int> randNUJm(1, MAP_WIDTH - 2);
	
	while (true) {
		// ���� ����Ʈ, ������ XY��ǥ, HP�� ǥ��.
		std::cout << "Point " << point << " user X: " << Umain.x << " Y: " << Umain.y << " HP :" << Umain.hp << "\n";

		Print_map(map, MAP_WIDTH, MAP_LENGTH); // �� ���
		if (HPchack(&Umain)) { // ü�� äũ. ü���� �����ϸ� �й�.
			if (_kbhit()) // Ű������ �ƹ� Ű�� �Է��Ͽ��� ��,
				User_move(&Umain, MAP_WIDTH, map); // ������ �Է��� ����.
			StarFall(map, &Umain, MAP_WIDTH, MAP_LENGTH, &point, STARFALL, randNUJm(messenne)); // �� �������� �ڵ�
			Sleep(DELAYTIME); // �ʹ� ������ ������ ��������
			system("cls"); // ȭ���ʱ�ȭ
		}
		else {
			std::cin.clear(); // �Է¹��� �ʱ�ȭ
			Print_DEAD(map, &Umain, boomnow, MAP_WIDTH, MAP_LENGTH); // �й� �̺�Ʈ�� �����.
			boomnow = !boomnow; // �������� 2��. ��¦��¦!
			
			if (_kbhit()) { // Ű�� �Է� �Ͽ��ٴ°� �� Ȯ���ϸ�,
				system("cls"); // ȭ�� �ʱ�ȭ
				std::cout << "Point " << point << std::endl;// ����Ʈ ���
				exit(1); // �̺�Ʈ ����.
			}
			Sleep(1000);// ��¦��¦�� 1�ʰ������� ����Ѵ�.
			system("cls"); // ȭ�� �ʱ�ȭ
		}
	}
	free(map);
	return 0;
}