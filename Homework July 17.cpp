// Name : Niloy Talukder Date: 07/22/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// HW July 17: HW_Book list

#include<iostream>    
using std::cin;
using std::cout;
using std::endl;

#include<iomanip>
using std::setw;

//function declaration
void print(long long int mylist[], int num_in_list);
void insert(long long int mylist[], int &num_in_list, long long int new_element, bool &sorted);
void insert_at(long long int mylist[], int at_position, int &num_in_list, long long int new_element, bool &sorted);
int find_linear(long long int mylist[], int num_in_list, long long int element);
int find_binary(long long int mylist[], int num_in_list, long long int element, bool &sorted);
void delete_item_position(long long int mylist[], int &num_in_list, int position);
void delete_item_isbn(long long int mylist[], int &num_in_list, long long int element);
void sort_list_selection(long long int mylist[], int num_in_list, bool &sorted);
void sort_list_bubble(long long int mylist[], int num_in_list, bool &sorted);


int main()
{
	bool sorted=0;
	int choice, at_position, num_in_list = 0; // variable to store choice number and also size of the book list
	const int size = 20; //maximum size of the book list

	long long int new_element, delete_element, book_list[size]; //variable to store new, delete element and array initialization for the book list
	
	cout<<"Welcome to the Booklist program\n\n";

	do{
		//choice
		cout<<"\nWhat would you like to do?\n\n";
		cout<<setw(9)<<"1.  add an element to end of list\n"
			<<setw(9)<<"2.  add an element at a location\n"
			<<setw(9)<<"3.  find an element by ISBN number (linear search)\n"
			<<setw(9)<<"4.  find an element by ISBN number (binary search)\n"
			<<setw(9)<<"5.  delete an element at position\n"
			<<setw(9)<<"6.  delete an element by ISBN number\n"
			<<setw(9)<<"7.  sort the list (using selection sort)\n"
			<<setw(9)<<"8.  sort the list (using bubble sort)\n"
			<<setw(9)<<"9.  print the list\n"
			<<setw(9)<<"0.  exit\n\n";

		cout<<"Your choice--";
		cin>>choice;

		switch(choice)
		{
		case(0): //exit
		    cout<<"\nEnd of booklist program\n\n";
			break;

		case(1): //add an element to end of list
			if(num_in_list==size) //check whether book list is full
				cout<<"Book list is full\n\n";
			else {
				//ask for new element
				cout<<"\nPlease type in the element you want to add in the list:\n";
				cin >> new_element;
				insert(book_list, num_in_list, new_element, sorted); //insert and display the list
			}
			continue;

		case(2): //add an element at a location
			if(num_in_list==size) //check whether book list is full
				cout<<"\nBook list is full\n\n";
			else {
				//ask for new element and its position
				cout<<"\nPlease type in the element you want to add:\n";
				cin >> new_element;
				cout<<"\nAt what position?\n";
				cin >> at_position;
				insert_at(book_list, at_position, num_in_list, new_element, sorted); //insert and display the list
			}
			continue;

		case(3): //find an element by ISBN number (linear search)
			//ask for element to search
			cout<<"\nPlease type in the element to find by ISBN number(linear search):\n";
			cin >> new_element;
			at_position=find_linear(book_list, num_in_list, new_element);

			//print element position
			if(at_position==-1)
				cout<<"\nElement not found in the Book list\n";
			else cout<<"\nSearching element is at position "<<at_position+1<<" in the Book list";
			
			continue;

		case(4): //find an element by ISBN number (binary search)
			if(sorted==0)
				cout<<"\nBook list is not sorted";
			else{
			    //ask for element to search
			    cout<<"\nPlease type in the element to find by ISBN number(binary search):\n";
			    cin >> new_element;
			    at_position=find_binary(book_list, num_in_list, new_element, sorted);

			    //print element position
			
			    if(at_position==-1)
				     cout<<"\nElement not found in the Book list\n";
			    else cout<<"\nSearching element is at position "<<at_position+1<<" in the Book list";
			}
			continue;

		case(5): //delete an element at position
			if (num_in_list==0) //lowest bound of list checking
		        cout<<"\nNo element in the Book list\n\n";
			else{
				//ask for element position that one to delete
				cout<<"\nAt what position you want to delete element?\n";
				cin >> at_position;

				delete_item_position(book_list, num_in_list, at_position);

				if(num_in_list==0)
					cout<<"\nNo element in the Book list\n\n";
			}
			continue;

		case(6): //delete an element by ISBN number
			if (num_in_list==0) //lowest bound of list checking
		        cout<<"\nNo element in the Book list\n\n";
			else{
				cout<<"\nPlease type in ISBN number of the element you want to delete:\n";
			    cin >> delete_element;
				delete_item_isbn(book_list, num_in_list, delete_element);

				if(num_in_list==0)
					cout<<"\nNo element in the Book list\n\n";
			}
			continue;

		case(7): //sort the list (using selection sort)
			if (num_in_list==0) //lowest bound of list checking
		        cout<<"\nNo element in the Book list\n\n";
			else sort_list_selection(book_list, num_in_list, sorted);
			continue;

		case(8): //sort the list (using bubble sort)
			if (num_in_list==0) //lowest bound of list checking
		        cout<<"\nNo element in the Book list\n\n";
			else sort_list_bubble(book_list, num_in_list, sorted);
			continue;

		case(9):
			print(book_list, num_in_list);
			continue;

		default:
			cout<<"\nInvalid choice";
			continue;

		}
		
	} while(choice!=0); //choice 0 then exit program

	return 0; //program terminated successfully

}

//print function
void print(long long int mylist[], int num_in_list)
{
	if (num_in_list==0) //lowest bound of list checking
		cout<<"\nNo element in the Book list\n\n";
	else 
		{ 
			cout<<"\nThe book list is:\n";
			for(int i=0; i<num_in_list; i++)
				cout<<setw(9)<<i+1<<".  "<<mylist[i]<<endl;

			cout<<"\n";
	}
	 	
} //end of print function

//function to add an element to end of list
void insert(long long int mylist[], int &num_in_list, long long int new_element, bool &sorted)
{

	mylist[num_in_list] = new_element; //putting element at end
	++num_in_list; //increasing list size by 1

	//print list
	cout<<"\nYour list is now:\n";
		for(int i=0; i<num_in_list; i++)
			cout<<setw(9)<<i+1<<".   "<<mylist[i]<<endl;
    cout<<"\n\n";

	if(mylist[num_in_list]>mylist[num_in_list-1]&&sorted==1)
	   sorted=1;
	else sorted=0;

} //end of insert function

//add an element at a location
void insert_at(long long int mylist[], int at_position, int &num_in_list, long long int new_element, bool &sorted)
{

	for(int i=num_in_list; i>(at_position-1); i--)
		mylist[i]=mylist[i-1];

	mylist[at_position-1] = new_element; //putting element at end
	++num_in_list; //increasing list size by 1

	//print list
	cout<<"\nYour list is now:\n";
		for(int i=0; i<num_in_list; i++)
			cout<<setw(9)<<i+1<<".   "<<mylist[i]<<endl;
    cout<<"\n\n";
	if((mylist[at_position-2]<mylist[at_position-1])&&(mylist[at_position-1]<mylist[at_position])&&sorted==1)
	   sorted=1;
	else sorted=0;

} //end of insert at location function

//find an element by ISBN number (linear search)
int find_linear(long long int mylist[], int num_in_list, long long int element)
{

	for(int j=0; j<num_in_list; j++)
	{
		if(mylist[j]==element)
			return j; //if found return location of the element
	}

	return -1; //element not found

} //end of find_linear function

//find an element by ISBN number (binary search)
int find_binary(long long int mylist[], int num_in_list, long long int element, bool &sorted)
{

		int middle, low=0, high=num_in_list-1;

		while(low<=high){
			// determine middle element of subarray being searched
			middle=(low+high)/2;

			// if search element  matches middle element, return middle
			if(element == mylist[middle])
				return middle;
			else{
				if(element<mylist[middle]) // if search element less than middle element, 
                // set new high element
					high=middle-1;
				else low=middle+1; //if element greater than middle element, 
                                  // set new low element
			}

		}
		return -1;
} // end of find binary function

//delete an element at position
void delete_item_position(long long int mylist[], int &num_in_list, int position)
{
    if(position<=num_in_list)
	{
	//shifting elements from the end towards left until delete position
	for(int i=position; i<num_in_list; i++)
		mylist[i-1]=mylist[i];

	num_in_list--; //decrease list size by 1

	//print list
	cout<<"Your list is now:\n";
		for(int i=0; i<num_in_list; i++)
			cout<<setw(9)<<i+1<<".   "<<mylist[i]<<endl;
    cout<<"\n\n";
	} else cout<<"Out of range";
	
} //end of delete_item_position function

//delete an element by ISBN number
void delete_item_isbn(long long int mylist[], int &num_in_list, long long int element)
{

	int position;

	position= find_linear(mylist, num_in_list, element); //find position

	if(position>-1)
		delete_item_position(mylist, num_in_list, position+1); //delete element
	else {
		cout<<"Item is not in the list";
		//print list
	    cout<<"Your list is now:\n";
		for(int i=0; i<num_in_list; i++)
			cout<<setw(9)<<i+1<<".   "<<mylist[i]<<endl;
        cout<<"\n\n";
	} 
	
} //end of delete_item_isbn function

//sort the list (using selection sort)
void sort_list_selection(long long int mylist[], int num_in_list, bool &sorted)
{ 
	long long int smallest, temp;

	for(int k=0; k<num_in_list; k++) // num_in_list-1 = number of passes
	{
		smallest=*(mylist+k);
		int sm_index=k;

		for(int n=k+1; n<num_in_list; n++)
		{

			if(*(mylist+n)<smallest)
			{
				smallest=*(mylist+n);
				sm_index=n;
			}

			temp=*(mylist+k);
			*(mylist+k)=*(mylist+sm_index);
			*(mylist+sm_index)=temp;
		}
	}

	sorted=1;

	//print list
	cout<<"\nYour list is now:\n";
		for(int i=0; i<num_in_list; i++)
			cout<<setw(9)<<i+1<<".   "<<*(mylist+i)<<endl;
    cout<<"\n\n";

} //end of selection sort function

//sort the list (using bubble sort)
void sort_list_bubble(long long int mylist[], int num_in_list, bool &sorted)
{
	long long int hold;
	bool flag=1;

	//loop to control no. of passes
	for(int pass=0; pass<(num_in_list-1) && flag; pass++)
	{
		flag=0;
		//loop to control no. of comparisons per pass
		for(int j=0; j<num_in_list-1; j++)
		{
			//comparison side by side element and swap them if fitrst element is greater than the second one
			if(*(mylist+j)>*(mylist+j+1))
			{
				hold=*(mylist+j);
				*(mylist+j)= *(mylist+j+1);
				*(mylist+j+1)=hold;
				flag=1; //set flag since swap occured
			}
		}
	}

	sorted=1;
	//print list
	cout<<"\nYour list is now:\n";
		for(int i=0; i<num_in_list; i++)
			cout<<setw(9)<<i+1<<".   "<<*(mylist+i)<<endl;
    cout<<"\n\n";
	
} //end of bubble_sort function