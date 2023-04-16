#pragma once
#include "struct.h"

// 출력관련
auto Make_map(int*& map, Fly* user, int map_width, int map_length)->void;
auto Print_map(int* map, int map_width, int map_length) -> void;

// 유저관련
auto User_move(Fly* user, int size, int* map) -> void;
auto Move_chack(Fly* data, int wh, int* pnt, int size) -> void;
auto HPchack(Fly* user) -> bool;

// 이벤트 관련
auto StarFall(int* map, Fly* user, int map_width, int map_length, int* point, int howmy, int random) -> void;
auto Print_DEAD(int* map, Fly* user, bool now, int map_width, int map_length) -> void;