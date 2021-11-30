#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int mod = 1e9+7, N = 1e5+2;

bool compare(pi x, pi y) {
	if(x.second == y.second) {
		return x.first < y.first;
	}
	return x.second < y.second;
}

int main() {
	int n;cin>>n;
	vector<pair<int, int>> time;
	for(int i = 0; i<n; i++) {
		int x, y;
		cin>>x>>y;
		time.push_back({x, y});
	}
	sort(time.begin(), time.end(), compare);
	int ans = 1;
	int i = 0, j = 1;
	while(j < n) {
		if(time[i].second < time[j].first) {
			ans++;
			i = j;
		}
		j++;
	}
	cout<<"Maximum Job can be held are: "<<ans;

	return 0;
}