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

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

// TC: O(n + m)
// AS: O(n + m)
Node* merge2SortedLinkedLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    if (head1->data <= head2->data) {
        head1->next = merge2SortedLinkedLists(head1->next, head2);
        return head1;
    } else {
        head2->next = merge2SortedLinkedLists(head1, head2->next);
        return head2;
    }
}

int main() {

    Node* head1 = new Node(0);
    head1 = insertAtEnd(head1, 1);
    head1 = insertAtEnd(head1, 1);
    head1 = insertAtEnd(head1, 2);
    head1 = insertAtEnd(head1, 4);
    head1 = insertAtEnd(head1, 6);

    Node* head2 = new Node(1);
    head2 = insertAtEnd(head2, 3);
    head2 = insertAtEnd(head2, 6);
    head2 = insertAtEnd(head2, 10);

    Node* result = merge2SortedLinkedLists(head1, head2);
    print(result);
}
