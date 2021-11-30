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
	int n, m;cin>>n>>m;
	int x, y;
	vector<vector<int>> adj(N);
	for(int i = 0; i<m; i++) {
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int s, d;
	cout<<"Enter the source and destination: ";
	cin>>s>>d;
	queue<int> q;
	vector<int> dis(N, 0);
	vector<bool> vis(N, false);
	q.push(s);
	vis[s] = true;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(int i: adj[node]) {
			if(!vis[i]) {
				dis[i] = dis[node]+1;
				q.push(i);
				vis[i] = true;
			}
		}
	}
	cout<<"Distance is: "<<dis[d];
	return 0;
}