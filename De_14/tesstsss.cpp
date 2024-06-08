#include <iostream>
using namespace std;

typedef struct TNODE{
    int key;
    TNODE *pR;
    TNODE *pL;
}*TREE;
typedef struct TNODE* node;
int UCLN( int a, int b){
   
    while (a*b!=0){
        if (a>b) a%=b;
        else b%=a;
    }
    return a+b;
}
bool NumberFriend(int n){
    int a=n;
    int b=0;
    while (n>0){
        int x= n%10;
        b= b*10+x;
        n/=10;
    }
    if (UCLN(a,b)==1) {
        return 1;
    }
    else return 0;
}
void Init(TREE &t){
    t=NULL;
}
node CreateNode(TREE &t, int x){
    node p= new TNODE;
    if (p==NULL) exit(1);
    p->key=x;
    p->pL=NULL;
    p->pR=NULL;
    return p;
}
void AddNode(TREE &t, int x){
    if (t!= NULL){
        if (x==t->key) return ;
        else if ( x<t->key) AddNode(t->pL,x);
            else AddNode(t->pR,x); 
    }
    else {
        node p=CreateNode(t,x);
        t=p;
    }
}
void TimTheMang(TREE &pHuy, TREE &t){
    if (t->pL) {
        TimTheMang(pHuy,t->pL);
    }
    else {
        pHuy->key=t->key;
        pHuy=t;
        t=t->pR;
    }
}
void DelNode (TREE &t){
    if (t!= NULL){
        DelNode(t->pL);
        DelNode(t->pR);
        if (NumberFriend(t->key)) {
            node pHuy=t;
            if (t->pL==NULL) t=t->pR;
            else if (t->pR==NULL) t=t->pL;
            else TimTheMang(pHuy,t->pR);
            delete pHuy;
        }
    }
    
}
void ShowFriends(TREE t){
    if (t!=NULL){
        ShowFriends(t->pL);
        if (NumberFriend(t->key)) cout <<t->key<<" ";
        ShowFriends(t->pR);
    }
}

void ShowList(TREE t){
    if (t!=NULL){
        ShowList(t->pL);
        cout <<t->key<<" ";
        ShowList(t->pR);
    }
}


int main (){
    TREE t;
    Init(t);
    int n; cin >>n;
    for ( int i=0; i<n;i++){
        int tmp; cin >>tmp;
        AddNode(t,tmp);
    }
    ShowFriends(t);
    cout <<endl;
    DelNode(t);
    ShowList(t);
    return 0;
}