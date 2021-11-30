#include <bits/stdc++.h>
using namespace std;
void solve(int a[], int n){
	int culIdx = n-1;
	for(int i = n-2; i<=0; i++){
		if(a[i] < a[i+1]){
			culIdx = i;
			break;
		}
	}
	int i = n-1;
	while(i >= 0 && a[i] < a[culIdx]) i--;
	int temp = a[i];
	a[i] = a[culIdx];
	a[culIdx] = temp;
	reverse(a+culIdx+2, a+n);
}

int main() {
	int n;cin>>n;
	int a[n];
	for(int i = 0; i<n; i++) {
		cin>>a[i];
	}

	next_permutation(a, a+n);
	for(int i: a) {
		cout<<i<< " ";
	}
	return 0;
}