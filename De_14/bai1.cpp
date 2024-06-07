#include<iostream>

using namespace std;

void nhap(int a[], int n){
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
}

void xuat(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<",";

        
    }
}

void Dem(int a[], int n, int b[], int m){
    int dem = 0;
    int j = 0;
    int i = 0;
    while(i<m){
        if(b[i]>a[j] && j<n){
            dem++;
            j++;
        }
        else{
            j = 0;
            cout<<dem<<" ";
            dem = 0;
            i++;
        }
    }
}
int main(){
    int a[] = {1,6,9,13,18,18};
    int b[] = {2,3,8,13,15,21,25};  
    //cout<<a[7];
    //xuat(a,n);
    //cout<<endl;
    //xuat(b,m);
    //cout<<endl;
    Dem(a,6,b,7);
    return 0;
}