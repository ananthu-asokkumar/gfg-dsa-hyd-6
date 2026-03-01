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

// TC: O(H)
// AS: O(1) (tail recursion)
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
// AS: O(1)
bool searchInBstIterative(Node* root, int target) {
    while (root != NULL) {
        if (root->data == target) {
            return true;
        }
        if (root->data < target) {
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return false;
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

    cout << searchInBst(root, 6) << endl;
    cout << searchInBstIterative(root, 6) << endl;

    cout << searchInBst(root, 7) << endl;
    cout << searchInBstIterative(root, 7) << endl;


}
 