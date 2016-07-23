// Name : Niloy Talukder Date: 07/13/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// In class Assignment July 10: Printing stars in triangular shape

#include<iostream>

using namespace std;


//function main begins program execution
int main()
{

   int count;

   cout<<"Enter number of lines:\n";//prompt
   cin>>count;
   
   for(int i = 0; i < count; i++) //first loop for controlling number of lines
   {

    for(int j = 0; j < i+1; j++) //second loop for controlling number of stars in the line
	{
		cout<<"*";
	}

	cout<<endl; //to go to next line

   }

 return 0; 

} //end main