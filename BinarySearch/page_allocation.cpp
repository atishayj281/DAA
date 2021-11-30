#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)

bool isPossible(int a[], int n, int m, int min)
{
	int student_required = 1, sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > min)
			return false;
		if (sum + a[i] > min)
		{
			student_required++;
			sum = a[i];
			if (student_required > m)
				return false;
		}
		else
		{
			sum += a[i];
		}
	}
	return true;
}

//Function to find minimum number of pages.
int findPages(int A[], int N, int M)
{
	//code here
	int start = A[0];
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += A[i];
	int end = sum;
	int ans = INT_MAX;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (isPossible(A, N, M, mid))
		{
			end = mid - 1;
			ans = min(ans, mid);
		}
		else
		{
			start = mid + 1;
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout <<findPages(a, n, m);
	}
	return 0;
}