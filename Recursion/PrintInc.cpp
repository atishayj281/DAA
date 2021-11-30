#include<iostream>
using namespace std;

void inc(int s, int n){
    if(s == n){
        cout<<s<<" ";
        return;
    }
    cout<<s<<" ";
    inc(s+1, n);
}

int main(){
    inc(1, 10);
    return 0;
}