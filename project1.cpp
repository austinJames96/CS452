/* Austin Sypolt CS452 Parallel Algorithms */

#include <iostream>
#include <stdio.h>
#include <string.h>
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

	char * batonODD = message;
	char * batonEVEN = message;
	
	//sprintf(message, "Sent list: ");
	//sprintf(batonODD + strlen(batonODD), "%d ", my_rank);
	
	//sprintf(message, "Sent list: ");
	//sprintf(batonEVEN + strlen(batonEVEN), "%d ", my_rank);
	
	if (my_rank == 0) {
		MPI_Send(batonEVEN, strlen(batonEVEN) + 1, MPI_CHAR, 2, tag, MPI_COMM_WORLD);
		sprintf(batonEVEN + strlen(batonEVEN), "%d ", my_rank);
		MPI_Recv(batonEVEN, 100, MPI_CHAR, p-2, tag, MPI_COMM_WORLD, &status);
		cout << batonEVEN << endl; 
	}
	
	if (my_rank == 1){
		MPI_Send(batonODD, strlen(batonODD) + 1, MPI_CHAR, p-1, tag, MPI_COMM_WORLD);
		sprintf(batonODD + strlen(batonODD), "%d ", my_rank);
		MPI_Recv(batonODD, 100, MPI_CHAR, my_rank+2, tag, MPI_COMM_WORLD, &status);
		cout << batonODD << endl; 
	}
	
	if (((my_rank % 2) == 0) && (my_rank != 0)){
		MPI_Recv(batonEVEN, 100, MPI_CHAR, my_rank-2, tag, MPI_COMM_WORLD, &status);
		sprintf(batonEVEN + strlen(batonEVEN), "%d ", my_rank);
		cout << batonEVEN << endl;
		
		if(my_rank == (p-2)){
			MPI_Send(batonODD, strlen(batonODD) + 1, MPI_CHAR, 0, tag, MPI_COMM_WORLD);
		}
		else{
			MPI_Send(batonODD, strlen(batonODD) + 1, MPI_CHAR, my_rank+2, tag, MPI_COMM_WORLD);
		}
	}
	
	if (((my_rank % 2) == 1) && (my_rank != 1)){
		if(my_rank == (p-1)){
			MPI_Recv(batonODD, 100, MPI_CHAR, 1, tag, MPI_COMM_WORLD, &status);
		}
		else{
			MPI_Recv(batonODD, 100, MPI_CHAR, my_rank+2, tag, MPI_COMM_WORLD, &status);
		}
		sprintf(batonODD + strlen(batonODD), "%d ", my_rank);
		cout << batonODD << endl; 
		MPI_Send(batonODD, strlen(batonODD) + 1, MPI_CHAR, my_rank-2, tag, MPI_COMM_WORLD);
	}
	
	// Shut down MPI
	MPI_Finalize();

return 0;
}

