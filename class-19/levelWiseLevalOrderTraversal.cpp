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
vector<vector<int>> levelWiseLevelOrder(Node* root) {

    if (root == NULL) {
        return {};
    }

    vector<vector<int>> result;
    queue<Node*> q;

    q.push(root);

    while(!q.empty()) {
        int sz = q.size();

        vector<int> currentLevel;
        for (int i = 0; i < sz; i++) {
            Node* current = q.front();
            q.pop();

            currentLevel.push_back(current->data);

            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        result.push_back(currentLevel);
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

    vector<vector<int>> result = levelWiseLevelOrder(root);
    
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
