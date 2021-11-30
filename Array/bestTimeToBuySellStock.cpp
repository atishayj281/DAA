#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> prices){

	if(prices.size() == 0) return 0; 
	int mi=prices[0], ma = prices[0];
	int i = 0;
	int maxProfit = 0;
	for(int i = 0; i<prices.size(); i++) {
		if (prices[i] > prices[i - 1]) 
		maxProfit += prices[i] - prices[i - 1];
	}
	return maxProfit;
}

int maxProfit(vector<int> prices){
	if(prices.size() == 0) return 0;
	int cost = 0;
	int maxCost = 0;
	int minPrice = prices[0];
	for(int i = 0; i<prices.size(); i++) {
		minPrice = min(minPrice, prices[i]);
		cost = prices[i] - minPrice;
		maxCost = max(maxCost, cost);

	}
	return maxCost;
}

int main() {
	
	int n;cin>>n;
	vector<int> v;
	int input;
	for(int i = 0; i<n; i++) {
		cin>>input;
		v.push_back(input);
	}

	cout<<maxProfit(v);

	return 0;
}
