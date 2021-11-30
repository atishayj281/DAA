#include<iostream>
using namespace std;

int knap(int W[], int V[], int w, int n){
    if(w == 0 || n == 0){
        return 0;
    }
    if(W[n-1] > w){
        return knap(W, V, w, n-1);
    }
    return max(knap(W, V, w-W[n-1], n-1) + V[n-1], knap(W, V, w, n-1));
}

int main(){
    int w[] = {10, 20, 30};
    int V[] = {100, 50, 150};
    int W = 50;
    cout<<knap(w, V, W, 3);
    return 0;
}