#include <bits/stdc++.h>
using namespace std;

int countPair(int a[], int n, int k) {
	unordered_map<int, int> frequency;
	int count = 0;
	for(int i = 0; i<n; i++) {
		frequency[a[i]]++;
	}

	for(int i = 0; i<n; i++) {
		count += frequency[k - a[i]];
		if(k - a[i] == a[i]) {
			count--;
		}
	}
	return count/2;
} 

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i<n; i++ ){
		cin>>a[i];
	}
	int k;cin>>k;

	cout<<"Total Pairs: "<<countPair(a, n, k);
	return 0;
}