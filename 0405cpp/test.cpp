﻿#include <iostream>

int main() {

	int arr[2][3] = { 1, 2, 3, 4, 5, 6 };
	int(*p)[3] = NULL;

	p = arr;

	printf("%d\n", *(p[0] + 1) + *(p[1] + 2));
	printf("%d\n", *(*(p + 1) + 0) + *(*(p + 1) + 1));

	return 0;
}
