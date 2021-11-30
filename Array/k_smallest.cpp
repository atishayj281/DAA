#include "bits/stdc++.h"
using namespace std;
int main(){
	int a[] = {7, 10, 4, 3, 20, 50};
	priority_queue<int, vector<int>, greater<int>> q;

	for(int i = 0; i<6; i++){
		q.push(a[i]);
	}

	int k = 3;
	for(int i = 0; i<k-1; i++){
		q.pop();
	}
	cout<<q.top();
	return 0;
}