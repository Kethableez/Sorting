#pragma once

#include <iostream>
#include <math.h>
#include <time.h>
#include "Sort.h"

class Array{
public:
	int size;
	int* Arr;
	int* tArr;

	Array(int size);

	void InitRand();
	void InitPerc(int percent);
	void InitRev();

	void Show();
	bool IsCorrect();
};