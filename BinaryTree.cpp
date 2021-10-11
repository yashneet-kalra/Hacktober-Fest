#include <iostream>
using namespace std;

struct node{
    int value;
    node *left;
    node *right;
};

class btree{
public:
    btree():
    void insert(int key);  //insert a node
    node *search(int key); //search a value
    void print();          //print the tree
    node *root;            //pointer to root element
};

btree::btree(){            //constructor
    root = NULL;
}

void btree::insert(int key, node *left){

    if(key < leaf->value){
        if(leaf->left !=NULL){
            insert(key, leaf->left);
        }else{
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->leeft = NULL;
            leaf->left->right = NULL;
        }
    }else if(key >= leaf->value){
        if(leaf=>right != NULL){
            insert(key, leaf->right);
        }else{
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NUll;
        }
    }
}

void btree::insert(int key){
    if(root != NULL){
        insert(key, root);
    }else{
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *btree::search(int key, node *leaf){
    if(leaf != NULL){
        if(key == leaf->value){
            return leaf;
        }
        if(key < leaf->value){
            return search(key, leaf->left);
        }else{
            return search(key, leaf->right);
        }
    }else{
        return NULL;
    }
}

node *btree::search(int key){
    return search(key, root);
}

void btree::print(node *leaf){
    if(leaf != NULL){
        print(leaf->left);
        cout << leaf->value << ",";
        print(leaf->right);
    }
}

int main(){
    
    //btree tree;
    btree *tree = new btree();

    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);

    tree->print();
}


/*
        10
       /   \
       6   14
      / \  / \
      5 8  11  18
*/