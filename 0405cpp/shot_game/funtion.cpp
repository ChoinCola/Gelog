#pragma once

#include "head.h"
#include "funtion.h"

// 맵과 유저를 반환한다.
auto Make_map(int*& map, Fly* user, int map_width, int map_length) -> void
{
	int* result = (int*)calloc(map_length * map_width + 1, sizeof(int));

	for (int i = 0; i < map_length * map_width; i++) // 초기화
		*(result + i) = 0;

	for (int i = 0; i < map_width; i++) { // 맨위  맨밑 벽 생성
		*(result + i) = 1;
		*(result + (map_width * map_length) - i) = 1;
	}

	for (int i = 0; i < map_length; i++) { // 좌측끝, 우측끝 벽 생성
		*(result + map_width * i) = 1;
		*(result + map_width * (i + 1) - 1) = 1;
	}

	user->x = map_width / 2;
	user->y = (map_length - map_length / 5);

	*(result + (user->y * map_width) + user->x) = 3; // 유저 위치 지정.

	map = result;
}


auto Print_map(int* map, int map_width, int map_length) -> void // 맵 출력함.
{
	for (int i = 0; i < map_length; i++) {
		for (int j = 0; j < map_width; j++) { // 전체조회하면서 맞는 기호를 출력한다.
			switch (*(map + (map_width * i) + j))
			{
			case 0:
				std::cout << "  ";
				break;
			case 1:
				std::cout << "□";
				break;
			case 2:
				std::cout << "※";
				break;
			case 3:
				std::cout << "△";
				break;
			case 4:
				std::cout << "☆";
				break;
			case 5:
				std::cout << "★";
				break;

			default:
				break;
			}
		}
		std::cout << '\n'; // 엔터.
	}
}

auto User_move(Fly* user,int size , int* map) -> void // 유저 움직임에 따라 유저를 움직임.
{
	int movekey;
	movekey = _getch();
	if (movekey == 224) {
		movekey = _getch();
		switch (movekey)
		{
		case 72: // 위
			printf("위 입력\n");
			Move_chack(user, -size, map, size);
			break;
		case 75: // 왼쪽
			printf("왼 입력\n");
			Move_chack(user, -1, map, size);
			break;
		case 77: // 오른쪽
			printf("오른 입력\n");
			Move_chack(user, 1, map, size);
			break;
		case 80: // 아래
			printf("아래 입력\n");
			Move_chack(user, size, map, size);
			break;
		}
	}
}

auto Move_chack(Fly* data, int wh, int* pnt, int size) -> void // 움직인 대로 맵에 반영한다. 반영 못할경우 갱신X
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
	// 별똥별 코드.

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
	}// 지형 전체 순회하면서, 역순으로 방문, 그리고 조건을 비교하여 가능한 경우 한칸 밑으로 내림.

	// make star
	// 지형순회 완료 시 별 제작하여 첫번째 줄에 뿌림.
	for (int i = 0; i < howmy; i++)
		*(map + random + map_width) = 2;

	*point += howmy * 50;
}

auto HPchack(Fly* user) -> bool // 체력이 0인지 아닌지 체크.
{
	if (user->hp == 0)
		return false;
	else
		return true;
}

auto Print_DEAD(int* map, Fly* user,bool now, int map_width, int map_length) -> void // 죽으면 빤짝빤짝!
{
	int boom1[][3] =  { 4,4,4,
						4,5,4,
						4,4,4 }; // 반짝이는 패턴 구현.
	int boom2[][3] =  { 5,5,5,
						5,4,5,
						5,5,5 };

	int* xy = map + user->x + user->y * map_width - ( 1 + map_width ); // 패턴을 만들 상대좌표 제작.

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (*(xy + i * map_width + j) == 1) { // 옆칸 위칸 밑칸 이 벽일 경우 패스
				continue;
			}

			switch (now) // 반짝반짝이게 패턴출력한다.
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