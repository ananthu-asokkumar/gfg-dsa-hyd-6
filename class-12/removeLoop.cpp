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

// TC: O(n)
// AS: O(1)
void detectAndRemoveLoop(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (slow != fast) {
        return;
    }

    // if the meeting point is the head node.
    if (slow == head) {
        while (slow->next != head) {
            slow = slow->next;
        }
        slow->next = NULL;
        return;
    }

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
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

    detectAndRemoveLoop(head);
    print(head);

    head->next->next->next->next->next->next->next->next = head->next->next;
    detectAndRemoveLoop(head);
    print(head);
}
