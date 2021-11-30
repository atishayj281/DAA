#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define f(i, a, b) for(int i = a; i<b; i++)

const int N = 1e5+2, MOD = 1e9+7;

vi adjList[N];

int main() {
	int nodes, edges;cin>>nodes>>edges;
	
	// vvi adjm(nodes+1, vi(nodes+1, 0));
	// for(int i = 0; i<edges; i++) {
	// 	int x, y;
	// 	cin>>x>>y;
	// 	adjm[x][y] = 1;
	// 	adjm[y][x] = 1;
	// }

	// cout<<"Adjacency Matrix of above graph is: \n";
	// for(int i = 1; i<nodes+1; i++) {
	// 	for(int j = 1; j<nodes+1; j++) {
	// 		cout<<adjm[i][j]<<" ";
	// 	} cout<<endl;
	// }

	// int f1, f2;cin>>f1>>f2;
	// if(adjm[f1][f2] == 1) cout<<"Edge is present\n";
	// else cout<<"Edge is note present b/w ${f1} and ${f2}";
	// cout<<endl;

	// Adjacency List
	for(int j = 1; j<=nodes; j++) {
		int x, y;cin>>x>>y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	cout<<"Adjacncy List of the above graph is given by: \n";
	for(int i = 1; i<=nodes; i++) {
		cout<<i<<"->";
		for(int x: adjList[i]) {
			cout<<x<<"->";
		}
		cout<<endl;
	}

	return 0;
}