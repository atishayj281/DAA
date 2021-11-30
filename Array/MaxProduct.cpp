// find maximum product subarray 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for(int i = a; i<b; i++)

int solve(vector<int> a) {
	int n = a.size();
	if(n == 0) return 0;
	if(n == 1) return a[0];
	int maxprod = a[0];
	int minVal = a[0];
	int maxVal = a[0];

	for(int i = 1; i<n; i++) {
		if(a[i] < 0) swap(minVal, maxVal);
		minVal = min(minVal, minVal * a[i]);
		maxVal = max(maxVal, a[i]*maxVal);
		maxprod = max(maxprod, maxVal);
	}
	return maxprod;
}
 
int main() {
	int n;cin>>n;
	vector<int> a;
	f(i, 0, n) {
		int k;cin>>k;
		a.push_back(k);
	}

	cout<<"Max Product is: "<<solve(a);
	return 0;
}