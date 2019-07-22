#pragma once
#include <sstream>
#include "heap.h"
using namespace std;
//All methods to be implemented in util.cpp and used in main
int nextCommand(int *i, int *v, int *f);
void loadFile(string fileName,HEAP* heap);
void writeHeap(HEAP* heap);