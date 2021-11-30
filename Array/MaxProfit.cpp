// Maximum profit by buying and selling a share atmost twice

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for(int i = a; i<b; i++)

int solve(int a[], int n) {
	int profit = 0;
	for(int i = 1; i<n; i++) {
		int diff = a[i] - a[i-1];
		if(diff > 0) profit += diff;
	}
	return profit;
}

int main() {
	int n;cin>>n;
	int a[n];
	f(i, 0, n) cin>>a[i];
	cout<<"Maximum Profit: "<<solve(a, n);
	return 0;
}