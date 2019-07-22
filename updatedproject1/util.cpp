#include "util.h"
#include "heap.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int nextCommand(int *i, int *v, int *f)
{
	char c;
	while (1)
	{
		cin>>c;
		if (c == ' ' || c == '\t' || c == '\n')
		{
			continue;
		}

		if(c =='S'||c =='R'||c =='W')
		{
			break;
		}

		if (c == 'K' || c == 'k')
		{
			scanf("%d",i);
			scanf("%d", v);
			scanf("%d", f);
			break;
		}

		if (c == 'C'||c=='D')
		{
			scanf("%d", i);
			break;
		}

		if (c == 'I')
		{
			scanf("%d", i);
			scanf("%d", v);
			break;
		}
		else {
			printf("invalid Command\n");
		}

	}
	return c;
}


void loadFile(string fileName,HEAP* heap) //gets information about the heap from a file and creates heap provided that conditions are met
{
	if (heap == NULL||heap->capacity==0)//makes sure heap is initialized
	{
		cout << "Sorry!! It cannot be done. Please initialize the heap first." << endl;
	}
	else {


		ifstream theFile; //file object
		theFile.open(fileName.c_str());

		int n = 0; //holds capacity number
		int i = 0; //counts number of elements
		ELEMENT A[100]; //generic element array to store key values that will be copied to heap
		if (theFile.is_open())
		{
			theFile >> n;

			while(!theFile.eof())
			{
				theFile >> A[i].key; //copies into array
				i++;
			}
			theFile.close();
			if (i < n)//not enough elements in file
			{
				cout << "Sorry!! It cannot be done. The number of elements in file is less than as specified in the beginning of file." << endl;
			}
			else {
				BuildHeap(heap, A, n);
			}
		}
		else
		{
			cout << "There was a problem opening file " << fileName << " for reading."<<endl;
		}
	}
}

void writeHeap(HEAP* heap)//Prints heap info if the heap exists
{
	if (heap == NULL||heap->capacity==0)
	{
		cout << "Sorry!! It cannot be done. Please initialize the heap first" << endl;
	}
	else
	{
		
		printHeap(heap);
	}
}
