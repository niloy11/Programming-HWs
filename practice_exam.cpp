#include<iostream>
using namespace std;

int main()
{
	int *p, *q, *r, *s;
      int a, b, c, d[10];

      p = &a;
      q = &b;
     *q = 98;
      *p = 76;
        q = p;
cout <<*p << endl;
cout << *q << endl;

 r = &d[0];         //note this is the same as saying r=d, which is also valid
 for (int i =0; i < 10; i++) r[i]  = i;
 p = r;
++p;
s= p;
++s;

cout << *r << endl;
cout << *q << endl;
cout << *p <<endl;
cout << *s <<endl;

	return 0;
}