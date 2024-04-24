#include<iostream>
#include<cmath>
using namespace std;

int loaibo(int n){
    int sum=0;
    int *A= new int[1000];  //lưu từng chữ số của n vào mảng A
    int index=0, timthay = 0;;
    int value = n;
    int k = 0;
    while(n>0){
        k++;
        n = n/10;
    }
    int i =0;
    while(value>0){
        A[index]=value/pow(10,(k-1-i));
        int tmp = pow(10,k-1-i);
        value = value % tmp;
        if(index>=1){
            if((A[index-1] > A[index])&&(timthay==0)){
                timthay = 1;
                index++;
                i++;
                continue;
            }else{
                sum = sum*10+A[index-1];
            }
        }
        index++;
        i++;
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
