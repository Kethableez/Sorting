#include "Array.h"

Array::Array(int nSize) {
	this->size = nSize;

	this->Arr = new int[this->size];
	this->tArr = new int[this->size];
}

void Array::InitRand() {
	for (int i = 0; i < this->size; i++) {
		this->Arr[i] = 1 + rand() % (this->size);
	}
}

void Array::InitPerc(int percent) {
	int p = (this->size * percent) / 100;

	for (int i = 0; i < this->size; i++) {
		if (i < p) this->Arr[i] = i + 1;
		else this->Arr[i] = 1 + rand() % (this->size * 10);
	}
}

void Array::InitRev() {
	int j = this->size;

	for (int i = 0; i < this->size; i++) {
		this->Arr[i] = j;
		j--;
	}
}

void Array::Show() {
	for (int i = 0; i < this->size; i++) {
		std::cout << this->Arr[i] << " ";
	}
}

bool Array::IsCorrect() {
	for (int i = 0; i < this->size; i++) {		
		if (i == 0) {
			if (this->Arr[i] > this->Arr[i + 1]) {
				std::cout << this->Arr[i] << " " << this->Arr[i + 1] << std::endl;
				return false;
			}
		}

		else if (i == this->size - 1) {
			if (this->Arr[i] < this->Arr[i - 1]) {
				std::cout << this->Arr[i] << " " << this->Arr[i - 1] << std::endl;
				return false;
			}
		}

		else {
			if (this->Arr[i + 1] < this->Arr[i]) {
				std::cout << this->Arr[i] << " " << this->Arr[i + 1] << std::endl;
				return false;
			}
		}
	}
	return true;
}