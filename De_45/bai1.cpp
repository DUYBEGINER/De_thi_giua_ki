#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int loaibo(int n){
    int tmp = 0, tmp1, tmp2;
    int sum = 0;
    while(n>0){
        tmp1 = n%10;
        n = n/10;
        tmp2 = n%10;
        if(tmp1<tmp2){
            tmp = tmp2;
        }else if(tmp == 0){
            tmp = tmp1;
        }
        sum = sum*10 + tmp1;
    }
    int n_new = 0;
    int tmp3;
    while(sum>0){
        tmp3 = sum%10;
        if(tmp3!=tmp)   n_new = n_new*10 + tmp3;
        sum = sum/10;
    }
    return n_new;
}
int main(){
    int n;
    cin>>n;
    cout<<loaibo(n);
    return 0;
}
