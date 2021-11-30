#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
bool find3Numbers(int a[], int n, int x)
{ //Your Code Here
	int low, high;
	sort(a, a + n);
	for (int i = 0; i < n - 2; i++)
	{
		low = i+1;
		high = n-1;
		while (low < high)
		{
		cout<<low<<" "<<high<<endl; 
			int sum = a[i] + a[low] + a[high];
			if (sum == x){
				cout<<sum;
				return true;
			}
			else if (sum < x){
				low++;
			}
			else{
				high++;
			}
		}
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	int x;
	cin >> x;
	int a[n];
	f(i, 0, n) cin >> a[i];
	cout << find3Numbers(a, n, x);
	return 0;
}