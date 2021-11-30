// Rearrange the array in alternating positive and negative items with O(1) extra space
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;cin>>n;
	int a[n];
	for(int i = 0; i<n; i++) cin>>a[i];
	int i = 0, j = 0;
	while(i < n && j < n) {

		while(j < n && a[j] > 0) j++;
		if(j >= n) break;
		while(i < n && a[i] <= 0) i++;
		if(i >= n) break;

		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;

		i++;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
	}

	for(int i = 0; i<n; i++) cout<<a[i]<<" ";
	return 0;
}