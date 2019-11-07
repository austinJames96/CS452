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
	char letters[1000];
	MPI_Status status;		// return status for receive
	
	cout << "Enter the name of a file to process: " << endl;
	cin << fileName << endl;
	
	/*string STRING;
	ifstream infile;
	infile.open (fileName);
        while(!infile.eof) 
        {
	        getline(infile,STRING); 
	        cout<<STRING; 
	infile.close();
	*/
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
	
	for (int x = 0; x < 1000; x++){
		cout << letters[x] << endl;
	}
	//asciiCheck = characterCheck;
	
	
	/*
	for (int x = 0; x < p; x++){
		infile.open (fileName);
		while(!infile.eof) 
		getline(infile,STRING);
			/*	
				if (asciiCheck == 97)
					letters[0]++;
				if (asciiCheck == 98)
					letters[0]++;
				if (asciiCheck == 99)
					letters[0]++;
				if (asciiCheck == 100)
					letters[0]++;
				if (asciiCheck == 101)
					letters[0]++;
				if (asciiCheck == 102)
					letters[0]++;
				if (asciiCheck == 103)
					letters[0]++;
				if (asciiCheck == 104)
					letters[0]++;
				if (asciiCheck == 105)
					letters[0]++;
				if (asciiCheck == 106)
					letters[0]++;
				if (asciiCheck == 107)
					letters[0]++;
				if (asciiCheck == 108)
					letters[0]++;
				if (asciiCheck == 109)
					letters[0]++;
				if (asciiCheck == 110)
					letters[0]++;
				if (asciiCheck == 111)
					letters[0]++;
				if (asciiCheck == 112)
					letters[0]++;
				if (asciiCheck == 113)
					letters[0]++;
				if (asciiCheck == 114)
					letters[0]++;
				if (asciiCheck == 115)
					letters[0]++;
				if (asciiCheck == 116)
					letters[0]++;
				if (asciiCheck == 117)
					letters[0]++;
				if (asciiCheck == 118)
					characterCountV++;
				if (asciiCheck == 119)
					characterCountW++;
				if (asciiCheck == 120)
					characterCountX++;
				if (asciiCheck == 121)
					characterCountY++;
				if (asciiCheck == 122)
					characterCountZ++;
			}
		}
	}
	
	if (my_rank == 0){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 97)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " a letters" << endl;
	        
        }
	infile.close();
	}

	if (my_rank == 1){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 98)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " b letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 2){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 99)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " c letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 3){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 100)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " d letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 4){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 101)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " e letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 5){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 102)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " f letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 6){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 103)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " g letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 7){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 104)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " h letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 8){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 105)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " i letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 9){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 106)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " j letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 10){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 107)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " k letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 11){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 108)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " l letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 12){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 109)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " m letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 13){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 110)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " n letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 14){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 111)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " o letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 15){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 112)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " p letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 16){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 113)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " q letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 17){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 114)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " r letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 18){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 115)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " s letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 19){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 116)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " t letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 20){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 117)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " u letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 21){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 118)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " v letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 22){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 119)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " w letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 23){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 120)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " x letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 24){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 121)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " y letters" << endl;
	        
        }
	infile.close();
	}
	
	if (my_rank == 25){
		infile.open (fileName);
        while(!infile.eof)  
        {
			getline(infile,STRING);
			if (asciiCheck == 122)
			{
				characterCount++;
			}
	        cout << "There are: " << characterCount << " z letters" << endl;
	        
        }
	infile.close();
	}
	*/
	// Shut down MPI
	MPI_Finalize();

	return 0;
}