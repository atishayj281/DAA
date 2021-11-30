#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for(int i = a; i<b; i++)

int trappingWater(int arr[], int n){
        int prefix[n];
	int suffix[n];
	prefix[0] = arr[0];
	suffix[n-1] = arr[n-1];
	for(int i = 1; i<n; i++) {
		prefix[i] = max(arr[i], prefix[i-1]);
	}

	for(int i = n-2; i>= 0; i--) {
		suffix[i] = max(arr[i], suffix[i+1]);
	}

	int ans = 0;
	for(int i = 0; i<n; i++) {
		ans += min(prefix[i], suffix[i]) - arr[i];
	}

	return ans;
    }

int main() {
	int n;cin>>n;
	int a[n];
	f(i, 0, n) cin>>a[i];
	cout<<trappingWater(a, n);
	return 0;
}