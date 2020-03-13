#include "Sort.h"
auto swap = [](auto&a,auto&b) 
{
	auto temp = a;
	a = b;
	b = temp;

};
/*
	QUICKSORT
*/

void Quicksort(int* Arr, int left, int right) {
	if (right <= left) return;

	int i = left - 1;
	int j = right + 1;
	int pivot = Arr[(left + right) / 2];

	while (true) {
		while (pivot < Arr[--j]);
		while (pivot > Arr[++i]);

		
		if (i <= j) {
			
			int temp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = temp;
		}
		else break;
	}
	
	if (j > left) Quicksort(Arr, left, j);
	if (i < right) Quicksort(Arr, i, right);
}

/*
	MERGESORT
*/

void Merging(int* Arr, int* tArr, int left, int mid, int right) {
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

void Mergesort(int* Arr, int* tArr, int left, int right) {
	if (right <= left) return;

	int mid = (left + right) / 2;
	Mergesort(Arr, tArr, left, mid);
	Mergesort(Arr, tArr, mid + 1, right);
	Merging(Arr, tArr, left, mid, right);
}

/*
	INTROSORT
*/

void Introsort(int* Arr, int left, int right, int depth) {
	while (right - left > 0) {
		if (depth == 0)
			Heapsort(&Arr[left], left, right - left + 1);
		else {
			int pivot;
			pivot = Partition(Arr, left, right);
			Introsort(Arr, pivot + 1, right, depth - 1);
			right = pivot - 1;
		}
	}
}

/*
	
*/

void HybridIntro(int* Arr, int n) {
	Introsort(Arr, 0, n - 1, (int(2 * log(double(n)))));
	Insertion(Arr, n);
}

int Partition(int* Arr, int first, int last) {
	int pivot, mid = (first + last) / 2;

	pivot = Arr[first] > Arr[mid] ? first : mid;

	if (Arr[pivot] > Arr[last])
		pivot = last;

	Swap(&Arr[pivot], &Arr[first]);
	pivot = first;

	while (first < last) {
		if (Arr[first] <= Arr[last])
			Swap(&Arr[pivot++], &Arr[first]);
		++first;
	}

	Swap(&Arr[pivot], &Arr[last]);
	return pivot;
}

void Insertion(int* Arr, int n) {
	int i;
	for (i = 1; i < n; i++) {
		int j, save = Arr[i];
		for (j = i; j >= 1 && Arr[j - 1] > save; j--)
			Arr[j] = Arr[j - 1];
		Arr[j] = save;
	}
}

void Swap(int* a, int* b) {
	int save = *a;
	*a = *b;
	*b = save;
}
void maxHeap(int* Arr, int left, int right) {
	int save = Arr[left];
	while (left <= right / 2) {
		int k = 2 * left;
		while (k < right && Arr[k] < Arr[k + 1])
			++k;
		if (save >= Arr[k])
			break;
		Arr[left] = Arr[k];
		left = k;
	}
	Arr[left] = save;
}

void Heapsort(int* Arr, int left, int right) {
	int i;
	for (int i = (right - 1) / 2; i >= left; i--) {
		maxHeap(Arr, i, right - 1);
	}
	for (i = right - 1; i > left; i--) {
		Swap(&Arr[i], &Arr[left]);
		maxHeap(Arr, left, i - 1);
	}
}