#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals){
	stack<vector<int>> st;
	vector<vector<int>> ans;
	sort(intervals.begin(), intervals.end());
	st.push({intervals[0][0], intervals[0][1]});
	for(int i = 1; i<intervals.size(); i++) {
		int start1 = st.top()[0];
		int end1 = st.top()[1];
		int start2 = intervals[i][0];
		int end2 = intervals[i][1];
		if(end1 < start2) {
			vector<int> ans;
			ans.push_back(start2);
			ans.push_back(end2);
			st.push(ans);
		} else {
			st.pop();
			end1 = max(end1, end2);
			st.push({start1, end1});
		}
	}

	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}

int main() {
	vector<vector<int>> v;
	int n;cin>>n;
	for(int i = 0; i<n; i++){
		vector<int> v1;
		int input;
		for(int j = 0; j<2; j++) {
			cin>>input;
			v1.push_back(input);
		}
		v.push_back(v1);
	}

	vector<vector<int>> ans = merge(v);
	for(vector<int> a: ans){
		cout<<a[0]<<" "<<a[1]<<endl;
	}
	return 0;
}