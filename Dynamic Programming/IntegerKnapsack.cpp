#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define gcd(x, y) __gcd(x, y)
#define f(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define vii vector<pi>
#define pb(x) push_back(x)
#define ff first
#define ss second
#define mii map<int, int>
const int mod = 1e9 + 7, N = 1e5 + 2;

vvi dp;

int knapSack(int W, vi wt, vi val, int n) {

	if(W == 0 || n == 0) return 0;
	if(dp[n][W] != -1) return dp[n][W];
	if(wt[n-1] > W) {
		dp[n][W] = knapSack(W, wt, val, n-1);
	} else {
		dp[n][W] = max(knapSack(W-wt[n-1], wt, val, n-1) + val[n-1], 
	knapSack(W, wt, val, n-1));
	}
	
	return dp[n][W];
}

int main() {
	int n, W;
	cin >> n >> W;
	vi w(n);
	vi cost(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	for(int i = 0; i<=n;i++) {
		vi a;
		for(int j = 0; j<=W;j++) {
			if(i == 0 || j == 0) a.push_back(0);
			else a.push_back(-1);
		}
		dp.push_back(a);
	}
	cout<<knapSack(W, w, cost, n);
	return 0;
}