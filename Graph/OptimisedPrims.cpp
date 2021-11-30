#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define gcd(x, y) __gcd(x, y)
#define f(i, a, b) for(int i = a; i<b; i++)
#define pi pair<int, int>
#define vii vector<pi>
const int mod = 1e9+7, N = 1e5+2;
int main() {
	int vertices, edges;cin>>vertices>>edges;
	vector<pair<int, int>> adj[vertices];

	int x, y, wt;
	for(int i = 0; i<edges; i++) {
		cin>>wt>>x>>y;
		adj[x].push_back({y, wt});
		adj[y].push_back({x, wt});
	}

	vector<int> parent(vertices);
	vector<int> key(vertices);
	vector<bool> mstSet(vertices);

	for(int i = 0; i<vertices; i++) {
		parent[i] = -1;
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	// MinPriority Queue
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	key[0] = 0;
	parent[0] = -1;
	pq.push({0, 0}); // first = key, second = index

	for(int count = 0; count < vertices - 1; count++) {
		int u = pq.top().second;
		pq.pop();

		for(auto i: adj[u]) {
			int v = i.first;
			int weight = i.second;
			if(!mstSet[v] and weight < key[v]) {
				key[v] = weight;
				parent[v] = u;
				pq.push({key[v], v});
			}
		}
	}

	for(int i = 0; i<vertices; i++) {
		cout<<parent[i]<<" - "<<i<<endl;
	}


	return 0;
}