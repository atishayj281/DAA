#include<iostream>
using namespace std;

void dec(int n){
    if(n == 1){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    return dec(n-1);
}

int main(){
    dec(5);
    return 0;
}