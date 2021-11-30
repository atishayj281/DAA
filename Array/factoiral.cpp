// find factorial of a bigger number...
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for(int i = a; i<b; i++)
#define MAX 10000

int multiply(int x, int res[], int res_size){
	int carry = 0;
	for(int i = 0; i<res_size; i++) {
		int pro = res[i] * x + carry;
		res[i] = pro%10;
		carry = pro/10;
	}
	while (carry)
	{
		res[res_size] = carry%10;
		carry /= 10;
		res_size++;
	}

	return res_size;	
}

vector<int> solve(int n) {
	int res[MAX];
	vector<int> ans;
	res[0] = 1;

	int res_size = 1;

	for(int i = 2; i<=n; i++) {
		res_size = multiply(i, res, res_size);
	}

	for(int i = res_size - 1; i>= 0; i--) {
		ans.push_back(res[i]);
	}

	return ans;
}

int main() {
	
	int n;cin>>n;

	vector<int> res;
	res = solve(n);

	for(int i: res) {
		cout<<i;
	}
	return 0;
}