#include<iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
    for(int row = 0; row<=x; row++){
        if(arr[row][y] == 1){
            return false;
        }
    }
    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(arr[row][col] == 1) return false;
        row--;
        col--;
    }

    row = x;
    col = y;
    while(row>=0 && col<n){
        if(arr[row][col] == 1) return false;
        row--;
        col++;
    }
    return true;
}

bool Queen(int **arr, int x ,int n){
    if(x >= n) return true;
    for(int i = 0; i<n; i++){
        if(isSafe(arr, x, i, n)){
            arr[x][i] = 1;
            if(Queen(arr, x+1, n)){
                return true;
            }
            arr[x][i] = 0;
        } 
    }
    return false;
}

int main(){
    int n;cin>>n;
    int **a = new int*[n];
    for(int i = 0; i<n; i++){
        a[i] = new int[n];
        for(int j = 0; j<n; j++){
            a[i][j] = 0;
        }
    }

    if(Queen(a, 0, n)){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Not Possible";
    }
    return 0;
}