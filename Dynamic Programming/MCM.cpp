#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define gcd(x, y) __gcd(x, y)
#define f(i, a, b) for(int i = a; i<b; i++)
#define pii pair<int, int>
#define vii vector<pi>
#define pb(x) push_back(x)
#define ff first
#define ss second
#define mii map<int, int>
#define w int x;cin>>x;while(x--)
const int mod = 1e9+7, inf = 1e5+2;
int main() {
	int n;cin>>n;
	vi p(n);
	f(i, 0, n) cin>>p[i];
	vvi dp(n, vi(n, inf));
	for(int i = 1; i<n; i++) {
		dp[i][i] = 0;
	}
	for(int l = 2; l<n; l++) {
		for(int i = 1; i<n-l+1; i++) {
			int j = l+i-1;
			for(int k = i; k<j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+p[i-1]*p[j]*p[k]);
			}
		}
	}
	cout<<"Minimum Operations to be done are: "<<dp[1][n-1];
	return 0;
}