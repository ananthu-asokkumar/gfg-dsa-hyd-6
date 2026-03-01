#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool searchInBst(Node* root, int target) {
    if (root == NULL) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    if (root->data < target) {
        return searchInBst(root->right, target);
    }

    return searchInBst(root->left, target);
}

// TC: O(H)
// AS: O(H)
Node* insertInBst(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (root->data == value) {
        return root;
    }

    if (root->data < value) {
        root->right = insertInBst(root->right, value);
    } else {
        root->left = insertInBst(root->left, value);
    }

    return root;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(9);
    root->right = new Node(11);
    root->right->right = new Node(12);

    root = insertInBst(root, 7);

    cout << searchInBst(root, 7) << endl;
    cout << searchInBst(root, 4) << endl;


}
 