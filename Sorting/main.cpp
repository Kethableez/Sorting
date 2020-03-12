#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "menu.h"

using namespace std;

int main() {
	srand(time(NULL));
	
	//interface();

	//int size = 1000000;
	//Array* Arr = new Array(size);

	int size = 30;
	Array* Arr = new Array(size);
	Arr->InitRand();
	//Arr->Show();

	Introsort(Arr->Arr, 0, size-1, Depth(size));
	if (Arr->IsCorrect()) {
		std::cout << "correct\n";
	}
	else std::cout << "incorrect\n";
	//if (Arr->IsCorrect()) {
	//	std::cout << "Correct \n";
	//}
	//else s	std::cout << "\n";td::cout << "Incorrect \n";

	//Arr->Show();
	//interface();
	
}