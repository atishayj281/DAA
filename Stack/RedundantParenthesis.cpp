#include"bits/stdc++.h"
using namespace std;

int get_redundant(string s){
	stack<char> st;
	int ans = 0;
	for(int i = 0; i<s.length(); i++){
		if(s[i] == '(' || s[i] == '+' || s[i] == '-'){
			st.push(s[i]);
		}else if(s[i] == ')'){
			if(st.top() == '('){
				ans++;
			}else {
				while(st.top() != '('){
					st.pop();
				} 
				st.pop();
			}
		}
	}
	return ans;
}

int main(){
	string s = "((a+b))";
	cout<<get_redundant(s);
	return 0;
}