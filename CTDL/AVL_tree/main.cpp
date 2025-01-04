#include <bits/stdc++.h> 

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(NULL), right(NULL), height(1) {}
};

int height(Node* h){
    return (h != NULL) ? h->height : 0;  
}

Node* leftrotate(Node* y){
    Node* x = y->right;
    Node* tp = x->left;

    //perform rotation
    x->left = y;
    y->right = tp;

    //update height
    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

Node* rightrotate(Node* x){
    Node* y = x->left;
    Node* tp = y->right;

    //perform rotation
    y->right = x;
    x->left = tp;

    //update height
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return y;
}


int getbalance(Node* h){
    return (h != NULL) ? height(h->left) - height(h->right) : 0;
}

Node* inserttree(Node* n, int k){
    if(n == NULL)
        return new Node(k);
    if(k < n->key)
        n->left = inserttree(n->left, k);
    else if(k > n->key)
        n->right = inserttree(n->right, k);
    else 
        return n;
    
    //update height of node 
    n->height = 1 + std::max(height(n->left), height(n->right));

    int balance = getbalance(n);
    //check 4 case
    
    //left case
    if(balance > 1 && k < n->left->key)
        return rightrotate(n);
    //right case
    if(balance < -1 && k > n->right->key)
        return leftrotate(n);
    //left right case
    if(balance > 1 && k > n->left->key){
        n->left = leftrotate(n->left);
        return rightrotate(n);
    }
    //right left case
    if(balance < -1 && k < n->right->key){
        n->right = rightrotate(n->right);
        return leftrotate(n);
    }

    return n;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    std::cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}


int main(){
    Node *root = nullptr; 
    
    // Constructing tree given in the above figure 
    root = inserttree(root, 10); 
    root = inserttree(root, 20); 
    root = inserttree(root, 30); 
    root = inserttree(root, 40); 
    root = inserttree(root, 50); 
    root = inserttree(root, 25); 
    
    /* The constructed AVL Tree would be 
              30 
            /   \ 
          20     40 
         /  \      \ 
       10   25     50 
    */
    std::cout << "Preorder traversal : \n"; 
    preOrder(root); 
    
    return 0; 

}
