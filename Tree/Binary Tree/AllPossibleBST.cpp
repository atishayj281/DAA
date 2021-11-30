#include "bits/stdc++.h"
using namespace std;

struct Node{
	int data;
	Node* left, *right;
	Node(int val){
		data = val;
		right = NULL;
		left = NULL;
	}
};

vector<Node*> possibleBST(int start, int end){
	vector<Node*> trees;
	if(start > end){
		trees.push_back(NULL);
		return trees;
	}
	for(int i = start; i<=end; i++){
		vector<Node*> leftSubtrees = possibleBST(start, i-1);
		vector<Node*> rightSubtrees = possibleBST(i+1, end);

		for(int j = 0; j<leftSubtrees.size(); j++){
			Node* left = leftSubtrees[j];
			for(int k = 0; k<rightSubtrees.size(); k++){
				Node* right = rightSubtrees[k];
				Node* root = new Node(i);
				root->left = left;
				root->right = right;
				trees.push_back(root);
			}
		}
	}
	return trees;
}

void preorder(Node* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	vector<Node*> roots = possibleBST(1, 3);
	for(int i = 0; i<3; i++){
		preorder(roots[i]);
		cout<<endl;
	}
	return 0;
}