#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

void read_file(string, vector <int> &);
void write_file(vector <int> &, int &, int &);

void shellsort(vector<int> &, int &);
void insertionsort(vector<int> &, int &);

int main(int argc, char *argv[])
{
  int count=0, count2=0;

  string text_file=argv[1];

  vector <int> vector_contents;
  read_file(text_file, vector_contents); //reading contents from text file in a vector

  //printVector(vector_contents); //printing vector elements

	
  shellsort(vector_contents, count);
  insertionsort(vector_contents, count2);
  
  write_file(vector_contents, count, count2); //writing in a text file
	
  return 0;

}

void shellsort(vector<int> & a, int &count)
{
	int N = a.size();
	int y=1;
	bool com;
	//int count = 0;
	int h = 1;
	while (pow(2, y) - 1 < N)
	{
		h = int(pow(2, y)) - 1;
		++y;
	}
	--y;
	while (h > 1)
	{
		for (int i = h; i < N; i++)
		{
			com = 1;
			for (int j = i; j >= h&&com==1; j -= h)
			{
				count++;
				if (a[j] >= a[j - h]) com=0;
				else swap(a[j], a[j - h]);
			}
		}
		--y;
		h = int(pow(2, y)) - 1;
	}
	//cout << "comparisons of shellsort: "<<count << endl;
}

void insertionsort(vector<int> & a, int &count2)
{
	bool com = 1;
	//int count2 = 0;
	int N = a.size();
	for (int i = 1; i < N; i++)
	{
		com = 1;
		for (int j = i; j > 0 && com == 1; j--)
		{
			count2++;
			if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
			else com = 0;
		}
	}
	//cout << "comparisons of insertion sort: " << count2 << endl;
}

//reading contents from text file in a vector
void read_file(string text_file, vector <int> & matrix){
	ifstream readFile(text_file);
	string token;
	while (readFile >> token)
		matrix.push_back(stoi(token));
}

void write_file(vector <int> & matrix,int &count, int &count2){
	ofstream writefile("output_q2.txt");
	if(writefile.is_open())
	{
	  writefile << "comparisons of shellsort phase: "<< count << endl;
	  writefile << "comparisons of insertion sort phase: "<< count2 << endl;
          writefile << "Ordered data:"<< endl;
          for(int i=0; i<matrix.size(); i++)
          {
	    writefile << matrix[i] <<endl;
          }
	   
	  writefile.close();
	}
		
}
