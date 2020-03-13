#pragma once

#define AMOUNT 100
#define PATH "C:\\Users\\mocar\\OneDrive\\Pulpit\\PWr\\PAMSI\\PROJEKT 1\\Pomiary\\"

#include <iostream>
#include <time.h>
#include <fstream>

#include "Array.h"
#include "Sort.h"

void menu();
void submenu();

void interface();

void Quick(int size, int choice);
void Merge(int size, int choice);
void Intro(int size, int choice);

void Write(int* time, std::string sFilename);
void CreateFile(std::string sFilename);
void SaveFile(int* tArr, std::string sortingname);