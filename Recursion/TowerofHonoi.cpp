#include<iostream>
using namespace std;

void TowerOfHonoi(int n, char src, char des, int helper){
    if(n == 0) return;
    TowerOfHonoi(n-1, src, helper, des);
    cout<<"Move from "<<src<<" to "<<des<<endl;
    TowerOfHonoi(n-1, helper, des, src);
}

int main(){
    TowerOfHonoi(3, 'A', 'C', 'B');
    return 0;
}