#include "bits/stdc++.h"
using namespace std;

vector<int> stockSpan(vector<int> prices)
{
	stack<pair<int, int>> st;
	vector<int> ans;
	for (auto price : prices)
	{
		int days = 1;
		while (!st.empty() and st.top().first <= price)
		{
			days += st.top().second;
			st.pop();
		}
		st.push({price, days});
		ans.push_back(days);
	}

	return ans;
}

int main()
{
	vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
	vector<int> ans = stockSpan(prices);
	for (auto days : ans)
	{
		cout << days << " ";
	}
	return 0;
}