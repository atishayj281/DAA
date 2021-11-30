#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for(int i = a; i<b; i++)

int solve(vector<int> a, int k) {
	sort(a.begin(), a.end());
	int n = a.size();
	int ans = a[a.size()-1] - a[0];
	int minh = a[0] + k;
	int maxh = a[a.size()-1] - k;
	int mi, ma;
	for(int i = 0; i<n-1; i++) {
		mi = min(minh, a[i+1] - k);
		ma = max(maxh, a[i] + k);
		if(mi < 0) continue;
		ans = min(ans, ma - mi);
	}

	return ans;
}

int main() {
	int n;cin>>n;
	int k;cin>>k;
	vector<int> heights;
	int in;
	f(i, 0, n) {
		cin>>in;
		heights.push_back(in);
	}

	cout<<"Minimum height is: "<< solve(heights, k);
	return 0;
}