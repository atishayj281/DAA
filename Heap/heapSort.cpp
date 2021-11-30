#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define gcd(x, y) __gcd(x, y)
#define f(i, a, b) for(int i = a; i<b; i++)
void heapify(vi& arr, int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest]) largest = l;
 
    if (r < n && arr[r] > arr[largest]) largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
void heapsort(vi& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}

int main() {
	int n;cin>>n;
	vi a(n+1, INT_MIN);
	f(i, 1, n+1) {
		cin>>a[i];
	}

	heapsort(a, a.size());

	f(i, 1, n+1) cout<<a[i]<<" ";

	return 0;
}