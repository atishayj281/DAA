// Kruskal Algorithm is used to find the Minimum Spanning Tree from a Graph.
// Spanning Tree - 'Spanning Tree is a subGraph which does not include a cycle having the same number of vertices'
// Minimum Spanning Tree - 'Minimum Spanning Tree is the spanning tree with minimum total weight'

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
	size[v] = v;
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

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first < b.first;
}

int main() {

	for(int i = 0; i<N; i++) {
		make_set(i);
	}

	int vertices, edges; cin>>vertices>>edges;
	vector<pair<int, pair<int, int>>> graph;
	int x, y, w;
	for(int i = 0; i<edges; i++) {
		cin>>w>>x>>y;
		graph.push_back({w, {x, y}});
	}

	sort(graph.begin(), graph.end(), compare);

	int ans = 0;

	for(pair<int, pair<int, int>> i : graph) {
		if(find_set(i.second.first) != find_set(i.second.second)) {
			ans += i.first;
			union_set(i.second.first, i.second.second);
		}
	}

	cout<<"Weight of the MST is: "<<ans;
	return 0;
}