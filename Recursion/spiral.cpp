#include<iostream>
using namespace std;

void spiralMat(int** a, int n, int i, int j){
    if(i == n/2 && j == n/2){
        a[i][j] = n;
        return;
    }
    if(i == n-1 && j < n-1){
        a[i][j] = n;
        return spiralMat(a, n+1, i, j+1);
    } else if(i < n-1 && j )

}
int main(){
     
    return 0;
}