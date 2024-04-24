#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int loaibo(int n){
    int dem=0;
    int *A= new int[1000];  //lưu từng chữ số của n vào mảng A
    int sum=0;
    while(n>0){
        A[dem] = n%10;
        dem++;
        n = n/10;
    }   
    for(int i = dem-1; i > 0; i--){
        if(A[i]>A[i-1]){
            for(int j=i; j<dem-1; j++)
                A[j]=A[j+1];
            dem--;
            break;
        }
    }
    for(int i=dem-1; i>=0; i--){
        sum = sum*10 + A[i];
    }
    delete[] A;
    return sum;
}
int main(){
    int n;
    cin>>n;
    cout<<loaibo(n);
    return 0;
}
