void xoaArm(LIST &T){
    NODE *p= T.pHead, *q;
    while(p!=NULL && Check_Armstrong(p->key)){
        T.pHead = p->pNext;
        delete p;
        p = T.pHead;
    }
    while(p!=NULL && p->pNext!=NULL){
        if(checkarmtrong(p->pNext->key)){
            q = p->next;
            p->next = q->next;
            delete q;
        }else{
            p = p->next
        }
    }

}