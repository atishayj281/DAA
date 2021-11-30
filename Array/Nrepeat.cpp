// Given an array of size n and a number k, find all elements that appear more than " n/k " times.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for(int i = a; i<b; i++)

unordered_set<int> solve(int a[], int n, int k) {
	unordered_map<int, int> freq;
	unordered_set<int> ans;
	for(int i = 0; i<n; i++) {
		freq[a[i]]++;
	}

	for(int i = 0; i<n; i++) {
		if(freq[a[i]] >= k) {
			ans.insert(a[i]);
		}
	}

	return ans;
}

int main() {
	int n;cin>>n;
	int k;cin>>k;
	int a[n];
	f(i, 0, n) cin>>a[i];
	unordered_set<int> ans = solve(a, n, k);
	for(int a: ans) cout<< a<<" ";
	return 0;
}