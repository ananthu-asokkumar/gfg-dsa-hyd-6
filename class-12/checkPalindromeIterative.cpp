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

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

// TC: O(n)
// AS: O(1)
Node* getMiddle(Node* head) {
    if (head == NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// TC: O(n)
// AS: O(1)
bool checkPalindrome(Node* head) {
    if (head == NULL) {
        return true;
    }

    Node* mid = getMiddle(head);

    Node* head1 = head;
    Node* head2 = mid->next;
    mid->next = NULL;

    head2 = reverse(head2);

    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
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
