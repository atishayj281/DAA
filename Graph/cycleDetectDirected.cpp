// Cycle Detection in Directed Graph
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define gcd(x, y) __gcd(x, y)
#define f(i, a, b) for(int i = a; i<b; i++)
#define pi pair<int, int>
#define vii vector<pi>
const int N = 1e5+2, mod = 1e9+7;

bool iscycle(int source, vector<vector<int>>&adj, vector<bool> &stack, vector<bool> &vis) {
	stack[source] = true;
	if(!vis[source]) {
		vis[source] = true;
		for(auto i: adj[source]) {
			if(!vis[i] and iscycle(i, adj, stack, vis)) return true;
			if(stack[i]) return true;
		}
	}
	stack[source] = false;
	return false;
}

int main() {
	vector<vector<int>> adj(N);
	int vertices, edges;cin>>vertices>>edges;
	for(int i = 0; i<edges; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
	}

	vector<bool> stack(N, false);
	vector<bool> vis(N, false);
	bool cycle = false;
	for(int i = 0; i<vertices; i++) {
		if(!vis[i] and iscycle(i, adj, stack, vis)) {
			cycle = true;
			break;
		} 
	}
	if(cycle) cout<<"Cycle is Present";
	else cout<<"Cycle is not present";
	return 0;
}