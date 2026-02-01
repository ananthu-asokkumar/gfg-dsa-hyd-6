#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtEnd(Node* head, int value) {
    if (head == NULL) {
        insertAtBeginning(head, value);
        return head;
    }

    Node* newNode = new Node(value);
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* checkPalindromeUtil(Node* curr, Node* head, bool &result) {
    if (curr == NULL) {
        return head;
    }

    Node* toCompare = checkPalindromeUtil(curr->next, head, result);
    if (curr->data != toCompare->data) {
        result = false;
    }
    return toCompare->next;
}

// TC: O(n)
// AS: O(n)
bool checkPalindrome(Node* head) {
    bool result = true;
    checkPalindromeUtil(head, head, result);
    return result;
}

int main() {

    Node* head = new Node(1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);

    cout << checkPalindrome(head) << endl;

    head = insertAtEnd(head, 1);

    cout << checkPalindrome(head) << endl;
}
