#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mpi.h" // message passing interface
using namespace std;

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah

int main (int argc, char * argv[]) {

	int my_rank;			// my CPU number for this process
	int p;					// number of CPUs that we have
	int source;				// rank of the sender
	int dest;				// rank of destination
	int tag = 0;			// message number
	char message[100];		// message itself
	MPI_Status status;		// return status for receive
	
	// Start MPI
	MPI_Init(&argc, &argv);
	
	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	// Find out the number of processes!
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	// THE REAL PROGRAM IS HERE
	srand(1251);
	
	// Maximum, minimum, and average of the array
	int n = 300000;
	int * a = new int[n];
	long * pMax = new long[n];
	long * pMin = new long[n];
	long * pAvg = new long[n];
/* 
	for (int x = 0; x < n; x++)
		a[x] = rand() % 8;
	
	psum[0] = a[0];
	for (int x = 1; x < n; x++)
		psum[x] = psum[x-1] + a[x];
	
 */	
	if (my_rank == 0)
		for (int x = 0; x < n; x++)
			a[x] = rand() % 8;		
 
	// DIVIDE THE PROBLEM UP
	int * locala = new int[n/p];
	long * localpsum = new long[n/p];
	long * localmin = new long[n/p];
	long * localmax = new long[n/p];
	long * localavg = new long[n/p];
	
	MPI_Scatter(&a[0], n/p, MPI_INT, locala, n/p, MPI_INT, 0, MPI_COMM_WORLD);
	
	// DO THE LOCAL WORK
	int lowcalmax;
	int lowcalmin;
	localmax[0] = locala[0];
	for (int x = 0; x < n/p; x++){
		if (localmax[x] < localmax[x+1]){
			lowcalmax == localmax[x];
		}
		if (localmin[x] < localmax[x+1]){
			lowcalmin == localmin[x];
		}
	}
	
	// Send my last partial prefix sum answer to all LATER processors
	for (int x = my_rank + 1; x < p; x++)
		MPI_Send(lowcalmax, 1, MPI_LONG, x, tag, MPI_COMM_WORLD);
	for (int x = my_rank + 1; x < p; x++)
		MPI_Send(lowcalmin, 1, MPI_LONG, x, tag, MPI_COMM_WORLD);
	
	// Receive all the answers from processors before me
	long local_max_value = 0;
	long temp;
	for (int x = 0; x < my_rank; x++) {
		MPI_Recv(&temp, 1, MPI_LONG, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
		if (temp > local_max_value)
			local_max_value == temp;
	}

	// Add the local_additive across our localpsum
	for (int x = 0; x < n/p; x++){
		if (localmax[x] < local_max_value){
			localmax[x] == local_max_value;
		}
	}
	// COLLECT THE ANSWERS BACK TOGETHER IN A HAPPY ENDING
	MPI_Gather(localmax, n/p, MPI_LONG, pMax, n/p, MPI_LONG, 0, MPI_COMM_WORLD);
	// MPI_Allgather(localpsum, n/p, MPI_LONG, psum, n/p, MPI_LONG, MPI_COMM_WORLD);
	
	if (my_rank == 0)
		for (int x = 0; x < n; x++)
			cout << pMax[x] << endl;
			
	// Shut down MPI
	MPI_Finalize();
	
	delete [] a;
	delete [] locala;
	delete [] localpsum;
	delete [] localmax;
	delete [] localmin;
	delete [] localavg;
	delete [] pMax;
	delete [] pMin;
	delete []pAvg;

	
	return 0;
}