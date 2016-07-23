#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
#include<stdlib.h>
#include <array>

using namespace std;

void read_file(string, vector <int> &);
void write_file(vector <int> &, int &);
void printVector(vector <int>);
void bottomupsort(vector<int> &a, int &count);
void merge(vector<int> &, int &, int, int, int);

int main(int argc, char *argv[])
{
  int count=0;

  string text_file=argv[1];

  vector <int> vector_contents;
  read_file(text_file, vector_contents); //reading contents from text file in a vector

  printVector(vector_contents); //printing vector elements


  // calling bottom up merge sort
  bottomupsort(vector_contents, count);
  write_file(vector_contents, count); //writing in a text file
 
  return 0;
}

//reading contents from text file in a vector
void read_file(string text_file, vector <int> & matrix){
	ifstream readFile(text_file);
	string token;
	while (readFile >> token)
		matrix.push_back(stoi(token));
}

void write_file(vector <int> & matrix,int &count){
	ofstream writefile("output_q1b.txt");
	if(writefile.is_open())
	{
	  writefile << "comparisons of bottom up mergesort: "<< count << endl<<endl;
          writefile << "Ordered data:"<< endl;
          for(int i=0; i<matrix.size(); i++)
          {
	    writefile << matrix[i] <<endl;
          }
	   
	  writefile.close();
	}
		
}

//printing vector elements
void printVector(vector <int> matrix){
	for (int i = 0; i < matrix.size(); i++)
		cout << matrix[i] << endl; // Change to this if want to display horizontally cout << matrix[i] << " ";
	cout << endl;
}

// bottom up merge sort
void bottomupsort(vector<int> &a, int &count){
    int Num= a.size();
    for (int sz = 1; sz < Num; sz += sz)
    {
	for (int lo = 0; lo < Num - sz; lo += 2 * sz)
	{
	   if (lo + 2 * sz - 1>Num - 1)
		merge(a, count, lo, lo + sz - 1, Num - 1);
	   else
		merge(a, count, lo, lo + sz - 1, lo + 2 * sz - 1);
	}
    }
}

// merge function
void merge(vector<int> &array, int &count, int lo, int mid, int hi){

    vector <int> temp;
    temp.resize((hi+1), 0);

    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
    {
      temp[k] = array[k];
    }
    for (int k = lo; k <= hi; k++)
    {
      if (i>mid) array[k] = temp[j++];
      else if (j > hi) array[k] = temp[i++];
      else
      {
         count++;
         if (temp[i] <= temp[j])
         {
           array[k] = temp[i++];					
         }
         else
         {
           array[k] = temp[j++];
         }
      }
    }
 } 
