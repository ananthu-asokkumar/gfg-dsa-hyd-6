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

void getPathUtil(Node* root, int value, vector<int> &currPath, vector<int> &resPath) {
    if (root == NULL || resPath.size() > 0) {
        return;
    }

    currPath.push_back(root->data);
    if (root->data == value) {
        resPath = currPath;
        return;
    }

    getPathUtil(root->left, value, currPath, resPath);
    getPathUtil(root->right, value, currPath, resPath);
    currPath.pop_back();
}

vector<int> getPath(Node* root, int value) {

    vector<int> currPath;
    vector<int> resPath;

    getPathUtil(root, value, currPath, resPath);

    return resPath;
}

// TC: O(n)
// AS: O(H)
int lca(Node* root, int n1, int n2) {

    vector<int> path1 = getPath(root, n1);
    vector<int> path2 = getPath(root, n2);

    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
        i++;
    }
    return path1[i - 1];
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

    cout << lca(root, 40, 50) << endl; // 20
    cout << lca(root, 40, 80) << endl; // 20
    cout << lca(root, 60, 50) << endl; // 10
    cout << lca(root, 20, 80) << endl; // 20
}
