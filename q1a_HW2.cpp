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
void topdownsort(vector<int> &, int &, int, int);
void merge(vector<int> &, int &, int, int, int);

int main(int argc, char *argv[])
{
  int count=0;

  string text_file=argv[1];

  vector <int> vector_contents;
  read_file(text_file, vector_contents); //reading contents from text file in a vector

  printVector(vector_contents); //printing vector elements


  // calling top down merge sort
  topdownsort(vector_contents, count, 0, vector_contents.size()-1);
 
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
	ofstream writefile("output_q1a.txt");
	if(writefile.is_open())
	{
	  writefile << "comparisons of top-down mergesort: "<< count << endl << endl;
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

// top down merge sort
void topdownsort(vector<int> &a, int &count, int lo, int hi){
    if (hi <= lo) return;
    int mid = lo + (hi-lo) / 2;
    topdownsort(a, count, lo, mid);
    topdownsort(a, count, mid + 1, hi);
    merge(a, count, lo, mid, hi);
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



