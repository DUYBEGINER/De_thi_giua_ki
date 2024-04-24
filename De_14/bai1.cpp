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
    int c[m]= {0};
    int j = 0;
    int i = 0;
    while(i<m){
        if(b[i]>a[j] && j<n){
            j++;
        }
        else{
            c[i] = j;
            i++;
        }
    }
    for(int k=0; k<m-1; k++){
        cout<<c[k]<<",";
    }
    cout<<c[m-1];
}
int main(){
    int  n, m;
    cin>>n;
    cin>>m;
    int a[n];
    int b[m];
    nhap(a,n);
    nhap(b,m);
    //xuat(a,n);
    //cout<<endl;
    //xuat(b,m);
    //cout<<endl;
    Dem(a,n,b,m);
    return 0;
}