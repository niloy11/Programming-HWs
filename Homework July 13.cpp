// Name : Niloy Talukder Date: 07/20/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// HW July 13: Matrix HW

#include<iostream>    
using std::cin;
using std::cout;
using std::endl;

#include<iomanip>
using std::setw;



void addition(double **matrix1, double **matrix2, int row, int column); //addition function definition
void subtraction(double **matrix1, double **matrix2, int row, int column); //subtraction function definition
void multiplication(double **matrix1, double **matrix2, double **matrix, int row, int column1, int column2); //multiplication function definition 
double determinant(double **matrix); //determinanat function definition
void transpose(double **matrix1, double **matrix2, int row, int column); //transpose function definition
void inverse(double **matrix, double A, double **matrix1, double **matrix2); ////inverse function definition
void inputting(double **matrix, int row, int column); //input matrix function defnition
void displaying(double **matrix, int row, int column); //output matrix function defnition

int main(){

	while(1)
	{
	int choice;

	cout<<"\nMenu:\nChoice 1 Addition\nChoice 2 Subtraction\nChoice 3 Multiplication\nChoice 4 Determinant\nChoice 5 Transpose\nChoice 6 Inverse\n\n";
	cin>>choice; //choice

	if((choice<1)||(choice>6)){
		cout<<"Invalid choice\n\n"; //outside 1-6 program terminates or keep asking for choice
       break;
	}

	int row1, column1; //variable for row & column of first matrices

	cout<<"Input number of rows and columns for first matrix:\n"; //prompt for dimension of first matrix
	cin>>row1>>column1;

	double **a = new double*[row1]; //pointer to pointer for memory allocation of 2D array

	for(int i=0; i<row1; i++)
	{
		a[i]= new double[column1];
	}

	cout<<"\n\ninput columnwise elements for first matrix:\n"; //prompt for matrix values
	inputting(a, row1, column1);

	cout<<"\n\nElements of first matrix:\n\n";
	    displaying(a, row1, column1);
    

	switch(choice)
	{

	case 1: //addition
		{
        int row2, column2;

	cout<<"\n\nInput number of rows and columns for second matrix:\n";
	cin>>row2>>column2; //prompt for second matrix dimension


	  double **b = new double*[row2]; //pointer to pointer for memory allocation of 2D array

	  for(int i=0; i<row2; i++)
	  {
		  b[i]= new double[column2];
	  }

	    cout<<"\n\ninput columnwise elements for second matrix:\n"; //prompt for second matrix values
	    inputting(b, row2, column2);

	    cout<<"\n\nElements of second matrix:\n\n";
	    displaying(b, row2, column2);

		if((row1==row2)&&(column1==column2))
		{

		addition(a, b, row1, column1);
		cout<<"\n\nElements of addition matrix:\n\n";
	    displaying(a, row1, column1);

		} 
		else cout<<"""Matrix addition not feasible\n\n";

		for(int i=0; i<column2; i++) //free memory space
	{
		delete[] b[i];
	}

	delete[] b;
		};

		continue;

    case 2: //subtraction
		{

        int row2, column2;

	cout<<"\n\nInput number of rows and columns for second matrix:\n";
	cin>>row2>>column2;


	  double **b = new double*[row2];

	  for(int i=0; i<row2; i++)
	  {
		  b[i]= new double[column2];
	  }

	    cout<<"\n\ninput columnwise elements for second matrix:\n"; //prompt for matrix values
	    inputting(b, row2, column2);

	    cout<<"\n\nElements of second matrix:\n\n";
	    displaying(b, row2, column2);

		if((row1==row2)&&(column1==column2))
		{

		subtraction(a, b, row1, column1);
		cout<<"\n\nElements of subtracted matrix:\n\n";
	    displaying(a, row1, column1);

		}
		else cout<<"""Matrix subtraction not feasible\n\n";

		for(int i=0; i<column2; i++)
	{
		delete[] b[i];
	}

	delete[] b;
	};

		continue;

	case 3: //multiplication
		{
			int row2, column2;

	cout<<"\n\nInput number of rows and columns for second matrix:\n";
	cin>>row2>>column2;


	  double **b = new double*[row2]; //pointer to pointer for memory allocation of 2D array to store second matrix

	  for(int i=0; i<row2; i++)
	  {
		  b[i]= new double[column2];
	  }

	    cout<<"\n\ninput columnwise elements for second matrix:\n"; //prompt for matrix values
	    inputting(b, row2, column2);

	    cout<<"\n\nElements of second matrix:\n\n";
	    displaying(b, row2, column2);


		if(column1==row2){
			double **c = new double*[row1]; //pointer to pointer for memory allocation of 2D array to store result

	        for(int i=0; i<row1; i++)
	        {
		       c[i]= new double[column2];
	        }

		   multiplication(a, b, c, row1, column1, column2);

		   cout<<"\n\nElements of multiplicated matrix:\n\n";
	       displaying(c, row1, column2);

		   for(int i=0; i<column2; i++)
	       {
		     delete[] c[i];
	       }

	       delete[] c;
		}
		else cout<<"\n\nMultiplication not possible\n\n";

		for(int i=0; i<column2; i++)
	{
		delete[] b[i];
	}

	delete[] b;
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
		    double **c = new double*[column1]; //pointer to pointer for memory allocation of 2D array

	        for(int i=0; i<column1; i++)
	        {
		       c[i]= new double[row1];
	        }

		   transpose(a, c, row1, column1);

		   cout<<"\n\nElements of transposed matrix:\n\n";
	       displaying(c, column1, row1);

		   for(int i=0; i<column1; i++)
	       {
		     delete[] c[i];
	       }

	       delete[] c;
		};
        continue;

	case 6: //inverse

		{
			if((row1==3)&&(column1==3))
			{
			double A;
		    A=determinant(a);
		    double **c = new double*[column1]; //pointer to pointer for memory allocation of 2D array

	        for(int i=0; i<column1; i++)
	        {
		       c[i]= new double[row1];
	        }

			double **d = new double*[column1]; //pointer to pointer for memory allocation of 2D array

	        for(int i=0; i<column1; i++)
	        {
		       d[i]= new double[row1];
	        }

		    if(determinant!=0)
		    {

			inverse(a, A, d, c);

			cout<<"\n\nElements of inverted matrix:\n\n";
	        displaying(c, row1, column1);	

		    }
		    else cout<<"Inverse matrix can not be determined";

		for(int i=0; i<column1; i++)
	       {
		     delete[] c[i];
	       }

	       delete[] c;

		   for(int i=0; i<column1; i++)
	       {
		     delete[] d[i];
	       }

	       delete[] d;
		}
			else cout<<"Inverse matrix caculation is not supported";
		};

		continue;

	default:
		cout<<"Invalid choice\n\n";
		break;
	}

	for(int i=0; i<column1; i++)
	{
		delete[] a[i];
	}

	delete[] a;
	

	}

	return 0;

}


//input matrix
void inputting(double **matrix, int row, int column)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			cin>>matrix[i][j];
		}
	}
}


//show matrix
void displaying(double **matrix, int row, int column)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			cout<<setw(10)<<matrix[i][j];

		}
		cout<<endl;
	}
}

//matrix addition
void addition(double **matrix1, double **matrix2, int row, int column)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			matrix1[i][j]+=matrix2[i][j];
		}
	}
}

//matrix subtraction
void subtraction(double **matrix1, double **matrix2, int row, int column)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			matrix1[i][j]-=matrix2[i][j];
		}
	}
}

//matrix multiplication
void multiplication(double **matrix1, double **matrix2, double **matrix3, int row, int column1,int column2)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column2; j++)
		{
			double sum=0;
			for(int k=0; k<column1; k++){
                  sum += (matrix1[i][k]*matrix2[k][j]);
			}
			matrix3[i][j]=sum;
		}
	}
}

//matrix determinant
double determinant(double **matrix)
{
	double sum=0;
    sum += matrix[0][0]*((matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1]));
	sum -= matrix[0][1]*((matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0]));
	sum += matrix[0][2]*((matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]));

	return sum;
}

//matrix transpose
void transpose(double **matrix1, double **matrix2, int row, int column)
{
    for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			matrix2[j][i]=matrix1[i][j];
		}
	}

}

//matrix inverse
void inverse(double **matrix, double A, double **matrix1, double **matrix2)
{
	double temp=0;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){

			matrix1[j][i]=matrix[i][j]; //copying swap value

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