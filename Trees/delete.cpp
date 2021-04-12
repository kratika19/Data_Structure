#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    struct Node *leftSide, *rightSide;
};

Node *newNode(int item) {
    Node *temp = new Node;
    temp->key = item;
    temp->leftSide = temp->rightSide = NULL;
    return temp;
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->leftSide);
        cout << root->key << ", ";
        inorderTraversal(root->rightSide);
    }
}

Node *insertNewNode(Node *node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->leftSide = insertNewNode(node->leftSide, key);
    else
        node->rightSide = insertNewNode(node->rightSide, key);
    return node;
}

Node *deleteNode(Node *root, int k) {
    if (root == NULL)
        return root;
    if (root->key > k) {
        root->leftSide = deleteNode(root->leftSide, k);
        return root;
    } else if (root->key < k) {
        root->rightSide = deleteNode(root->rightSide, k);
        return root;
    }

    if (root->leftSide == NULL) {
        Node *temp = root->rightSide;
        delete root;
        return temp;
    } else if (root->rightSide == NULL) {
        Node *temp = root->leftSide;
        delete root;
        return temp;
    } else {
        Node *successiveParent = root;
        Node *successive = root->rightSide;
        while (successive->leftSide != NULL) {
            successiveParent = successive;
            successive = successive->leftSide;
        }
        if (successiveParent != root)
            successiveParent->leftSide = successive->rightSide;
        else
            successiveParent->rightSide = successive->rightSide;
        root->key = successive->key;
        delete successive;
        return root;
    }
}

int main() {
    Node *root = NULL;
    root = insertNewNode(root, 100);
    root = insertNewNode(root, 60);
    root = insertNewNode(root, 40);
    root = insertNewNode(root, 80);
    root = insertNewNode(root, 140);
    root = insertNewNode(root, 120);
    root = insertNewNode(root, 160);

    cout << "Inorder traversal of the binary tree :" << endl;
    inorderTraversal(root);
    cout << endl << endl;

    cout << "Remove node with value 40" << endl;
    root = deleteNode(root, 40);
    cout << "Inorder traversal of the newly generated binary tree :" << endl;
    inorderTraversal(root);
    cout << endl << endl;

    cout << "Remove node with value 60" << endl;
    root = deleteNode(root, 60);
    cout << "Inorder traversal of the newly generated binary tree :" << endl;
    inorderTraversal(root);
    cout << endl << endl;

    cout << "Remove node with value 100" << endl;
    root = deleteNode(root, 100);
    cout << "Inorder traversal of the newly generated binary tree :" << endl;
    inorderTraversal(root);
    cout << endl << endl;

    return 0;
}