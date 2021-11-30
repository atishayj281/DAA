// Detect the Cycle in Undirected Graph using Disjoint Set Union.
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

vi size(N);
vi parent(N);

void make_set(int v) {
	parent[v] = v;
	size[v] = 1;
}

int find_set(int v) {
	if(parent[v] == v) return v;
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if(a != b) {
		if(size[a] < size[b]) {
			swap(a, b);
		}
		parent[b] = a;
		size[a] += size[b];
	}
}


int main() {
	for(int i = 0; i<N; i++) {
		make_set(i);
	}
	int vertices, edges;cin>>vertices>>edges;
	vector<pair<int, int>> adj;
	int x, y;
	for(int i = 0; i<vertices; i++) {
		cin>>x>>y;
		adj.push_back({x, y});
	}

	bool iscycle = false;
	for(auto i: adj) {
		int u = i.first;
		int v = i.second;
		int x = find_set(u);
		int y = find_set(v);
		if(x == y) {
			iscycle = true;
		}
		else {
			union_set(u, v);
		}
	}

	if(iscycle) cout<<"Cycle is Found";
	else cout<<"Cycle is not Present";

	return 0;
}