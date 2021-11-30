#include <bits/stdc++.h>
using namespace std;

void solve(string in, string out) {

	if(out.size() == 0) {
		cout<<in<<" ";
		return;
	}

	for(int i = 1; i<out.size(); i++) {
		//cout<<in<<" ";
		solve(in+out[i-1], out.substr(i, out.size()));
		solve(in, out.substr(i, out.size()));
	}
	return;
}

int main() {
	string s;cin>>s;
	solve("", s);
	return 0;
}