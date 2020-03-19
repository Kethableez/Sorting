#pragma once

#include <iostream>

/*
	Mergesort
*/

template <typename Item>
void Merging (Item* Arr, Item * tArr, int left, int mid, int right){
	int i = left, j = mid + 1;

	for (int i = left; i <= right; i++) {
		tArr[i] = Arr[i];
	}

	for (int k = left; k <= right; k++) {
		if (i <= mid) {
			if (j <= right) {
				if (tArr[j] < tArr[i]) Arr[k] = tArr[j++];
				else Arr[k] = tArr[i++];
			}
			else Arr[k] = tArr[i++];
		}
		else Arr[k] = tArr[j++];
	}
}

template <typename Item>
void Mergesort(Item* Arr, Item* tArr, int left, int right) {
	if (right <= left) return;

	int mid = (left + right) / 2;
	Mergesort(Arr, tArr, left, mid);
	Mergesort(Arr, tArr, mid, right);
	Merging(Arr, tArr, left, mid, right);
}



