#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

long int distance(vector<int>, vector<int>);
void read_file(string, vector <int> &);
long int getInvCount(int arr[], int n);
void write_file(int &count);

int main(int argc, char *argv[])
{
        string text_file1=argv[1];
        string text_file2=argv[2];
	
	vector <int> vector_contents1;
	vector <int> vector_contents2;
        read_file(text_file1, vector_contents1); //reading contents from text file in a vector
	read_file(text_file2, vector_contents2); //reading contents from text file in a vector

        int inv=distance(vector_contents1,vector_contents2);
	cout<<inv<<endl;
	write_file(inv);

	return 0;
 }

//source: http://algs4.cs.princeton.edu/25applications/KendallTau.java.html
// return Kendall tau distance between two permutations
long int distance(vector<int> a, vector<int> b) {
        int N1 = a.size();
	int N2 = b.size();
	if(N1!=N2)
	{
	  cout<<"Permutations are not of same size"<<endl;
	  return 0;
	}

        int ainv[N1];
        for (int i = 0; i < N1; i++)
            ainv[a[i]] = i;

        int bnew[N1];
        for (int i = 0; i < N1; i++)
            bnew[i] = ainv[b[i]];

        return getInvCount(bnew,N1);
    }

//reading contents from text file in a vector
void read_file(string text_file, vector <int> & matrix){
	ifstream readFile(text_file);
	string token;
	while (readFile >> token)
		matrix.push_back(stoi(token));
}

//giving count of inversions
long int getInvCount(int arr[], int n)
{
  int inv_count = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i+1; j < n; j++)
      if (arr[i] > arr[j])
        inv_count++;
 
  return inv_count;
}

void write_file(int &count){
	ofstream writefile("output_q3.txt");
	if(writefile.is_open())
	{
	  writefile << "inversions = "<< count << endl;
	  writefile.close();
	}
		
}
