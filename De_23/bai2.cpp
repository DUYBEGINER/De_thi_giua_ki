#include <iostream>
#include<cmath>

using namespace std;

typedef struct Node{
    int key;
    Node* pNext;
}NODE;

typedef struct List{
    Node* pHead;
    Node* pTail;
}LIST;

bool Check_Armstrong(int n) { 
    int expon=0;
    int sum = 0;
    int tmp = n;
    while(tmp>0){
        expon++;
        tmp = tmp/10;
    }
    tmp = n;
    while(tmp>0){
        sum = sum + pow(tmp%10,expon);
        tmp /= 10;
    }
    if(sum == n) return true;
    else return false;
}

void Xoa_Armstrong(LIST &L) {
    NODE *p = L.pHead, *q;
    // Xóa các nút đầu tiên có giá trị là số Armstrong
    while (p != NULL && Check_Armstrong(p->key)) {
        L.pHead = p->pNext;
        delete p;
        p = L.pHead;
    }

    // Xóa các nút còn lại có giá trị là số Armstrong
    while (p != NULL && p->pNext != NULL) {
        if (Check_Armstrong(p->pNext->key)) {
            q = p->pNext;
            p->pNext = q->pNext;
            delete q;
        } else {
            p = p->pNext;
        }
    }
}

void Init(LIST &T){
    T.pHead = NULL;
    T.pTail = NULL;
}


void Show(LIST t){
    NODE *p = t.pHead;
    while(p!=NULL){
        cout<<p->key<<" ";
        p = p->pNext;
    }
}


NODE* CreateNode(int x){
     NODE* p = new NODE;
     p->key = x;
     p->pNext = NULL;
     return p;
}

void Insert(LIST &T, int x) {
    NODE *p =CreateNode(x);
    if(T.pHead==NULL){
        T.pHead = p;
        T.pTail  = p;
    }else{
        T.pTail->pNext = p;
        T.pTail = p;
    }
}


int main(){
    LIST T;
    Init(T);
    int n;
    cout<<"Nhap so luong node: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        Insert(T,x);
    }
    cout<<"Danh sach truoc khi xoa so Armstrong: ";
    Show(T);
    cout<<endl;
    cout<<"Danh sach sau khi xoa so Armstrong: ";
    Xoa_Armstrong(T);
    if(T.pHead) Show(T);
    else cout<<"NULL";
    return 0;
}