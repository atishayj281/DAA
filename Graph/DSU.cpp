// Find the Disjoint Set Union
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

vi parent(N);
vi size(N);

void make_set(int v){
	parent[v] = v;
	size[v] = 1;
}

int find_set(int v) {
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
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

	int vertices, edges;
	cin>>vertices>>edges;
	vvi adj(N);
	for(int i = 0; i<edges; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		union_sets(x, y);
	}
	int v;
	cout<<"Enter the vertex to find it's parent: ";
	cin>>v;

	cout<<find_set(v);


	
	return 0;
}