#include<iostream>
using namespace std;
void loc(int a[7][6], int i, int j){
    a[i][j]=1;
    if (i>0 && a[i-1][j]==-1) loc(a,i-1,j);
    if (i<6 && a[i+1][j]==-1) loc(a,i+1,j);
    if (j>0 && a[i][j-1]==-1) loc(a,i,j-1);
    if (j<5 && a[i][j+1]==-1) loc(a,i,j+1);
}

int count(int a[7][6],int n, int m){
    int dem=0;
    for ( int i=0;i<n;i++){
        for ( int j=0; j<m;j++){
            if (a[i][j]==-1) {
                dem++;
                loc(a,i,j);
            }
        }
    }
    return dem;
}


int main (){
    int n =7, m=6;
    int a[7][6]={
        {-1, -1, 0, 0, 0, -1},
        {-1, -1, 0, 0, 0,  0},
        {-1,  0, 0, 0, 0,  0},
        {-1, -1, 0, 0, 0, -1},
        { 0,  0, 0, 0, 0, -1},
        {-1,  0,-1,-1,-1, -1},
        {-1,  0, 0, 0, 0, -1},
    };
    cout <<"So thanh phan lien thong: "<< count(a,7,6)<<endl;
    for ( int i=0; i<7;i++){
        for ( int j=0;j<6;j++){
            cout <<a[i][j]<<"\t";
        }
        cout <<endl;
    }
    return 0;
}