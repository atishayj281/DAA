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
vi graph[N];
vector<bool> vis(N, false);

void dfs(int source) {
	// preorder
	vis[source] = true;
	// cout<<source<<endl;
	// inorder
	vector<int>::iterator it;
	for(it = graph[source].begin(); it != graph[source].end(); it++) {
		if(!vis[*it]) {
			dfs(*it);
		}
	}

	// postOrder
	cout<<source<<endl;
}

int main() {
	int vertices, edges;
	cin>>vertices>>edges;
	for(int i = 0; i<edges; i++) {
		int x, y;cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	vector<int> a;
	

	int source;cout<<"Enter the source: ";cin>>source;
	dfs(source);
	return 0;
}