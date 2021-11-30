#include "bits/stdc++.h"
using namespace std;

vector<int> solve(int a[], int n1, int b[], int n2)
{
	vector<int> ans;
	
	int i=0, j = 0, k = n1-1;
	while(i<=k && j < n2) {
		if(a[i] >= b[j]){
			int temp = a[k];
			a[k] = b[j];
			b[j] = temp;
			k--;
			j++;
		} else {
			i++;
		}
	}

	sort(a, a+n1);
	sort(b, b+n2);

	for (int i = 0; i < n1; i++)
	{
		ans.push_back(a[i]);
	}
	for (int i = 0; i < n2; i++)
	{
		ans.push_back(b[i]);
	}
	return ans;
}

int main()
{
	int n1;
	cin >> n1;
	int a[n1];
	for (int i = 0; i < n1; i++)
	{
		cin >> a[i];
	}
	int n2;
	cin >> n2;
	int b[n2];
	for (int i = 0; i < n2; i++)
	{
		cin >> b[i];
	}

	vector<int> ans = solve(a, n1, b, n2);
	for (int a : ans)
	{
		cout << a << " ";
	}

	return 0;
}