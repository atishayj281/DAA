#include<iostream>
using namespace std;

// Print all the ASCII subsequence of a string
void subseq(string s, string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string res = s.substr(1);
    subseq(res, ans);
    subseq(res, ans+ch);
    int num = ch;
    subseq(res, ans+to_string(num));
}

int main(){
    subseq("AB", "");
    return 0;
}