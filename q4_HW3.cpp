#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

//code source:http://www.cplusplus.com/forum/general/1551/

using namespace std;

class BinarySearchTree
{
    private:
        struct node
        {
           node* left;
           node* right;
           int key;
	   int size;
        };
        node* root;
    
    public:
        BinarySearchTree(){
           root = NULL;
        }
       
        bool isEmpty() const { return root==NULL; }
        void insert(int);
        void remove(int);
	
		
	int count(node* );
	int rank(int );
	int rank(int , node*);
	int select(int );
	int select(int, node*); 
};

int BinarySearchTree::count ( node* root )
{
    if ( root == NULL ) return 0;
    root->size = count(root->left) + count(root->right) + 1;
	return root->size;
}

void BinarySearchTree::insert(int d)
{
    node* temp = new node;
    node* parent;
    temp->key = d;
    temp->left = NULL;
    temp->right = NULL;
    parent = NULL;
    
    if(isEmpty()) root = temp;
    else{
        node* current;
        current = root;
        while(current){
            parent = current;
            if(temp->key >= current->key) 
				current = current->right;
            else current = current->left;
        }

		if (temp->key != parent->key){
			if(temp->key < parent->key)
			   parent->left = temp;
			else
			   parent->right = temp;
			}
    }
}

int BinarySearchTree::select(int rank){
	
	count(root);
	if(rank<0) return NULL;
	if(rank >= root->size) return NULL;
	int key = select(rank, root);
	return key;
}

int BinarySearchTree::select(int rank,node* x){
	if(x == NULL) return NULL;
	int t=0;

	if(x->left==NULL) t=0;
	else t = x->left->size;
	
	if (t == rank) 
		return x->key;
	else if (t > rank)
		return select(rank, x->left);
	else if (t < rank)
		return select(rank-t-1, x->right);
}

int BinarySearchTree::rank(int key){
	count(root);
	return rank(key, root);
}

int BinarySearchTree::rank(int key, node* z)
{
	if(x==NULL) return 0;
	
	if(key == z->key) {
		if(z->left == NULL) return 0;
		else return z->left->size;
	}
	else if(key < z->key) {
		if(z->left == NULL) return 0;
		else return rank(key, z->left);
	}
	else if(key > z->key) {
		return 1 + z->left->size + rank(key, z->right);
	}
}



int main(int argc, char *argv[])

{
  
	BinarySearchTree BST;

  
	string text_file=argv[1];

  
	ifstream readFile(text_file);
	
	string token;
	
	while (readFile >> token)
		BST.insert(stoi(token));
 
	ofstream writefile("output_q4.txt");
	
	if(writefile.is_open())
	{
	  
		writefile<<"\nValue of select 7 is: "<<BST.select(7)<<endl;
		writefile<<"Value of rank 7 is: "<<BST.rank(7)<<endl;
	        }        
	writefile.close();
		

	return 0;

}
