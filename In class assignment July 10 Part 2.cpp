// Name : Niloy Talukder Date: 07/12/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// In class Assignment July 10: Printing stars in diamond shape


#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
    
using std::setw;

//function main begins program execution
int main()
{

   int count;

   cout<<"Enter odd number of lines:\n";//prompt
   cin>>count;
   
   for(int i = 0; i < (count/2)+1; i++) //first loop for controlling number of lines
   {

	   cout << setw((count/2) + 1 + i);

       for( int j = 0; j < i*2+1; j++) //second loop for controlling number of stars in the line
	   {
		   cout << "*";
	   }

	   cout<<endl; //to go to next line

   }

   for( int i = 0; i < (count/2); i++)
   {
	   cout << setw(count - 1 - i);

	   for( int j = 0; j < (count/2) + 1 - i*2; j++) //second loop for controlling number of stars in the line
	   {
		   cout << "*";
	   }

	   cout<<endl; //to go to next line

   }

   return 0;

} //end of main