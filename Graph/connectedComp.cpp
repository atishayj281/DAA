// Calculate the number of connected component in a graph and their sizes.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define gcd(x, y) __gcd(x, y)
#define f(i, a, b) for(int i = a; i<b; i++)
#define pi pair<int, int>
#define vii vector<pi>
const int N = 1e5+2;

int get_comp(int idx, vvi graph, vector<bool> &vis) {
	if(vis[idx]) return 0;
	vis[idx] = true;
	int ans = 1;
	for(auto i: graph[idx]) {
		if(!vis[i]) {
			ans += get_comp(i, graph, vis);
		}
	}
	return ans;
}

int main() {
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> graph(N);
	int x, y;
	for(int i = 0; i<edges; i++) {
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	vector<bool> vis(vertices, false);
	vector<int> components_size;
	for(int i = 0; i<vertices; i++) {
		if(!vis[i]) {
			components_size.push_back(get_comp(i, graph, vis));
			// cout<<get_comp(i, graph, vis)<<endl;
		}
	}

	for(auto i: components_size) {
		cout<<i<<" ";
	}
	return 0;
}