#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

void insertionsort(vector<int> &, int &);
void write_file(vector <int> &,int &);


int main()
{
  int count=0;
  vector <int> vector_contents;
  for(int i=0; i<8192; i++)
  {
     if(i<1024)
       vector_contents.push_back(1);
     if(i>1023 && i<3072)
       vector_contents.push_back(11);
     if(i>3071 && i<7168)
       vector_contents.push_back(111);
     if(i>7167 && i<8192)
       vector_contents.push_back(1111);
  }
  
  insertionsort(vector_contents, count);

  write_file(vector_contents, count); //writing in a text file 

  return 0;
}

void insertionsort(vector<int> & a, int &count)
{
	bool com = 1;
	int N = a.size();
	for (int i = 1; i < N; i++)
	{
		com = 1;
		for (int j = i; j > 0 && com == 1; j--)
		{
			count++;
			if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
			else com = 0;
		}
	}
}

void write_file(vector <int> & matrix,int &count){
	ofstream writefile("output_q4.txt");
	if(writefile.is_open())
	{
	  writefile << "comparisons of insertion sort: "<< count << endl << endl;
          writefile << "Ordered data:"<< endl;
          for(int i=0; i<matrix.size(); i++)
          {
	    writefile << matrix[i] <<endl;
          }
	   
	  writefile.close();
	}
		
}
