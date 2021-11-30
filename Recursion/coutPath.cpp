#include<iostream>
using namespace std;


int countPath_board(int s, int d, int n){
    if(s == d){
        return 1;
    }
    if(s>d || d>=n || s>=n){
        return 0;
    }
    int count = 0;
    for(int i = 1; i<=6; i++){
        count += countPath_board(s+i, d, n);
    }
    return count;
}

int main(){
    cout<<countPath_board(0, 3, 10);
    return 0;
}