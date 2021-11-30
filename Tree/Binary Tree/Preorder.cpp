#include "bits/stdc++.h"
#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *left = NULL;
	Node *right = NULL;
	Node(int d)
	{
		data = d;
	}
};

vector<int> v;

vector<int> preOrder(Node *root)
{
	if (root == NULL)
		return v;
	v.push_back(root->data);
	preOrder(root->left);
	preOrder(root->right);

	return v;
}
/*
	1
      /  \
     2    3
    / \  / \
   4   5 6 7
*/
int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	vector<int> a = preOrder(root);
	for(int item: a){
		cout<<item<<" ";
	}
	
	return 0;
}