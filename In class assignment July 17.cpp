#include<iostream>    
using namespace std;

//function declaration
long fibonacci(int n); 
int binarysearch(const int b[], int key, int high);

int main()
{

   int x, number,index; //variable for totalno of elements in fibonacci series, searching number in series and the index for it
   cout<<"How many fibonacci numbers to print?:\n\n"; //ask for total number in series
   cin>>x;

   int *array = new int[x]; //allocating memory for array of given size

   //initializing first two number in fibonacci series
   *array=0; 
   *(array+1)=1;

   //putting fibonacci numbers in the array
   for(int i=0; i<x-2; i++)
   {
	   *(array+i+2)=fibonacci(i)+fibonacci(i+1);
   }

   //printing fibonacci series
   cout<<"\nThe fibonacci series until "<<x<<" is:\n\n"; 

   for(int i=0; i<x; i++)
   {
	   cout<<*(array+i)<<"  ";
   }

   cout<<"\n\n";

   //do while loop for iterative search of any number in the series
   do{

      cout<<"Please enter the number you wish to search for:  "; //prompt for number
      cin>>number;
      index=binarysearch(array, number, x); //call binary search function to search number

	  //checking whether number is in series or not and print index number
      if(index==-1)
	       cout<<"\n\nnumber "<<number<<" not found\n\n";
      else cout<<"\n\nIndex for searching number "<<number<<" is "<<index<<"\n\n";

   } while(number!=-1); //if searching number -1 then program termination
   
   //release memory location
    delete[] array;

    return 0; //successful program termination

}


//fibonacci function
long fibonacci(int n)
{
	//intializing first two elements of the series
	if (n==0) return 0;
	else if (n==1) return 1;
	else return fibonacci(n-1)+fibonacci(n-2); //recursive call
}

//binary search function
int binarysearch(const int b[], int key, int high)
{
	int middle; //variable for middle index after each search
	int low=0; //lowest index is 0
	while(low<=high)
	{
		middle = (low+high)/2;

		if (key==b[middle]) return middle; //checking middle index value with searching number
		else if(key<b[middle]) //number less than middle number take lower half for next search and vice versa
			high=middle-1;
		     else low=middle+1;       
	}

	return -1; //number not found
}
