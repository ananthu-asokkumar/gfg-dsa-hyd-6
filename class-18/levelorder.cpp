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

// TC: O(n)
// AS: O(n)
vector<int> levelorder(Node* root) {
    if (root == NULL) {
        return {};
    }

    queue<Node*> q;
    vector<int> result;

    q.push(root);

    while(!q.empty()) {

        Node* curr = q.front();
        q.pop();

        result.push_back(curr->data);

        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
    }

    return result;
}

int main() {

    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right = new Node(30);
    root->right->right = new Node(60);

    vector<int> result = levelorder(root);
    for (int i : result) {
        cout << i << " ";
    }
}
