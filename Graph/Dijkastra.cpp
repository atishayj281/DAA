#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define gcd(x, y) __gcd(x, y)
#define f(i, a, b) for(int i = a; i<b; i++)
#define pii pair<int, int>
#define vii vector<pi>
#define pb(x) push_back(x)
#define ff first
#define ss second
#define mii map<int, int>
const int mod = 1e9+7, inf = 1e5+2;
int main() {
	int vertices, edges;cin>>vertices>>edges;
	vi dist(vertices+1, inf);
	vector<vector<pair<int, int>>> graph(vertices+1);
	for(int i = 0; i<edges; i++) {
		int x, y, w;
		cin>>x>>y>>w;
		graph[x].push_back({w, y});
		graph[y].push_back({w, x}); // first-> weight, second -> vertex
	}
	int source;
	cout<<"Enter the source: ";cin>>source;
	dist[source] = 0;
	set<pair<int, int>> s;
	s.insert({0, source}); // first -> distance, second -> vertex
	while (!s.empty())
	{
		auto u = *s.begin();
		s.erase(u);
		for(auto i: graph[u.second]) {
			if(dist[i.second] > dist[u.second] + i.first) {
				s.erase({dist[i.second], i.second});
				dist[i.second] = dist[u.second] + i.first;
				s.insert({dist[i.second], i.second});
			}
		}
	}
	for(int i = 0; i<=vertices; i++) {
		if(dist[i] < inf) cout<<i<<": "<<dist[i]<<endl;
		else cout<<i<<": -1"<<endl;
	}
	
 	return 0;
}