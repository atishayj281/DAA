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
	vector<pair<int, int>> adj[N];
	for(int i = 0; i<edges; i++) {
		int x, y, wt;
		cin>>wt>>x>>y;
		adj[x].push_back({y, wt});
		adj[y].push_back({x, wt});
	}

	vector<int> parent(N);	// Array to store the parent of all the edges in mst
	vector<int> key(N);	// Array to store the weight
	vector<bool> mstSet(N);	// Array to store the MST

	for(int i = 0; i<vertices; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
		parent[i] = -1;
	}

	key[0] = 0;
	parent[0] = -1;

	for(int count = 0; count < vertices - 1; count++) {
		int mi = INT_MAX, u;

		// Finding the minimal weight index which is not a part of MST till now
		for(int v = 0; v < vertices; v++) {
			if(!mstSet[v] and key[v] < mi) {
				mi = key[v];
				u = v;
			}
		}

		// setting the minimal index as a part of the MST
		mstSet[u] = true;

		// Traverse through all the edges and updating the parent and key value i.e. weight
		for(auto i: adj[u]) {
			int v = i.first;
			int weight = i.second;
			if(!mstSet[v] and weight < key[v]) {	// If the edge is not a part of the MST and 
				parent[v] = u;			// it's current assigned weight is greater than
				key[v] = weight;		// the encountered weight then reassign the weight 
								// and reassign the parent.
			}
		}
	}
	for(int i = 0; i < vertices; i++) {
		cout<<parent[i] << " - "<<i<<endl;
	}
	return 0;
}