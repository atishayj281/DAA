#include <iostream>
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

int get_height(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int lh = get_height(root->left);
	int rh = get_height(root->right);
	return (max(lh, rh) + 1);
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