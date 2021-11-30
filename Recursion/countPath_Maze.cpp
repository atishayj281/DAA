#include<iostream>
using namespace std;

// Count the total no. of exists paths in a n*n matrix
int countPath(int i, int j, int n){
    if(i==n-1 && j == n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countPath(i+1, j, n) + countPath(i, j+1, n);
}

int main(){
    cout<<countPath(0, 0, 3);
    return 0;
}