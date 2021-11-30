//find common elements In 3 sorted arrays
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (i = a; i < b; i++)

vector<int> common_elements(int a[], int b[], int c[], int n1, int n2, int n3)
{
	vector<int> ans;
	set<int> s;
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2 && k < n3)
	{
		if (a[i] == b[j] && b[j] == c[k])
		{
			s.insert(a[i]);
			i++;
			j++;
			k++;
		}
		else if (a[i] < b[j])
			i++;
		else if (b[j] < c[k])
			j++;
		else
			k++;
	}
	for(int item: s) {
		ans.push_back(item);
	}
	return ans;
}

int main()
{
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int a[n1], b[n2], c[n3];
	int i;
	f(i, 0, n1) cin >> a[i];
	f(i, 0, n2) cin >> b[i];
	f(i, 0, n3) cin >> c[i];

	vector<int> ans = common_elements(a, b, c, n1, n2, n3);
	for (int i : ans)
	{
		cout << i << " ";
	}
	return 0;
}