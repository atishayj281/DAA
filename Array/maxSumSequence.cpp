#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)

int solve(int arr[], int n)
{
	unordered_set<int> freq;
	int ans = 0;
	f(i, 0, n) freq.insert(arr[i]);

	f(i, 0, n){
		if(freq.find(arr[i] - 1) == freq.end()){
			int j = arr[i];
			while(freq.find(j) != freq.end()) j++;

			ans = max(ans, j - arr[i]);
		}
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	f(i, 0, n) cin >> a[i];
	cout << solve(a, n);
	return 0;
}