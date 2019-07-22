#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "heap.h"
#include "Main.h"
using namespace std;
int main()
{
	char c;//command character
	int i, v, f;//variables to hold various flag key and index inputs
	int min = 0;
	HEAP* heap=(HEAP*)malloc(sizeof(HEAP));
	while (1)
	{
		c = nextCommand(&i, &v, &f);
		switch (c)
		{
		case 's':
		case 'S': printf("COMMAND: %c. \n", c);//terminate
			printf("The program is going to be terminated.");
			exit(0);
		case 'k':
		case 'K': printf("COMMAND: %c %d %d %d. \n", c, i, v, f);//decrease key
			DecreaseKey(heap, i, v, f);
			break;
		case 'd':
		case 'D': printf("COMMAND: %c %d \n", c, i);
			min=DeleteMin(heap, i);
			if (heap == NULL || min==0) //since deletemin returns zero if operation is not done, this prevents the zero from being printed
			{

			}
			else
			{
				printf("%d", min);
			}
			break;
		case 'c':
		case 'C': printf("COMMAND: %c %d \n", c, i); //initializes the heap
			*heap=Initialize(i);
			break;
		case 'i':
		case 'I': printf("COMMAND: %c %d %d \n", c, i, v); //insert
			Insert(heap, i, v);
			break;
		case 'r':
		case 'R': printf("COMMAND: %c. \n", c); //read from file
			loadFile("HEAPinput.txt",heap);
			break;
		case 'w':
		case 'W':
			printf("COMMAND: %c \n", c); //write info to screen
			writeHeap(heap);
			break;
		
		default:break;
		}
	}

	exit(0);
}
