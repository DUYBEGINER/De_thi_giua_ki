#include <iostream>
#include <vector>

using namespace std;

typedef struct TNODE{
    int key;
    struct TNODE *pLeft;
    struct TNODE *pRight;
} *TREE;

void InitTree(TREE &t){
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
    if(a==0 || b==0){
        return a+b;
    }
    while(a!=b){
        if(a>b){
            a = a-b;
        }else{
            b = b-a;
        }
    }
    return a;
}

//Kiểm tra số thân thiện
bool is_friendlyNum(int n){
    int value = n;
    int tmp;
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

void deleteNode(TREE &T, int key) {
    if(T == NULL) return;
    else{
        if(key < T->key){
            deleteNode(T->pLeft, key);
        }else if(key > T->key){
            deleteNode(T->pRight, key);
        }else{   // key == T->key
            TNODE *pHuy = T;  
            //Nếu như nhanh trái bằng NULL -> đây là cây con phải
            if(T->pLeft == NULL){
                T = T->pRight;
            }else if(T->pRight == NULL){
                T = T->pLeft;
            }
            else{
                TNODE *themang = T->pRight;
                Timthemang(pHuy,themang);
            }
            delete pHuy;
        }
        }
}



// void Search_friendlyNum(TREE T, vector<int> &a){
//     if(T!=NULL){
//         if(is_friendlyNum(T->key)){
//             a.push_back(T->key);
//         }
//         Search_friendlyNum(T->pLeft,a);
//         Search_friendlyNum(T->pRight,a);
//     }
// }

void delete_friendlyNumber(TREE &t){
   if(t!=NULL){
    if(is_friendlyNum(t->key)){
           deleteNode(t,t->key);
       }
       delete_friendlyNumber(t->pLeft);
       delete_friendlyNumber(t->pRight);
       
   }
}


void ShowList(TREE t){
    if(t!=NULL){
        cout<<t->key<<" ";
        ShowList(t->pLeft);
        ShowList(t->pRight);
    }
}

int main(){
    TREE T;
    InitTree(T);
    int n,a,b;
    cout<<"Nhap so luong node:";
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
    ShowList(T);

    return 0;
}