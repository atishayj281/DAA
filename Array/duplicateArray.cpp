#include<iostream>
using namespace std;

int solve(int a[], int n) {
	int res = 0;
	for(int i = 0; i<=n; i++) {
		res = res ^ a[i];
	}
	for(int i = 1; i<=n; i++) {
		res = res ^ i;
	}
	return res;
}

int main(){
	int n;cin>>n;
	int a[n+1];
	for(int i = 0; i<=n; i++) {
		cin>>a[i];
	}
	cout<<solve(a, n);
	return 0;
}