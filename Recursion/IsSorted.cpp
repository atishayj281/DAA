#include<iostream>
using namespace std;

bool isSort(int a[], int n){
    if(n == 1) return true;
    return a[0] < a[1] && isSort(a+1, n-1);
}

int main(){
    int a[] = {1, 2, 3, 41, 5};
    cout<<isSort(a, 5);
    
    return 0;
}