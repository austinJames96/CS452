/* Austin Sypolt CS452 Parallel Algorithms */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mpi.h" // message passing interface
#include <fstream>
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
	char fileName[100];
	char characterCheck;
	int asciiCheck;
	int characterCounter
	int n = 1000;
	char letters[n];
	int localn = n/p;
	
	MPI_Status status;		// return status for receive
	
	cout << "Enter the name of a file to process: " << endl;
	cin << fileName << endl;
	
	
	// Start MPI
	MPI_Init(&argc, &argv);
	
	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	// Find out the number of processes!
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	// THE REAL PROGRAM IS HERE
    cout << my_rank << endl;
	
	cout << "Enter file: " << endl;
	cin << fileName << endl;
	if (my_rank == 0){
		ifstream infile(fileName);
		infile.open (fileName);
		infile>>letters;
	}
	asciiCheck = characterCheck;
	MPI_Scatter(&letters[0], localn, MPI_INT, localn, localn, MPI_INT, 0, MPI_COMM_WORLD);
	for (int x = 0; x < n; x++){
		if ((asciiCheck - (p+97)) == 0)
			characterCounter++;
	}
	
	for (int x = 0; x < p; x++){
		MPI_Allreduce(&localdot, &dotproduct, 1, MPI_LONG, MPI_SUM, MPI_COMM_WORLD);
	}
	MPI_Finalize();

	return 0;
}