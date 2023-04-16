#pragma once
#include "struct.h"

// ��°���
auto Make_map(int*& map, Fly* user, int map_width, int map_length)->void;
auto Print_map(int* map, int map_width, int map_length) -> void;

// ��������
auto User_move(Fly* user, int size, int* map) -> void;
auto Move_chack(Fly* data, int wh, int* pnt, int size) -> void;
auto HPchack(Fly* user) -> bool;

// �̺�Ʈ ����
auto StarFall(int* map, Fly* user, int map_width, int map_length, int* point, int howmy, int random) -> void;
auto Print_DEAD(int* map, Fly* user, bool now, int map_width, int map_length) -> void;