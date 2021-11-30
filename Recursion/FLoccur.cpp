#include<iostream>
using namespace std;

int first(int a[], int n, int i, int key){
    if(i == n) return -1;
    if(a[i] == key) return i;
    return first(a, n, i+1, key);
}

int last(int a[], int n, int i, int key){
    if(i == n) return -1;
    int rest = last(a, n, i+1, key);
    if(rest != -1){
        return rest;
    }
    if(a[i] == key) return i;
    return -1;
}

int main(){
    int a[] = {2, 4, 1, 4, 5};
    cout<<first(a, 5, 0, 4)<<" ";
    cout<<last(a, 5, 0, 6);
    return 0;
}