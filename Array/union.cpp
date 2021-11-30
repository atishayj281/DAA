#include "bits/stdc++.h"
using namespace std;

int unioArray(int a[], int n, int b[], int m) {
	set<int> ans;
	for(int i = 0; i<n; i++){
		ans.insert(a[i]);
	}
	for(int i = 0; i<m; i++){
		ans.insert(b[i]);
	}
	return ans.size();
}

int main(){
	int n;cin>>n;
	int a[n];
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	int m;cin>>m;
	int b[m];
	for(int i = 0; i<m; i++){
		cin>>b[i];
	}

	cout<<unioArray(a, n, b, m);

	return 0;
}