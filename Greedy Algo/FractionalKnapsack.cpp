#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define gcd(x, y) __gcd(x, y)
#define f(i, a, b) for(int i = a; i<b; i++)
#define vii vector<pair<int, int>>
#define ff first
#define ss second
#define pi pair<int, int>

bool compare(pi x, pi y) {
	int f1 = x.second / x.first;
	int f2 = y.second / y.first;
	return f1 > f2;
}

int knapsack(vii wc, int W) {
	int ans = 0;
	sort(wc.begin(), wc.end(), compare);
	for(pi i: wc) {
		if(i.first <= W) {
			ans += i.second;
			W -= i.first;
		} else {
			ans += (i.second / i.first) * W;
			W = 0;
			break;
		}
	}
	return ans;
}
int main() {
	int n, W;cin>>n>>W;
	vii wc;
	f(i, 0, n) {
		int f, s;
		cin>>f>>s; // f --> weight , s --> cost
		wc.push_back({f, s});
	}
	cout<<knapsack(wc, W);
	return 0;
}