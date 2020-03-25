#pragma once

#include <iostream>
#include <math.h>

/* 
	Swap method
*/

template <typename Item>
void Swap(Item* Arr, int arg1, int arg2) {
	Item temp = Arr[arg1];
	Arr[arg1] = Arr[arg2];
	Arr[arg2] = temp;
}

/*
	INSERTIONSORT
*/

template <typename Item>
void Insertionsort(Item* Arr, int left, int right) {
	right++;
	int i = left;
	while (i < right) {
		int j = i;
		while (j > 0 && Arr[j - 1] > Arr[j]) {
			Swap(Arr, j, j - 1);
			--j;
		}
		++i;
	}
}

/*
	HEAPSORT
*/

template <typename Item>
void Heapify(Item* Arr, int size, int root) {
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < size && Arr[left] > Arr[largest]) largest = left;
	if (right < size && Arr[right] > Arr[largest]) largest = right;
	if (largest != root) {
		Swap(Arr, root, largest);
		Heapify(Arr, size, largest);
	}
}

template <typename Item>
void Heapsort(Item* Arr, int left, int right) {
	++right;

	Item* temp = new Item[right - left];
	for (int i = 0; i < right - left; i++) {
		temp[i] = Arr[i + left];
	}

	for (int i = (right - left) / 2 - 1; i >= 0; --i) {
		Heapify(temp, (right - left), i);
	}

	for (int i = (right - left) - 1; i >= 0; --i) {
		Swap(temp, 0, i);
		Heapify(temp, i, 0);
	}

	for (int i = 0; i < right - left; i++) {
		Arr[i + left] = temp[i];
	}

	delete[] temp;
}

/*
	Partition method
*/

template <typename Item>
int Partition(Item* Arr, int left, int right) {
	Item pivot = Arr[(left + right) / 2];

	int i = left - 1;
	int j = right + 1;

	while (1) {
		do ++i;
		while (Arr[i] < pivot);

		do --j;
		while (Arr[j] > pivot);

		if (i >= j) return j;
		Swap(Arr, i, j);
	}
}

/*
	INTROSORT
*/

template <typename Item>
void IntroProcedure(Item* Arr, int left, int right, int maxdepth) {
	int size = right - left + 1;

	if (size <= 16) Insertionsort(Arr, left, right);
	else if (maxdepth == 0) Heapsort(Arr, left, right);
	else if (left < right) {
		int pivot = Partition(Arr, left, right);
		IntroProcedure(Arr, left, pivot, --maxdepth);
		IntroProcedure(Arr, pivot + 1, right, --maxdepth);
	}
}

template <typename Item>
void Introsort(Item* Arr, int left, int right) {
	int maxdepth = (int)log(right - left + 1) * 2;
	IntroProcedure(Arr, left, right, maxdepth);
}