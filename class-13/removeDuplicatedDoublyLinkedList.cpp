#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

// TC: O(n)
// AS: O(1)
Node* removeDuplicates(Node* head) {

    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr->next;
        while (temp != NULL && temp->data == curr->data) {
            temp = temp->next;
        }

        curr->next = temp;
        if (temp != NULL) {
            temp->prev = curr;
        }
        curr = temp;
    }
    return head;
}

int main() {
    
    vector<Node*> nodes;
    nodes.push_back(new Node(1));
    nodes.push_back(new Node(2));
    nodes.push_back(new Node(2));
    nodes.push_back(new Node(3));
    nodes.push_back(new Node(3));

    nodes[0]->next = nodes[1];
    nodes[1]->next = nodes[2];
    nodes[2]->next = nodes[3];
    nodes[3]->next = nodes[4];

    nodes[4]->prev = nodes[3];
    nodes[3]->prev = nodes[2];
    nodes[2]->prev = nodes[1];
    nodes[1]->prev = nodes[0];

    Node* head = removeDuplicates(nodes[0]);

    print(head);

}
