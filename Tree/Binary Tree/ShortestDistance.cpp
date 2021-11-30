#include "bits/stdc++.h"
using namespace std;

class Node{
	public:
	int data;
	Node* left,* right;
	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* lca(Node* root, int n1, int n2){
	if(root == NULL){
		return NULL;
	}
	if(root->data == n1 || root->data == n2){
		return root;
	}

	Node* leftLCA = lca(root->left, n1, n2);
	Node* rightLCA = lca(root->right, n1, n2);
	if(leftLCA != NULL && rightLCA != NULL){
		return root;
	}
	if(leftLCA == NULL){
		return rightLCA;
	}
	return leftLCA;
}

int distance(Node* root, int n, int dist){
	if(root == NULL){
		return -1;
	}
	if(root->data == n) return dist;
	int left = distance(root->left, n, dist+1);
	if(left != -1) return left;
	return distance(root->right, n, dist+1);
}

int get_shortest_distance(Node* root, int n1, int n2){
	Node* LCA = lca(root, n1, n2);

	if(LCA == NULL){
		cout<<"Invalid Nodes..."<<endl;
		return -1;
	}
	int d1 = distance(LCA, n1, 0);
	int d2 = distance(LCA, n2, 0);
	return d1+d2;
}

int main(){
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	int n1, n2;
	cout<<"Enter the two nodes: ";
	cin>>n1>>n2;
	cout<<"Shortest Distance: "<<get_shortest_distance(root, n1, n2);
	return 0;
}