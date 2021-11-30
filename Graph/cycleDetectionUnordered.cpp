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

vector<bool> vis(N, false);
vector<vector<int>> graph(N);

bool isCycle(int parent, int source) {
	vis[source] = true;
	for(auto i: graph[source]) {
		if(i != parent) {
			if(vis[i]) return true;
		} 
		if(!vis[i] && isCycle(source, i)) {
			return true;
		}
	}
	return false;
}

int main() {
	int vertices, edges;cin>>vertices>>edges;
	int x, y;
	for(int i = 0; i<edges; i++) {
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bool cycle = false;
	for(int i = 0; i<vertices; i++) {
		if(!vis[i] && isCycle(-1, i)) {
			cycle = true;
		}
	}

	if(cycle) cout<<"Cycle is Present";
	else cout<<"Cycle is not present";

	return 0;
}