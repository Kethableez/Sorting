#include "Sort.h"

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
	HEAPSORT
*/

void maxHeap(int* Arr, int left, int right, int root) {
	for (int i = root / 2; i >= 1; i--) {
		int temp = Arr[left + i - 1];
		int child;
		while (i <= root / 2) {
			child = 2 * 1;
			if (child < root && Arr[left + child - 1] < Arr[left + child + 1]) {
				child++;
			}
			if (temp >= Arr[left + child - 1]) break;
			Arr[left + i - 1] = Arr[left + child - 1];
		}
		Arr[left + i - 1] = temp;
	}
}

void Heapsort(int* Arr, int left, int right) {
	int root = right - left;
	maxHeap(Arr, left, right, root);
	
	for (int i = root; i >= 1; i--) {
		int templeft = left + 1;
		std::swap(left, templeft);

		int temp = Arr[left + i - 1];
		int child;
		while (i <= root / 2) {
			child = 2 * i;
			if (child < root && Arr[left + child - 1] < Arr[left + child + 1]) child++;
			if (temp >= Arr[left + child - 1]) break;
			Arr[left + i - 1] = Arr[left + child - 1];
			i = child;
		}
		Arr[left + i - 1] = temp;
	}

}

/*
	INTROSORT
*/

int Depth(int size) {
	return (int)(2 * floor(log2(size)));
}

void Insertionsort(int* Arr, int left, int right) {
	int j, key;

	for (int i = left; i < right; i++) {
		key = Arr[i];
		j = i;

		while (j > left && Arr[j-1] > key) {
			Arr[j] = Arr[j-1];
			j--;
		}
		Arr[j] = key;
	}
}

int Partition(int* Arr, int left, int right) {
	int i, j;

	int pivot = Arr[(left + right) / 2];
	i = (left - 1);
	for (j = left; j < right; j++) {
		if (Arr[j] <= pivot) {
			i++;
			std::swap(Arr[i],Arr[j]);
		}
	}
	std::swap(Arr[i+1], Arr[right]);
	return (i+1);
}

void Introsort(int* Arr, int left, int right, int depth) {

	if (right - left > 16) {
		if (depth == 0) {
			Heapsort(Arr, left, right);
		}
		depth = depth - 1;
		int pivot = Arr[(left + right) / 2];
		std::swap(pivot, Arr[right]);
		int p = Partition(Arr, left, right);
		Introsort(Arr, p + 1, right, depth);
		Introsort(Arr, left, p - 1, depth);
	}
	else Insertionsort(Arr, left, right);
}