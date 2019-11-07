// Austin Sypolt
// CS452 Parallel Algorithms
// Project 2 | A Minor Character Can Still Drink Heavily
// Due: 2/25/19

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
using namespace std;
 
void merge(int *a, int first, int last, int middle)
{
	int b[last-first+1];
	int i = first; //First element
	int k = 0; //Initial element
	int j = middle + 1; //This will be the start of the 2nd half of the array
 
	//This merges the two parts of the array into a temporary array b
	while (i <= middle && j <= last)
	{
		if (a[i] < a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else
		{
			b[k] = a[j];
			k++;
			j++;
		}
	}
 
	//Leftover items are moved into array b
	while (i <= middle)
	{
		b[k] = a[i];
		k++;
		i++;
	}
	while (j <= last)
	{
		b[k] = a[j];
		k++;
		j++;
	}
 
	//Bring the merged data back to the original array a
	for (i = first; i <= last; i++)
	{
		a[i] = b[i-first];
	}
}

void mergesort(int *a, int first, int last)
{
	int middle; //Acts as the middle point to identify where the split happens
	if (first < last)
	{
		middle=(first+last)/2;
		//Splits the data in half for separate merge analysis
		mergesort(a, first, middle);
		mergesort(a, middle+1, last);
		//Puts the sorted data into a single array
		merge(a, first, last, middle);
	}
}
 
int main()
{
	int arraySize, i; //Initializing arraySize variable and loop variable i
	cout << "Please specify the size of the array: " << endl;
	cin >> arraySize;
	srand(time(0));
	int a[arraySize] = {0};
	
	//Fill the array a of size arraySize with random numbers
	for(i = 0; i < arraySize; i++) {
		a[i] = rand() % 100000;
	}
	
 	mergesort(a, 0, arraySize-1);
	
	cout<<"Final Sorted Array: ";
	for (i = 0; i < arraySize; i++)
        cout<< " " << a[i]; //Print out sorted array elements
	cout << endl;
 
	return 0;
}