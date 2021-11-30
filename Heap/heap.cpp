#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for(int i = a; i<b; i++)

void insertHeap(vector<int>& a, int v) {
	a.push_back(v);
	int i = a.size() - 1;
	while(i > 1) {
		int parent = i/2;
		if(a[parent] < a[i]) {
			int temp = a[parent];
			a[parent] = a[i];
			a[i] = a[parent];
			i = parent;
		} else return;
	}
}

void deleteHeap(vector<int>& arr) {
	arr[1] = arr[arr.size()-1];
	arr.pop_back();
	int i = 1;
	while(i < arr.size()) {
		int left = arr[i*2];
		int right = arr[2*i + 1];
		int larger = left > right ? 2*i : (2*i) + 1;
		if(arr[larger] > arr[i]) {
			int t = arr[larger];
			arr[larger] = arr[i];
			arr[i] = t;
			i = larger;
		} else return;
	}

}


int main() {
	vector<int> arr;
	// arr.push_back(INT_MAX);
	for(int i = 0; i<10; i++) {
		insertHeap(arr, i);
		
	}
	for(int i = 0; i<10; i++) {
		deleteHeap(arr);
	}

	cout<<"Size of heap is: "<<arr.size();

	return 0;
}