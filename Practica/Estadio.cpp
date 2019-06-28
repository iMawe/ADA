#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct node{
  string key_value;
  node *left;
  node *right;
};

class btree{
public:
    btree(){
		root = NULL;
	}
    ~btree();
    void insert(string key){
		if(key < leaf->key_value){
			if(leaf->left!=NULL) insert(key, leaf->left);
			else{
				leaf->left=new node;
				leaf->left->key_value=key;
				leaf->left->left=NULL;    //Sets the left child of the child node to null
				leaf->left->right=NULL;   //Sets the right child of the child node to null
			}  
		}
		else if(key>=leaf->key_value){
			if(leaf->right!=NULL) insert(key, leaf->right);
			else{
			  leaf->right=new node;
			  leaf->right->key_value=key;
			  leaf->right->left=NULL;  //Sets the left child of the child node to null
			  leaf->right->right=NULL; //Sets the right child of the child node to null
			}
		}
	}

private:
    void insert(string key, node *leaf){
		if(root!=NULL) insert(key, root);
		else{
			root=new node;
			root->key_value=key;
			root->left=NULL;
			root->right=NULL;
		}
	}

    node *root;
};

int main(){
	btree *tree = new btree();

	return 0;
}