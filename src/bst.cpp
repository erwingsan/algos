#include <iostream>

using namespace std;

struct BSTNode{
    BSTNode(int k):key(k), p(0), right(0), left(0){};
    BSTNode *p;
    BSTNode *right;
    BSTNode *left;
    int key;
};

void bst_insert(BSTNode **head, int key);
void printbst(BSTNode *h);

BSTNode* maximum(BSTNode *h);
BSTNode* minimum(BSTNode *h);

BSTNode* search(BSTNode *h, int key);
BSTNode* successor(BSTNode *node);

void transplant(BSTNode *h, BSTNode *oldn, BSTNode *newn);
void bst_delete(BSTNode *h, BSTNode *node);

int mainbst(){
    
    BSTNode *head = 0;
    cout << "BST size: ";
    int s;
    cin >> s;
    
    while(s > 0){
        int e;
        cin >> e;
        bst_insert(&head, e);
        --s;
    }
    
    printbst(head);
    cout << endl;
    
    BSTNode *e1 = search(head, 18);
    
    cout << "search for 13  - Parent: " << e1->p->key <<endl;
    
    BSTNode *e2 = successor(e1);
    
    cout << "search for succesor of 13: " << e2->key <<endl;
    
    bst_delete(head, e1);
    
    printbst(head);
    cout << endl;
    
//    bst_delete(head, e2);
//    
//    printbst(head);
//    cout << endl;
//    
//    bst_delete(head, head);
//    
//    printbst(head);
//    cout << endl;
    
    return 0;

}


void bst_insert(BSTNode **head, int key){
    
    BSTNode *e = new BSTNode(key);
    //head case
    if(*head == 0){
        *head = e;
        return;
    }
    
    
    BSTNode *p = 0;
    BSTNode *c = *head;
    
    while(c != 0){
        p = c;
        if(c->key > key){
            c = c->left;
        }else{
            c = c->right;
        }
    }
    
    e->p = p;
    if(p->key > key)
        p->left = e;
    else
        p->right = e;
    
}

BSTNode* search(BSTNode *h, int key){

    if(h == 0 || h->key == key){
        return h;
    }
    
    if(h->key > key)
        return search(h->left, key);
    else
        return search(h->right, key);
    
//    while(c != 0 && c->key != key){
//        if(c->key > key)
//            c = c->left;
//        else
//            c = c->right;
//    }
//    
//    return c;
    
}

void transplant(BSTNode *h, BSTNode *oldn, BSTNode *newn){
    // oldn is head
    if(oldn->p == 0)
        h = oldn;
    else if(oldn->p->left == oldn)
        oldn->p->left = newn;
    else
        oldn->p->right = newn;
    
    // update parent if new node is not null
    if(newn != 0)
        newn->p = oldn->p;

}

void bst_delete(BSTNode *h, BSTNode *node){
    
    //simple cases
    if(node->left == 0)
        transplant(h, node, node->right);
    else if (node->right == 0)
        transplant(h, node, node->left);
    
    else {
        // search successor (minimum in right tree - note that minimum does not have left child!!)
        BSTNode *m = minimum(node->right);
        // 1. Minimum is right of node to delete
        if(m->p == node){
            transplant(h,node,m);
            //fix left children
            m->left = node->left;
            m->left->p = m;
        }
        else{ // 2. Minimum is far
            //transplant right child of minimum
            transplant(h, m, m->right);
            // take right child to minimum
            m->right = node->right;
            m->right->p = m;
            // transplant minimum in place
            transplant(h, node, m);
            //fix left children
            m->left = node->left;
            m->left->p = m;
        }
        
    }
    
    //free(node);
    
}

BSTNode* successor(BSTNode *node){
    
    if(node->right != 0){
        return minimum(node->right);
    }
    
    while(node->p->left != node && node->p != 0){
        node = node->p;
    }
    return node->p;
    
}

BSTNode* maximum(BSTNode *h){
    
    BSTNode *c = h;
    
    if(c == 0) {
        cout << " Empty ";
        return 0;
    }
    
    while(c->right != 0){
        c = c->right;
    }
    
    return c;
    
}

BSTNode* minimum(BSTNode *h){
    
    BSTNode *c = h;
    
    if(c == 0) {
        cout << " Empty ";
        return 0;
    }
    
    while(c->left != 0){
        c = c->left;
    }
    
    return c;
    
}

// in order
void printbst(BSTNode *e){
    
    //Parent
    if(e != 0){
        printbst(e->left);
        cout << e->key << " ";
        printbst(e->right);
    }
    
}