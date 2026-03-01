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

void pushLeft(Node* node, stack<Node*> &s) {

    while (node != NULL) {
        s.push(node);
        node = node->left;
    }
}

// TC: O(n)
// AS: O(H)
vector<int> iterativeInoredr(Node* root) {

    stack<Node*> s;

    pushLeft(root, s);
    vector<int> result;

    while (!s.empty()) {

        Node* current = s.top();
        s.pop();

        result.push_back(current->data);
        
        pushLeft(current->right, s);
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

    vector<int> res = iterativeInoredr(root);
    for (int i : res){
        cout << i << " ";
    }
}
 