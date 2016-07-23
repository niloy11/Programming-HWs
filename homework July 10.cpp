//Name:Niloy Talukder Date:7/17/15
//Course : 16:332:503 , PM for Financial Applications and Numerical Computing.
//Monte Carlo simulation

#include<iostream> //cin,cout
#include<fstream> //file processing
#include<stdlib.h> //srand, rand, RAND_MAX
#include<time.h> //time

using namespace std;

//function main begins program execution
int main()
{  

	int x;
	cout<<"Number of iteration:\n";
	cin>>x;

	double max=RAND_MAX;
	ofstream file;

	//opens the file MonteCarlo.txt
	file.open("MonteCarlo.txt");
	//initialize random seed
	srand(time(0));

	//for loop to write random values to the file
	for(int i=0; i<x; i++)
	{

		file<<rand()/max<<","<<rand()/max<<"\n";

	}

	cout<<"Numbers printed to MonteCarlo.txt file"<<endl;

	return 0; //successful program termination

} //end of main