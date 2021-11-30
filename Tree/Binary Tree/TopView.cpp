#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

void topView(Node* root) {
	
}


int main(){
	
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	return 0;
}