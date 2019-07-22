#pragma once
struct ELEMENT//element structure containing a key
{
	int key;
};

struct HEAP//heap data structure
{
	int capacity;
	int size;
	ELEMENT *H;
};

//methods that perform operations on heap
HEAP Initialize(int n);
void buildMinHeap(HEAP* heap, int i);
void BuildHeap(HEAP* heap, ELEMENT* A, int n);
void Insert(HEAP* heap, int flag, int k);
int DeleteMin(HEAP* heap, int flag);
void DecreaseKey(HEAP* heap, int flag, int index, int value);
void printHeap(HEAP* heap);
