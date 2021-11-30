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

void levelOrder(Node *root)
{
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		Node *cur = q.front();
		q.pop();
		cout << cur->data << " ";
		if (cur->left != NULL)
		{
			q.push(cur->left);
		}
		if (cur->right != NULL)
		{
			q.push(cur->right);
		}
	}
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
	return 0;
}