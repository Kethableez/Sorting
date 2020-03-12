#include "menu.h"

void menu() {
	std::cout << "Choose sorting algorithm: " << std::endl;
	std::cout << "1. Quicksort" << std::endl;
	std::cout << "2. Mergesort" << std::endl;
	std::cout << "3. Introsort" << std::endl;
	std::cout << "4. Quit" << std::endl;
}

void submenu() {
	std::cout << "Choose initialize type:" << std::endl;
	std::cout << "1. Random elements" << std::endl;
	std::cout << "2. Percent of sorted elements" << std::endl;
	std::cout << "3. Reverse order " << std::endl;
}

void interface() {
	int k = 0, b, size;

	while (k != 4) {
		menu();
		std::cin >> k;

		if (k != 4) {
			submenu();
			std::cin >> b;

			std::cout << "Enter size: ";
			std::cin >> size;

			switch (k) {
			case 1:
				Quick(size, b);
				break;

			case 2:
				Merge(size, b);
				break;

			case 3:
				//Intro(size, b);
				break;

			case 4:
				break;

			default:
				std::cout << "Incorrect option";
				break;
			}
		}
		else break;
	}
}

void Quick(int size, int choice) {

	int* Tarr = new int[AMOUNT];
	bool correct = false;

	if (choice == 1) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitRand();

			time_t t = clock();
			Quicksort(Arr->Arr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				std::cout << "[Quicksort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			delete Arr;
		}
	}

	else if (choice == 2) {
		int perc;
		std::cout << "Enter percentage: ";
		std::cin >> perc;
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitPerc(perc);

			time_t t = clock();
			Quicksort(Arr->Arr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				std::cout << "[Quicksort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			delete Arr;
		}
	}

	else if (choice == 3) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitRev();

			time_t t = clock();
			Quicksort(Arr->Arr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				std::cout << "[Quicksort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			delete Arr;
		}
	}
	else {
		std::cout << "Incorrect option! ";
		return;
	}

	if (correct) {
		SaveFile(Tarr, "Quicksort");
	}

	else std::cout << "Save to file error - incorrect sorting! \n";
	
}

void Merge(int size, int choice) {
	int* Tarr = new int[AMOUNT];
	bool correct = false;

	if (choice == 1) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitRand();

			time_t t = clock();
			Mergesort(Arr->Arr, Arr->tArr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				std::cout << "[Mergesort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			delete Arr;
		}
	}

	else if (choice == 2) {
		int perc;
		std::cout << "Enter percentage: ";
		std::cin >> perc;
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitPerc(perc);

			time_t t = clock();
			Mergesort(Arr->Arr, Arr->tArr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				std::cout << "[Mergesort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			delete Arr;
		}
	}

	else if (choice == 3) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitRev();

			time_t t = clock();
			Mergesort(Arr->Arr, Arr->tArr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				std::cout << "[Mergesort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";


			delete Arr;
		}
	}
	else {
		std::cout << "Incorrect option! ";
		return;
	}

	if (correct) {
		SaveFile(Tarr, "Mergesort");
	}
	else std::cout << "Save to file error - incorrect sorting! \n";

}

//void Intro(int size, int choice) {
//	int* Tarr = new int[AMOUNT];
//	bool correct = false;
//
//	if (choice == 1) {
//		for (int i = 0; i < AMOUNT; i++) {
//			Array* Arr = new Array(size);
//			Arr->InitRand();
//
//			time_t t = clock();
//			Hybrid(Arr->Arr, size);
//
//			if (Arr->IsCorrect()) {
//				t = clock() - t;
//				Tarr[i] = (int)t;
//				std::cout << "[Introsort] Sorting time: " << t << " ms" << std::endl;
//				correct = true;
//			}
//			else std::cout << "Invalid sorting! \n";
//			delete[] Arr;
//		}
//	}
//
//	else if (choice == 2) {
//		int perc;
//		std::cout << "Enter percentage: ";
//		std::cin >> perc;
//
//		for (int i = 0; i < AMOUNT; i++) {
//			Array* Arr = new Array(size);
//			Arr->InitPerc(perc);
//
//			time_t t = clock();
//			Hybrid(Arr->Arr, size);
//
//			if (Arr->IsCorrect()) {
//				t = clock() - t;
//				Tarr[i] = (int)t;
//				std::cout << "[Introsort] Sorting time: " << t << " ms" << std::endl;
//				correct = true;
//			}
//		}
//	}
//
//	else if (choice == 3) {
//		for (int i = 0; i < AMOUNT; i++) {
//			Array* Arr = new Array(size);
//			Arr->InitRev();
//
//			time_t t = clock();
//			Hybrid(Arr->Arr, size);
//
//			if (Arr->IsCorrect()) {
//				t = clock() - t;
//				Tarr[i] = (int)t;
//				std::cout << "[Introsort] Sorting time: " << t << " ms" << std::endl;
//				correct = true;
//			}
//		}
//	}
//}

void Write(int* time, std::string sFilename) {
	std::ofstream file;
	std::string Filename = PATH;
	Filename.append(sFilename);
	file.open(Filename);
	for (int i = 0; i < AMOUNT; i++) {
		file << time[i] << "\n";
	}
	file.close();
}

void CreateFile(std::string sFilename) {
	std::string Filename = PATH;
	Filename.append(sFilename);
	std::ofstream file{ Filename };
}

void SaveFile(int* tArr, std::string sortingname) {
	std::cout << "Enter initialization type: " << std::endl;
	std::string temp;
	std::cin >> temp;
	std::string sFilename = sortingname;

	sFilename.append(temp);
	sFilename.append(".");

	std::cout << "Enter size: " << std::endl;
	std::cin >> temp;

	sFilename.append(temp);
	sFilename.append(".txt");

	CreateFile(sFilename);
	Write(tArr, sFilename);
}