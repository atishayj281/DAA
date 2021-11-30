#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left = NULL;
	Node* right = NULL;
	Node(int d){
		data = d;
	}
};

/*
	1
      /  \
     2    3
    / \  / \
   4   5 6 7
*/

void replaceSum(Node* root){
	if(root == NULL) {
		return;
	}
	replaceSum(root->left);
	replaceSum(root->right);
	if(root->left != NULL) {
		root->data += root->left->data;
	}
	if(root->right != NULL) {
		root->data += root->right->data;
	}
}

void preOrder(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	preOrder(root);
	cout<<endl;
	replaceSum(root);
	preOrder(root);
	return 0;
}