// Name : Niloy Talukder Date: 07/14/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// In class Assignment July 13: Finding out winner of poll conducted by RSC

#include<iostream>

using namespace std;
    
//function main begins program execution
int main()
{
   const int candidate= 5; //number of candidatess
   const int voter= 20; //number of voters
   int largest=0; //to find the maximum no. of votes
   int winner=0; //to find winner number

   int frequency[candidate] = {0}; //counter for candidates
   int response[voter] = {5, 1, 4, 3, 5, 3, 2, 5, 5, 2, 
	   3, 3, 3, 2, 5, 5, 4, 1, 1, 5}; //reponse array

   //counting vote for candidates using an array
   for(int i=0; i<voter; i++)
	   ++frequency[response[i]-1];

   //finding maximum no. of votes and the winner number
   for(int i=0; i<candidate; i++){

	   while(frequency[i]>largest){
		   largest=frequency[i];
		   winner=i+1;
	   }

   }

   cout<<"winner is number "<< winner <<" candidate with " << largest << " votes\n"; //printing out winner with no. of votes

   return 0; //program successfully terminated

}

