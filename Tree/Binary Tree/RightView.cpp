#include "bits/stdc++.h"
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

void right_view(Node* root) {
	if(root == NULL) {
		return;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		int n = q.size();
		for(int i = 1; i<= n; i++){
			Node* cur = q.front();
			q.pop();
			if(i == n) {
				cout<< cur->data<<" ";
			}
			if(cur->left != NULL) {
				q.push(cur->left);
			}
			if(cur->right != NULL) {
				q.push(cur->right);
			}
		}
	}
}

int main(){
	
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	right_view(root);
	return 0;
}