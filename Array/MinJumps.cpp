// Minimum no. of Jumps to reach end of an array

#include<iostream>
using namespace std;

int solve(int a[], int n) {
	if(n == 1) return 0;
	if(a[0] == 0) return -1;
	int jumps = 1;
	int steps = a[0];
	int maxreange = a[0];

	for(int i = 1; i<n; i++) {
		if(i == n - 1) {
			return jumps;
		}

		maxreange = max(maxreange, i+a[i]);
		steps--;
		if(steps == 0) {
			jumps++;
			if(i >= maxreange) return -1;
			steps = maxreange - i;
		}
	}
	return jumps;
}

int main(){
	int n;cin>>n;
	int a[n];
	for(int i = 0; i<n; i++) {
		cin>>a[i];
	}
	cout<<solve(a, n);
	return 0;
}

