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

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// TC: O(n)
// AS: O(n/k)
Node* kReverseLinkedList(Node* head, int k) {
    if (head == NULL || k <= 1) {
        return head;
    }

    int cnt = 0;
    Node* curr = head;
    Node* prev = NULL;

    Node* last = head;

    while (curr != NULL && cnt < k) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        cnt++;
    }

    last->next = kReverseLinkedList(curr, k);
    return prev;
}

int main() {

    Node* head = new Node(1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 7);
    head = insertAtEnd(head, 8);
    head = insertAtEnd(head, 9);

    head = kReverseLinkedList(head, 3);

    print(head);
}
