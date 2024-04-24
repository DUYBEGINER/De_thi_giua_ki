#include<iostream>
using namespace std;


typedef struct TNODE
{
    int key;
    struct TNODE *pLeft;
    struct TNODE *pRight;
}*TREE;

struct TNODE root;

int InitTree(TREE &t){
    t = NULL;
}

int IsEmptyTree(TREE t){
    return (t == NULL);
}

TNODE *CreateNode(int x){
    TNODE *p = new TNODE;
    if(p==NULL){
        exit(1);
    }
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void AddNode(TREE &t, int x){
    if(t!=NULL){
        if(x==t->key)
            return;
        else if(x<t->key)   
            AddNode(t->pLeft,x);
            else
            AddNode(t->pRight,x);
    }
    else{
        TNODE *p =  CreateNode(x);
        t=p;  
    }
}

bool isPalinromic(int n){
    int value = n;
    int sum=0;
    int  temp=0;
    while(n>0){
        temp = n%10;
        sum = sum*10 +temp;
        n = n/10;
    }
    if(sum==value)
        return 1;
    else
        return 0;
}

int dem = 0;
int Dem_Palinromic(TREE  t){
    if(t==NULL)
        return 0;
    if (t != NULL){
        if(isPalinromic(t->key))
            dem++;
        Dem_Palinromic(t->pLeft);
        Dem_Palinromic(t->pRight);
    }
}
int main(){
    TREE p;
    InitTree(p);
    int n;
    cin>>n;
    int  a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        AddNode(p,a[i]);
    }
    Dem_Palinromic(p);
    cout<<"So luong cac so palindromic la: "<<dem<<endl;
}