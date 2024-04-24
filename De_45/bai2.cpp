#include<iostream>
#include <unordered_set>
using namespace std;

typedef struct TNODE{
    int key;
    struct TNODE *pLeft;
    struct TNODE *pRight; 
}*TREE;

void Init_Node(TNODE* &T){
    T = NULL;
}

bool Lucky_Number(int n){
    unordered_set<int> seen; 
    while(n!=1 && seen.find(n) == seen.end()){
        seen.insert(n);
        int sum=0;
        while(n>0){
            int tmp = n%10;
            sum += tmp*tmp;
            n /= 10;
        }
        n = sum;
    }
    return n==1;
}
int dem = 0;

int dem_lucky(TREE &t){
    if(t){
        if(((t->pLeft==NULL) && (t->pRight==NULL)) && (Lucky_Number(t->key))){
                return 1;
        }else{
            return dem_lucky(t->pLeft)+dem_lucky(t->pRight);
        }
    }else{
        return 0;
    }
 }

// int dem(TREE t){
//     if(t){
//         int d = dem(t->pLeft) + dem(t->pRight) ;
//         if()
//     }
// }
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
void LNR(TREE t){
    if(t != NULL)
    {
        LNR(t->pLeft);
        cout<<t->key<<"  ";
        LNR(t->pRight);
    }
}

int main(){
    TREE t;
    Init_Node(t);
    int A[100];
    int n;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>A[i];
        AddNode(t,A[i]);
    }
    LNR(t);
    cout<<endl;
    cout<<dem_lucky(t)<<endl;
    return 0;
}