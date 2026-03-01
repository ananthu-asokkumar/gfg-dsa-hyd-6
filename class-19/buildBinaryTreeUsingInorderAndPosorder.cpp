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
void postorderTrav(Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTrav(root->left);
    postorderTrav(root->right);
    cout << root->data << " ";
}

// TC: O(n)
// AS: O(H)
void inorderTrav(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTrav(root->left);
    cout << root->data << " ";
    inorderTrav(root->right);
}


Node* constructUtil(vector<int> &inorder, vector<int> &postorder,
                    int inStart, int inEnd, int &postIndex) {

    if (inStart > inEnd) {
        return NULL;
    }

    Node* root = new Node(postorder[postIndex]);
    postIndex--;

    int index = inStart;
    for (int i = inStart + 1; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            index = i;
            break;
        }
    }
    // right: [index + 1 .. inEnd]
    root->right = constructUtil(inorder, postorder, index + 1, inEnd, postIndex);

    // left: [inStart .. index - 1]
    root->left = constructUtil(inorder, postorder, inStart, index - 1, postIndex);
    
    return root;
}

// TODO: Build a binary tree using inorder and preorder.

// TC: O(n^2)
// AS: O(n) OR
//     O(H) where H is the height of the OUTPUT tree.
Node* constructBinaryTreeUsingInorderAndPostorder(vector<int> inorder, vector<int> postorder) {

    int n = inorder.size();
    int postIndex = n - 1;

    return constructUtil(inorder, postorder, 0, n - 1, postIndex);
}

int main() {

    Node* root = constructBinaryTreeUsingInorderAndPostorder(
        {4, 8, 2, 5, 1, 6, 3, 7},
        {8, 4, 5, 2, 6, 7, 3, 1});
    
    inorderTrav(root);
    cout << endl;
    postorderTrav(root);
}
