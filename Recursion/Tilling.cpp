#include<iostream>
using namespace std;

int countWays(int n){
    if(n == 0 || n == 1 || n ==2){
        return n;
    }
    return countWays(n-1) + countWays(n-2);
}

int main(){
    cout<<countWays(4);
    return 0;
}