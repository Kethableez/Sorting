#pragma once
#include <iostream>

template <typename Item>
void Quicksort(Item* Arr, int left, int right) {
	if (right <= left) return;

	int i = left - 1;
	int j = right + 1;
	Item pivot = Arr[(left + right) / 2];

	while (true) {
		while (pivot < Arr[--j]);
		while (pivot > Arr[++i]);

		if (i <= j) {
			Item temp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = temp;
		}
		else break;
	}

	if (j > left) Quicksort(Arr, left, j);
	if (i < right) Quicksort(Arr, i, right);
}