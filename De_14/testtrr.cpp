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
        else if(x<t->key) { // Thêm dấu ngoặc nhọn ở đây
            AddNode(t->pLeft,x);
        } else { // Thêm dấu ngoặc nhọn ở đây
            AddNode(t->pRight,x);
        }
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

void Timthemang(TREE &pHuy, TREE &p){
    if(p->pLeft){
      Timthemang(pHuy, p->pLeft);  
    }else{
        pHuy->key = p->key;
        pHuy = p;
        p = p->pRight;
    }
}

void xoa_Node(TREE &t, int x){
    //cout<<"xoa node: "<<t->key;
    if(t!=NULL){
            TNODE *pHuy = t;
            TNODE *parent = t;
            if(t->pLeft==NULL && t->pRight==NULL){
                delete pHuy;
            }else if(t->pLeft==NULL){
                 t = t->pRight;
            }
            else if(t->pRight==NULL)
                 t = t->pLeft;
            else 
            Timthemang(pHuy,t->pRight);
            delete pHuy;
            //pHuy =  NULL;
    }
}
void ShowList(TREE t){
    if(t!=NULL){
        cout<<t->key<<" ";
        ShowList(t->pLeft);
        ShowList(t->pRight);
    }
}
void delete_friendlyNumber(TREE &t){
    if (t != NULL) {
        while(is_friendlyNumber(t->key)) {
            //cout<<"Xoa lan: ";
            xoa_Node(t, t->key);
            //ShowList(t);
        }
        delete_friendlyNumber(t->pLeft);
        delete_friendlyNumber(t->pRight);
    }
}


int main(){
    TREE T;
    InitTree(T);
    int n,a,b;
    cin>>n;
    while(n>0){
        cin>>a;
        AddNode(T,a);
        n--;
    }
    ShowList(T);
    cout<<endl;
    delete_friendlyNumber(T);
    cout<<endl;
    if(IsEmptyTree(T))
    cout<<"Empty";
    else{
        cout<<"no";
    }
    //ShowList(T);
    return 0;
}