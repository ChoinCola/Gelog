#pragma once

#include "head.h"
#include "funtion.h"

// �ʰ� ������ ��ȯ�Ѵ�.
auto Make_map(int*& map, Fly* user, int map_width, int map_length) -> void
{
	int* result = (int*)calloc(map_length * map_width + 1, sizeof(int));

	for (int i = 0; i < map_length * map_width; i++) // �ʱ�ȭ
		*(result + i) = 0;

	for (int i = 0; i < map_width; i++) { // ����  �ǹ� �� ����
		*(result + i) = 1;
		*(result + (map_width * map_length) - i) = 1;
	}

	for (int i = 0; i < map_length; i++) { // ������, ������ �� ����
		*(result + map_width * i) = 1;
		*(result + map_width * (i + 1) - 1) = 1;
	}

	user->x = map_width / 2;
	user->y = (map_length - map_length / 5);

	*(result + (user->y * map_width) + user->x) = 3; // ���� ��ġ ����.

	map = result;
}


auto Print_map(int* map, int map_width, int map_length) -> void // �� �����.
{
	for (int i = 0; i < map_length; i++) {
		for (int j = 0; j < map_width; j++) { // ��ü��ȸ�ϸ鼭 �´� ��ȣ�� ����Ѵ�.
			switch (*(map + (map_width * i) + j))
			{
			case 0:
				std::cout << "  ";
				break;
			case 1:
				std::cout << "��";
				break;
			case 2:
				std::cout << "��";
				break;
			case 3:
				std::cout << "��";
				break;
			case 4:
				std::cout << "��";
				break;
			case 5:
				std::cout << "��";
				break;

			default:
				break;
			}
		}
		std::cout << '\n'; // ����.
	}
}

auto User_move(Fly* user,int size , int* map) -> void // ���� �����ӿ� ���� ������ ������.
{
	int movekey;
	movekey = _getch();
	if (movekey == 224) {
		movekey = _getch();
		switch (movekey)
		{
		case 72: // ��
			printf("�� �Է�\n");
			Move_chack(user, -size, map, size);
			break;
		case 75: // ����
			printf("�� �Է�\n");
			Move_chack(user, -1, map, size);
			break;
		case 77: // ������
			printf("���� �Է�\n");
			Move_chack(user, 1, map, size);
			break;
		case 80: // �Ʒ�
			printf("�Ʒ� �Է�\n");
			Move_chack(user, size, map, size);
			break;
		}
	}
}

auto Move_chack(Fly* data, int wh, int* pnt, int size) -> void // ������ ��� �ʿ� �ݿ��Ѵ�. �ݿ� ���Ұ�� ����X
{
	int* movedata;
	movedata = pnt + data->x + data->y * size;
	printf("%d\n", *movedata);
	if (*(movedata + wh) == 0) {
		*movedata = 0;
		*(movedata + wh) = 3;
		data->x += wh % size;
		data->y += wh / size;
	}
}

auto StarFall(int* map,Fly* user ,int map_width, int map_length,int* point ,int howmy, int random) -> void
{
	int star = howmy;
	// ���˺� �ڵ�.

	// starfall now
	for (int i = map_width * map_length; i > 0; i--) {
		if (*(map + i) == 2 && *(map + i + map_width) != 1 && i + map_width < map_width * map_length && *(map + i + map_width) != 3) {
			*(map + i) = 0;
			*(map + i + map_width) = 2;
		}
		else if (*(map + i) == 2 && *(map + i + map_width) == 1) {
			*(map + i) = 0;
		}
		else if (*(map + i) == 2 && *(map + i + map_width) == 3) {
			*(map + i) = 0;
			user->hp --;
		}
	}// ���� ��ü ��ȸ�ϸ鼭, �������� �湮, �׸��� ������ ���Ͽ� ������ ��� ��ĭ ������ ����.

	// make star
	// ������ȸ �Ϸ� �� �� �����Ͽ� ù��° �ٿ� �Ѹ�.
	for (int i = 0; i < howmy; i++)
		*(map + random + map_width) = 2;

	*point += howmy * 50;
}

auto HPchack(Fly* user) -> bool // ü���� 0���� �ƴ��� üũ.
{
	if (user->hp == 0)
		return false;
	else
		return true;
}

auto Print_DEAD(int* map, Fly* user,bool now, int map_width, int map_length) -> void // ������ ��¦��¦!
{
	int boom1[][3] =  { 4,4,4,
						4,5,4,
						4,4,4 }; // ��¦�̴� ���� ����.
	int boom2[][3] =  { 5,5,5,
						5,4,5,
						5,5,5 };

	int* xy = map + user->x + user->y * map_width - ( 1 + map_width ); // ������ ���� �����ǥ ����.

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (*(xy + i * map_width + j) == 1) { // ��ĭ ��ĭ ��ĭ �� ���� ��� �н�
				continue;
			}

			switch (now) // ��¦��¦�̰� ��������Ѵ�.
			{
			case true:
				*(xy + i * map_width + j) = boom1[i][j];
				break;
			case false:
				*(xy + i * map_width + j) = boom2[i][j];
				break;
			}
		}
	}
}