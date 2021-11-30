#include<iostream>
using namespace std;

int SumTillN(int n){
    if(n == 0) return 0;
    int prevSum = SumTillN(n-1);
    return n + prevSum;
}

int main(){
    cout<<SumTillN(5);
    return 0;
}