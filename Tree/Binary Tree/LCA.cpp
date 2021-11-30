#include "bits/stdc++.h"
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

/*
	1
      /  \
     2    3
    / \  / \
   4   5 6 7
*/

bool getPath(Node *root, int key, vector<int> &path)
{
	if (root == NULL)
	{
		return false;
	}

	path.push_back(root->data);
	if (root->data == key)
	{
		return true;
	}
	if (getPath(root->left, key, path) || getPath(root->right, key, path))
	{
		return true;
	}
	path.pop_back();
	return false;
}

int get_Anscestor(Node *root, int n1, int n2)
{
	vector<int> path1, path2;
	if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
	{
		return -1;
	}
	int pc;
	for (pc = 0; pc < path1.size() && pc < path2.size(); pc++)
	{
		if (path1[pc] != path2[pc])
		{
			break;
		}
	}
	return path1[pc - 1];
}

Node *lca(Node *root, int n2, int n1)
{
	// Write your code here.
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == n1 || root->data == n2)
	{
		return root;
	}
	Node *leftLCA = lca(root->left, n2, n1);
	Node *rightLCA = lca(root->right, n2, n1);

	if (leftLCA != NULL && rightLCA != NULL)
	{
		return root;
	}

	if (leftLCA != NULL)
	{
		return leftLCA;
	}
	return rightLCA;
}

int main()
{

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	int n1 = 7, n2 = 6;
	Node* l = lca(root, n1, n2);
	if(l == NULL){
		cout<<"Lca doesn't exist"<<endl;
	}
	else{
		cout<<l->data<<endl;
	}
	return 0;
}