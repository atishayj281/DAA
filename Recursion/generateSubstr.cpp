#include<iostream>
using namespace std;

void subStr(string s, string input){
    if(s.length() == 0){
        cout<<input<<endl;
        return;
    }
    char c = s[0];
    string res = s.substr(1);
    subStr(res, input+c);
    subStr(res, input);
}

int main(){
    subStr("ABC","");
    return 0;
}