#include "heap.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

HEAP Initialize(int n)//creates heap object with size zero and capacity n
{
	HEAP* heap=(HEAP*)malloc(sizeof(HEAP));
	heap->capacity = n;
	heap->size = 0;
	heap->H = new ELEMENT[n+1];
	return *heap;
}
void buildMinHeap(HEAP* heap, int i)//method used to build the heap. Makes it a min heap structure
{
	int left = 2 * i;
	int right = 2 * i + 1;
	int min = 0;

	if ((left <= heap->size) && (heap->H[left].key < heap->H[i].key))//checks if the left child is smaller
	{
		min = left;
	}
	else
	{
		min = i;
	}

	if ((right <= heap->size) && (heap->H[right].key < heap->H[min].key))//checks if right child is smaller than min
	{
		min = right;
	}

	if (min != i)//swaps values and recursively calls function until the min heap is complete
	{
		int temp = heap->H[i].key;
		heap->H[i].key = heap->H[min].key;
		heap->H[min].key = temp;

		buildMinHeap(heap, min);
	}
}

void BuildHeap(HEAP* heap, ELEMENT* A, int n)//copies the elements of A into the heap and calls buildMinHeap to create min heap structure
{
	if (heap->capacity < n)
	{
		cout << "Sorry!! It cannot be done. Please increase the capacity of heap first." << endl;
	}
	for (int i = 0; i < n; i++)
	{
		heap->H[i + 1] = A[i];
		heap->size++;
	}

	for (int i = heap->size / 2; i >= 1; i--)
	{
		buildMinHeap(heap, i);
	}
}

void Insert(HEAP* heap, int flag, int k) //inserts the value into the heap data structure
{
	if (heap == NULL||heap->capacity==0)
	{
		cout << "Sorry!! It cannot be done. Please initialize the heap first." << endl;
	}
	else {
		
		if (flag == 1)
		{
			int size = pow(2,(int)log2(heap->size) + 1);//find the next power of two to increment capacity
			heap->size++;
			int i = heap->size;
			if (heap->capacity < heap->size)//if there is not enough capacity increment it to next power of two
			{
				ELEMENT* newH = new ELEMENT[size];//element array to hold elements from original heap
				for (int j = 1; j < heap->size; j++)
				{
					newH[j].key = heap->H[j].key;
				}
				delete[] heap->H;//free memory no longer used
				heap->H = newH;
				heap->capacity = size;//increment capacity
			}
			while (i > 1 && heap->H[i / 2].key > k)//rebuild min heap structure
			{
				heap->H[i].key = heap ->H[i/2].key;
				i = i / 2;
			}
			heap->H[i].key = k;
			
		}

		else if (flag == 2)
		{
			printHeap(heap);
			int size = pow(2,(int)log2(heap->size) + 1);
			heap->size++;
			int i = heap->size;
			if (heap->capacity < heap->size)
			{
				ELEMENT* newH = new ELEMENT[size];
				for (int j = 1; j < heap->size; j++)
				{
					newH[j].key = heap->H[j].key;
				}
				delete[] heap->H;
				heap->H = newH;
				heap->capacity = size;
			}

			while (i > 1 && heap->H[i / 2].key > k)
			{
				heap->H[i].key = heap->H[i/2].key;
				i = i / 2;
			}
			heap->H[i].key = k;
			printHeap(heap);
		
		}
		else
		{
			cout << "This is not a valid flag value. This operation cannot be completed." << endl;
		}
		
	}
}

int DeleteMin(HEAP* heap, int flag)//deletes the min and rebuilds heap if possible
{
	if (heap==NULL||heap->capacity==0)
	{
		cout << "Sorry!! It cannot be done. Please initialize the heap and put elements into it." << endl;
		return 0;//returns a value since the method must return an integer
	}
	else if (heap->size == 0)
	{
		cout << "There are no elements in heap to delete." << endl;
		return 0;
	}
	else
	{

		if (flag == 1)//only removes the min and restructures heap
		{
			int min = heap->H[1].key;
			heap->H[1] = heap->H[heap->size];
			heap->size--;
			buildMinHeap(heap, 1);
			return min;
		}

		else if (flag == 2)//prints heap before and after the min is removed
		{
			printHeap(heap);
			int min = heap->H[1].key;
			heap->H[1] = heap->H[heap->size];
			heap->size--;
			buildMinHeap(heap, 1);
			printHeap(heap);
			return min;
		}
		else{
			cout << "This is not a valid flag value. This operation cannot be completed." << endl;
			return 0;
		}
	}
}

void DecreaseKey(HEAP* heap, int flag, int index, int value)//decreases the value stored at the given index if possible and remakes heap
{
	if (heap == NULL||heap->capacity==0)
	{
		cout << "Sorry!! It cannot be done. Please initialize the heap first and put elements into it." << endl;
	}
	else if (heap->size <= 3)//not enough elements to decrease key
	{
		cout << "There are only " << heap->size << " elements in the heap. Hence this operation cannot be completed" << endl;
	}
	else if (value > heap->H[index].key)//value given is larger than current. Invalid because this would increase key
	{
		cout << value << " cannot be larger than the current value in the heap at index " << index << ". Hence this operation cannot be completed." << endl;
	}
	else
	{
		heap->H[index].key = value;
		
		if (flag == 1)//decreases key and reorganizes heap only
		{
			while (index > 1 && heap->H[index / 2].key > heap->H[index].key)
			{
				int temp = heap->H[index].key;
				heap->H[index].key = heap->H[index / 2].key;
				heap->H[index / 2].key = temp;
				index = index / 2;
			}
		}

		if (flag == 2)//decreases key and reorganizes heap. prints heap before and after operation
		{
			printHeap(heap);
			while (index > 1 && heap->H[index / 2].key > heap->H[index].key)
			{
				int temp = heap->H[index].key;
				heap->H[index].key = heap->H[index / 2].key;
				heap->H[index / 2].key = temp;
				index = index / 2;
			}
			printHeap(heap);
		}

	}
}


void printHeap(HEAP* heap)//prints heap info
{
	cout << "The capacity is "<<heap->capacity << endl;
	cout << "Size is " << heap->size << endl;

	for (int i = 1; i <= heap->size; i++)
	{
		cout << heap->H[i].key << endl;
	}
}
