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
// AS: O(H)
int height(Node* root, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return 0;
    }
    if (heights.find(root) != heights.end()) {
        return heights[root];
    }

    int leftHeight = height(root->left, heights);
    int rightHeight = height(root->right, heights);

    heights[root] = 1 + max(leftHeight, rightHeight);
    return heights[root];
}

int diameterUtil(Node* root, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return 0;
    }

    int lh = height(root->left, heights);
    int rh = height(root->right, heights);
    int result = lh + rh;

    int leftSubtreeDiam = diameterUtil(root->left, heights);
    int rightSubtreeDiam = diameterUtil(root->right, heights);

    return max({lh + rh, leftSubtreeDiam, rightSubtreeDiam});
}

// TC: O(n)
// AS: O(n)
int diameter(Node* root) {
    unordered_map<Node*, int> heights;
    return diameterUtil(root, heights);   
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

    cout << diameter(root) << endl;
}
