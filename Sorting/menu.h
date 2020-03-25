#pragma once

#define AMOUNT 100
#define PATH "C:\\Users\\mocar\\OneDrive\\Pulpit\\PWr\\PAMSI\\PROJEKT 1\\Pomiary\\"

#include <iostream>
#include <time.h>
#include <fstream>

#include <string>
#include "Array.h"
#include "Quicksort.h"
#include "Mergesort.h"
#include "Introsort.h"

/*
	Drive function
*/

void Sorting();

/* 
	Sorting functions	
*/

void Quick(int size, int choice, float perc);
void Merge(int size, int choice, float perc);
void Intro(int size, int choice, float perc);

/*
	Save to file functions
*/

void Write(int average, int total, std::string sFilename);
void CreateFile(std::string sFilename);
void SaveFile(int average, int total, std::string sortingname, std::string choice, std::string Size);