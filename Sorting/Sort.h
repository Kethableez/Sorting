#pragma once

#include <iostream>
#include <time.h>
#include "Array.h"

void Quicksort(int* Arr, int left, int right);

void Merging(int* Arr, int* tArr, int left, int mid, int right);
void Mergesort(int* Arr, int* tArr, int left, int right);

void maxHeap(int* Arr, int left, int right, int i);
void Heapsort(int* Arr, int left, int right);

int Depth(int size);
void Insertionsort(int* Arr, int left, int right);
void Introsort(int* Arr, int left, int right, int depth);
int Partition(int* Arr, int left, int right);
