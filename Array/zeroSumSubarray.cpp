#include <bits/stdc++.h>
using namespace std;

bool zeroSum(int a[], int n){
	unordered_set<int> sum;
	int curSum = 0;
	for(int i = 0; i<n; i++) {
			curSum = curSum + a[i];
			if(sum.find(curSum) != sum.end() || curSum == 0) {
				return true;
			}
			sum.insert(curSum);
		
	}
	return false;
}

int main() {
	int n;cin>>n;
	int a[n];
	for(int i =0; i<n; i++) cin>>a[i];
	cout<<zeroSum(a, n);
	return 0;
}