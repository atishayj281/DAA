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

bool biparite = true;	// this varibale will record whether the graph is Bipariatte or not

void color(int idx, int clr, vector<int> &colr, vector<bool> &vis, vector<vector<int>> &adj) {
	if(colr[idx] != -1 and colr[idx] != clr) {  // If the vertex is already coloured
		biparite = false;		  // and the color is different
		return;
	}
	colr[idx] = clr;	// color the vertex
	if(vis[idx]) return;	// if the vertex is already visited then return
	vis[idx] = true;	// visit the vertex
	for(int i: adj[idx]) {	// traverse through the list
		color(i, clr xor 1, colr, vis, adj);	// color all the child vertices
	}
}

int main() {
	int vertices, edges;cin>>vertices>>edges;
	vector<vector<int>> adj(N);
	int x, y;
	for(int i = 0; i<edges; i++) {
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<int> colr(vertices, -1);
	vector<bool> vis(vertices, false);
	int clr = 0; // Let the first color is 0
	// -1 represents that there in no color

	for(int i = 0; i<vertices; i++) {
		color(i, clr, colr, vis, adj);
	}

	if(biparite) cout<<"Graph is Biparriate";
	else cout<<"Graph is not biparriate";

	return 0;
}