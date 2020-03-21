#include "menu.h"

void Sorting() {
	int t[5] = { 10000, 50000, 100000, 500000, 1000000 };
	float p[8] = { 0, 25, 50, 75, 95, 99, 99.7, 0 };


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				Quick(t[i], 1, p[j]);
			}
			else if (j == 7) Quick(t[i], 3, p[j]);
			else Quick(t[i], 2, p[j]);
		}
	}


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				Merge(t[i], 1, p[j]);
			}
			else if (j == 7) Merge(t[i], 3, p[j]);
			else Merge(t[i], 2, p[j]);
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				Intro(t[i], 1, p[j]);
			}
			else if (j == 7) Intro(t[i], 3, p[j]);
			else Intro(t[i], 2, p[j]);
		}
	}
}


void Quick(int size, int choice, float perc) {
	std::string sSize = std::to_string(size);
	
	std::string sChoice;
	if (choice == 1) sChoice = "Rand";
	else if (choice == 2) {
		sChoice = "Perc";
		sChoice.append(".");
		std::string sPerc = std::to_string(perc);
		sChoice.append(sPerc);
		sChoice.append(".");
	}
	else if (choice == 3) sChoice = "Rev";

	int* Tarr = new int[AMOUNT];
	bool correct = false;

	time_t tt = clock();

	if (choice == 1) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitRand();

			time_t t = clock();
			Quicksort(Arr->Arr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				//std::cout << "[Quicksort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			Arr->~Array();
		}
	}

	else if (choice == 2) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitPerc(perc);

			time_t t = clock();
			Quicksort(Arr->Arr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				//std::cout << "[Quicksort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			Arr->~Array();
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
				//std::cout << "[Quicksort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			Arr->~Array();
		}
	}
	else {
		std::cout << "Incorrect option! ";
		return;
	}

	tt = clock() - tt;

	int av = 0;
	for (int i = 0; i < AMOUNT; i++) {
		av += Tarr[i];
	}

	int average = (av / AMOUNT);

	if (correct) {
		SaveFile(average, tt, "Quicksort", sChoice, sSize);
		std::cout << "DONE!" << std::endl;
	}

	else std::cout << "Save to file error - incorrect sorting! \n";
	
	delete[] Tarr;
}

void Merge(int size, int choice, float perc) {

	std::string sSize = std::to_string(size);

	std::string sChoice;
	if (choice == 1) sChoice = "Rand";
	else if (choice == 2) {
		sChoice = "Perc";
		sChoice.append(".");
		std::string sPerc = std::to_string(perc);
		sChoice.append(sPerc);
		sChoice.append(".");
	}
	else if (choice == 3) sChoice = "Rev";

	int* Tarr = new int[AMOUNT];
	bool correct = false;

	time_t tt = clock();

	if (choice == 1) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitRand();

			time_t t = clock();
			Mergesort(Arr->Arr, Arr->tArr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				//std::cout << "[Mergesort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			Arr->~Array();
		}
	}

	else if (choice == 2) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitPerc(perc);

			time_t t = clock();
			Mergesort(Arr->Arr, Arr->tArr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				//std::cout << "[Mergesort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";

			Arr->~Array();
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
				//std::cout << "[Mergesort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Sorting is incorrect! \n";


			Arr->~Array();
		}
	}
	else {
		std::cout << "Incorrect option! ";
		return;
	}

	tt = clock() - tt;

	int av = 0;
	for (int i = 0; i < AMOUNT; i++) {
		av += Tarr[i];
	}

	int average = (av / AMOUNT);

	if (correct) {
		SaveFile(average, tt, "Mergesort", sChoice, sSize);
		std::cout << "DONE!" << std::endl;
	}
	else std::cout << "Save to file error - incorrect sorting! \n";
	delete[] Tarr;
}

void Intro(int size, int choice, float perc) {
	std::string sSize = std::to_string(size);

	std::string sChoice;
	if (choice == 1) sChoice = "Rand";
	else if (choice == 2) {
		sChoice = "Perc";
		sChoice.append(".");
		std::string sPerc = std::to_string(perc);
		sChoice.append(sPerc);
		sChoice.append(".");
	}
	else if (choice == 3) sChoice = "Rev";

	int* Tarr = new int[AMOUNT];
	bool correct = false;

	time_t tt = clock();

	if (choice == 1) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitRand();

			time_t t = clock();
			Introsort(Arr->Arr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				//std::cout << "[Introsort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Invalid sorting! \n";
			Arr->~Array();
		}
	}

	else if (choice == 2) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitPerc(perc);

			time_t t = clock();
			Introsort(Arr->Arr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				//std::cout << "[Introsort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Invalid sorting! \n";
			Arr->~Array();
		}
	}

	else if (choice == 3) {
		for (int i = 0; i < AMOUNT; i++) {
			Array* Arr = new Array(size);
			Arr->InitRev();

			time_t t = clock();
			Introsort(Arr->Arr, 0, size - 1);

			if (Arr->IsCorrect()) {
				t = clock() - t;
				Tarr[i] = (int)t;
				//std::cout << "[Introsort] Sorting time: " << t << " ms" << std::endl;
				correct = true;
			}
			else std::cout << "Invalid sorting! \n";
			Arr->~Array();
		}
	}
	else {
		std::cout << "Incorrect option! ";
		return;
	}

	tt = clock() - tt;

	int av = 0;
	for (int i = 0; i < AMOUNT; i++) {
		av += Tarr[i];
	}

	int average = (av / AMOUNT);

	if (correct) {
		SaveFile(average, tt, "Introsort", sChoice, sSize);
		std::cout << "DONE!" << std::endl;
	}
	else std::cout << "Save to file error - incorrect sorting! \n";
	delete[] Tarr;
}

void Write(int average, int total, std::string sFilename) {
	std::ofstream file;
	std::string Filename = PATH;
	Filename.append(sFilename);
	file.open(Filename);
	file << average << "\n";
	file << total << "\n";
	file.close();
}

void CreateFile(std::string sFilename) {
	std::string Filename = PATH;
	Filename.append(sFilename);
	std::ofstream file{ Filename };
}

void SaveFile(int average, int total, std::string sortingname, std::string SortType, std::string size) {
	std::string sFilename = sortingname;
	sFilename.append(".");
	sFilename.append(SortType);
	sFilename.append(".");
	sFilename.append(size);
	sFilename.append(".txt");
	CreateFile(sFilename);
	Write(average, total, sFilename);
}