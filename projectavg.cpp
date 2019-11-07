/* Austin Sypolt CS452 Parallel Algorithms */

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
	
	srand(1231);
	
	int n = 300000;
	int * a = new int[n];
	long * psum = new long[n];

	if (my_rank == 0)
		for (int x = 0; x < n; x++)
			a[x] = rand() % 8;		
 
	// DIVIDE THE PROBLEM UP
	int * locala = new int[n/p];
	long * localpsum = new long[n/p];
	long * localmin = new long[];
	int localmin = 0;
	int localmax = 0;
	
	MPI_Scatter(&a[0], n/p, MPI_INT, locala, n/p, MPI_INT, 0, MPI_COMM_WORLD);
	
	localpsum[0] = locala[0];
	for (int x = 1; x < n/p; x++){
		localpsum[x] = localpsum[x-1] + locala[x];
		if (localpsum[x] > locala[x]){
			localmax == localpsum[x]
		}
		if (locala[x] < localmin){
			localmin == localpsum[x]
		}
	}
	s
	for (int x = my_rank + 1; x < p; x++)
		MPI_Send(&localpsum[n/p-1], 1, MPI_LONG, x, tag, MPI_COMM_WORLD);
		MPI_Send(localmax, 1, MPI_LONG, x, tag, MPI_COMM_WORLD);
		MPI_Send(localmin, 1, MPI_LONG, x, tag, MPI_COMM_WORLD);
	
	long local_additive = 0;
	long temp;
	for (int x = 0; x < my_rank; x++) {
		MPI_Recv(&temp, 1, MPI_LONG, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
		local_additive += temp;
	}

	for (int x = 0; x < n/p; x++)
		localpsum[x] += local_additive;

	MPI_Gather(localpsum, n/p, MPI_LONG, psum, n/p, MPI_LONG, 0, MPI_COMM_WORLD);
	MPI_Gather(localmax, n/p, MPI_LONG, pMax, n/p, MPI_LONG, 0, MPI_COMM_WORLD);
	MPI_Gather(localmin, n/p, MPI_LONG, pMin, n/p, MPI_LONG, 0, MPI_COMM_WORLD);
	
	double pAvg = (psum[n-1])/n;
	if (my_rank == 0){
		cout << "The average is: " << pAvg << endl;
		cout << "The maximum is: " << pMax << endl;
		cout << "The minimum is: " << pMin << endl;
	}
	// Shut down MPI
	MPI_Finalize();
	
	delete [] a;
	delete [] psum;
	delete [] locala;
	delete [] localpsum;
	
	return 0;
}