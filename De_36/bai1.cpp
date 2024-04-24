#include <iostream>
#include <cmath>
using namespace std;

bool laSNT(int n){
    if(n<=1)
        return 0;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int test;
    cin>>test;
    while(test>0){
        int n;
        cin>>n;
        for(int i=2; i<=n/2; i++) {
            if((laSNT(i))&&(laSNT(n-i))){
                cout<<n-i<<"+"<<i<<endl;
                break;
            }
        }
        test--;
    }
    return 0;
}