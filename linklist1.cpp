#include<iostream>

using namespace std;

typedef struct Node{

    int key;
    Node *pNext;
}NODE;

typedef struct List{
    NODE *pHead;
    NODE *pTail;
}LIST;

void Init(LIST &L){
    L.pHead = NULL;
    L.pTail = NULL;
}

bool IsEmpty(LIST L){
    return (L.pHead == NULL);
}

NODE* CreateNode(int x){
    NODE *p = new NODE;
    if(p == NULL){
        return NULL;
    }
    p->key = x;
    p->pNext  = NULL;
    return p;

}

void Show(LIST L){
    NODE *p = L.pHead;
    while(p!=NULL){
        cout<<p->key<<" ";
        p = p->pNext;
    }

}

//Insert first
void Insert(LIST &L, int x){
    NODE *p = CreateNode(x);
    if(p == NULL){
        return;
    }
    if(L.pHead == NULL){
        L.pHead = p;
        L.pTail = p;
    }else{
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

void CreateList(LIST &T, int n){
    int n;
    cout<<"Nhap so luong node: ";
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        Insert(T,x);
    }
}


int main(){

    return 0;
}