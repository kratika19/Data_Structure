#include <bits/stdc++.h>

using namespace std;

class node {
public:
    node *left;
    node *right;
    int data;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insertinBST(node *root, int i) {

    if (root == NULL) {
        return new node(i);
    }

    if (i <= root->data) {
        root->left = insertinBST(root->left, i);
    }

    if (i >= root->data) {
        root->right = insertinBST(root->right, i);
    }

    return root;
}

node *build() {
    int d;
    cin >> d;
    node *root = NULL;
    while (d != -1) {
        root = insertinBST(root, d);
        cin >> d;
    }
    return root;
}


void InOrder(node *root) {
    if (root == NULL) {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PreOrder(node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(node *root) {
    if (root == NULL) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";

}



int main() {
    node *root = NULL;
    root = build();
    PostOrder(root);
    InOrder(root);
    PreOrder(root);

}