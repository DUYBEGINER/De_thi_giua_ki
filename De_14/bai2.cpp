#include <iostream>

using namespace std;

typedef struct TNODE{
    int key;
    struct TNODE *pLeft;
    struct TNODE *pRight;
} *TREE;

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
        if(p == NULL){
            return;
        }else{
            t=p; 
        }
    }
}

int ucln(int a, int b){
    if(b==0) return a;
    return ucln(b,a%b);
}

bool is_friendlyNumber(int n){
    int value = n;
    int tmp = 0;
    int sum = 0;
    while(n>0){
        tmp = n%10;
        sum = sum*10 + tmp;
        n = n/10;
    }
    if(ucln(value,sum) == 1)
        return 1;
    else 
        return 0;
}

void Xoa_node(TREE &t){
    if(t!=NULL){
        if((t->pLeft==NULL) && (t->pRight==NULL)){
            
        }
    }
}
void xoa_friendlyNumber(TREE &t){
    
}

int main(){
    int a;
    cin>>a;
    cout<<is_friendlyNumber(a);
    return 0;
}