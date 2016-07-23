// Name : Niloy Talukder Date: 07/20/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// HW July 13: Matrix HW_Vector

#include<iostream>    
using std::cin;
using std::cout;
using std::endl;

#include<iomanip>
using std::setw;

#include<vector>
using std::vector;

void outputVector(const vector<vector<double>> & g); //to show matrix element function definition
void inputVector(vector<vector<double>> & g); //input matrix element function definition
void addition(vector<vector<double>> & matrix1, vector<vector<double>> & matrix2);//matrix addition function definition
void subtraction(vector<vector<double>> & matrix1, vector<vector<double>> & matrix2);//matrix subtraction function definition
void multiplication(vector<vector<double>> & matrix1, vector<vector<double>> & matrix2, vector<vector<double>> & matrix); //matrix multiplication function definition
double determinant(vector<vector<double>> & matrix);//matrix determinant function definition
void transpose(vector<vector<double>> & matrix1, vector<vector<double>> & matrix2);//matrix transpose function definition
void inverse(vector<vector<double>> & matrix, double A, vector<vector<double>> & matrix1, vector<vector<double>> & matrix2);//matrix inverse function definition



int main()
{
    while(1)
	{
	int choice;

	cout<<"\nMenu:\nChoice 1 Addition\nChoice 2 Subtraction\nChoice 3 Multiplication\nChoice 4 Determinant\nChoice 5 Transpose\nChoice 6 Inverse\n\n";
	cin>>choice;

	if((choice<1)||(choice>6)){
		cout<<"Invalid choice\n\n";
       break;
	}

	int row1, column1; //variable for row & column of two matrices

	cout<<"Input number of rows and columns for first matrix:\n"; //prompt for dimension of first matrix
	cin>>row1>>column1;

	std::vector<std::vector<double>> a(row1, std::vector<double>(column1));

	cout<<"\n\ninput columnwise elements for first matrix:\n"; //prompt for matrix values
	inputVector(a);

	cout<<"\n\nElements of first matrix:\n\n";
	outputVector(a);

	switch(choice)
	{

	case 1: //addition
		{
        int row2, column2; //for second matrix

	    cout<<"\n\nInput number of rows and columns for second matrix:\n";
	    cin>>row2>>column2;


	    std::vector<std::vector<double>> b(row2, std::vector<double>(column2)); //create vector space for second matrix

	    cout<<"\n\ninput columnwise elements for second matrix:\n"; //prompt for matrix values
	    inputVector(b);

	    cout<<"\n\nElements of second matrix:\n\n";
	    outputVector(b); //show matrix

		if((row1==row2)&&(column1==column2)) //dimension check
		{

		addition(a, b);
		cout<<"\n\nElements of addition matrix:\n\n";
	    outputVector(a);

		} 
		else cout<<"""Matrix addition not feasible\n\n";

		};

		continue;

    case 2: //subtraction
		{

        int row2, column2; //for second matrix

	    cout<<"\n\nInput number of rows and columns for second matrix:\n";
	    cin>>row2>>column2;


	    std::vector<std::vector<double>> b(row2, std::vector<double>(column2)); //create vector space for second matrix

	    cout<<"\n\ninput columnwise elements for second matrix:\n"; //prompt for matrix values
	    inputVector(b);

	    cout<<"\n\nElements of second matrix:\n\n";
	    outputVector(b); //show matrix

		if((row1==row2)&&(column1==column2))
		{

		subtraction(a, b);
		cout<<"\n\nElements of subtracted matrix:\n\n";
	    outputVector(a); //show result

		}
		else cout<<"""Matrix subtraction not feasible\n\n";
	};

		continue;

	case 3: //multiplication
		{
			int row2, column2; //for second matrix

	    cout<<"\n\nInput number of rows and columns for second matrix:\n";
	    cin>>row2>>column2;


	    std::vector<std::vector<double>> b(row2, std::vector<double>(column2)); //create vector space for second matrix

	    cout<<"\n\ninput columnwise elements for second matrix:\n"; //prompt for matrix values
	    inputVector(b);

	    cout<<"\n\nElements of second matrix:\n\n";
	    outputVector(b); //show matrix

		if(column1==row2){

			std::vector<std::vector<double>> c(row1, std::vector<double>(column2)); //create vector space for resultant matrix

		   multiplication(a, b, c);

		   cout<<"\n\nElements of multiplicated matrix:\n\n";
	       outputVector(c); //show result

		}
		else cout<<"\n\nMultiplication not possible\n\n";
	};

		continue;

		case 4: //determinant
		if((row1==3)&&(column1==3))
		{
			double A1;
			A1=determinant(a);
			cout<<"Determinant is: "<<A1<<endl;
		}
		else cout<<"Determinant caculation is not supported";
	    continue;

	case 5: //transpose
		{
		   std::vector<std::vector<double>> c(column1, std::vector<double>(row1)); //create vector space for resultant matrix

		   transpose(a, c);

		   cout<<"\n\nElements of transposed matrix:\n\n";
	       outputVector(c);

		};
        continue;

	case 6: //inverse

		{
			if((row1==3)&&(column1==3))
			{
			double A;
		    A=determinant(a);

		    std::vector<std::vector<double>> c(row1, std::vector<double>(column1)); //create vector space for resultant matrix

			std::vector<std::vector<double>> d(row1, std::vector<double>(column1)); //create vector space for swap matrix

		    if(determinant!=0)
		    {

			inverse(a, A, d, c);

			cout<<"\n\nElements of inverted matrix:\n\n";
	        outputVector(c);

		    }
		    else cout<<"Inverse matrix can not be determined";

		
		}
			else cout<<"Inverse matrix caculation is not supported";
		};

		continue;

	default:
		cout<<"Invalid choice\n\n";
		break;
	}

	}

	return 0;

}

//to show matrix element
void outputVector(const vector<vector<double>> & g)
{
	for (size_t i=0; i<g.size(); i++)
  {
    for (size_t j=0; j<g[i].size(); j++)
    {
      cout << setw(10) << g[i][j];
    }
    cout << endl;
  }

}

//input matrix element
void inputVector(vector<vector<double>> & g)
{

	for (size_t i=0; i<g.size(); i++)
  {
    for (size_t j=0; j<g[i].size(); j++)
    {
      cin >> g[i][j];
    }
  }

}

//matrix addition function
void addition(vector<vector<double>> & matrix1, vector<vector<double>> & matrix2)
{
	
	for (size_t i=0; i<matrix1.size(); i++)
  {
    for (size_t j=0; j<matrix1[i].size(); j++)
    {
      matrix1[i][j]+=matrix2[i][j];
    }
  }
}

//matrix subtraction function
void subtraction(vector<vector<double>> & matrix1, vector<vector<double>> & matrix2)
{
	
	for (size_t i=0; i<matrix1.size(); i++)
  {
    for (size_t j=0; j<matrix1[i].size(); j++)
    {
      matrix1[i][j]-=matrix2[i][j];
    }
  }
}

//matrix multiplication function
void multiplication(vector<vector<double>> & matrix1, vector<vector<double>> & matrix2, vector<vector<double>> & matrix)
{
	for (size_t i=0; i<matrix1.size(); i++)
  {
    for (size_t j=0; j<matrix2[i].size(); j++)
    {
			double sum=0;
			for(int k=0; k<matrix1[i].size(); k++){
                  sum += (matrix1[i][k]*matrix2[k][j]);
			}
			matrix[i][j]=sum;
		}
	}
}

//matrix determinant function
double determinant(vector<vector<double>> & matrix)
{
	double sum=0;
    sum += matrix[0][0]*((matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1]));
	sum -= matrix[0][1]*((matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0]));
	sum += matrix[0][2]*((matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]));

	return sum;

}

//matrix transpose function
void transpose(vector<vector<double>> & matrix1, vector<vector<double>> & matrix2)
{
    
	for (size_t i=0; i<matrix1.size(); i++)
  {
    for (size_t j=0; j<matrix1[i].size(); j++)
    {
      matrix2[j][i]=matrix1[i][j];
    }
  }

}


//matrix inverse function
void inverse(vector<vector<double>> & matrix, double A, vector<vector<double>> & matrix1, vector<vector<double>> & matrix2)
{
   for (size_t i=0; i<3; i++)
  {
    for (size_t j=0; j<3; j++)
    {
      matrix1[j][i]=matrix[i][j];//transpose
    }
  }

   matrix2[0][0]=(matrix1[1][1]*matrix1[2][2]-matrix1[1][2]*matrix1[2][1])/A;
	matrix2[0][1]=-(matrix1[1][0]*matrix1[2][2]-matrix1[1][2]*matrix1[2][0])/A;
	matrix2[0][2]=(matrix1[1][0]*matrix1[2][1]-matrix1[1][1]*matrix1[2][0])/A;
	matrix2[1][0]=-(matrix1[0][1]*matrix1[2][2]-matrix1[0][2]*matrix1[2][1])/A;
	matrix2[1][1]=(matrix1[0][0]*matrix1[2][2]-matrix1[0][2]*matrix1[2][0])/A;
	matrix2[1][2]=-(matrix1[0][0]*matrix1[2][1]-matrix1[0][1]*matrix1[2][0])/A;
	matrix2[2][0]=(matrix1[0][1]*matrix1[1][2]-matrix1[0][2]*matrix1[1][1])/A;
	matrix2[2][1]=-(matrix1[0][0]*matrix1[1][2]-matrix1[0][2]*matrix1[1][0])/A;
	matrix2[2][2]=(matrix1[0][0]*matrix1[1][1]-matrix1[0][1]*matrix1[1][0])/A;

}
