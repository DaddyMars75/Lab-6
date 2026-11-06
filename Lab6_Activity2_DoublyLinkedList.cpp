#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Insert a node at the end.
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;
}

// Display from first node to last.
void displayForward(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
}

// TODO 1: Display nodes backward.
void displayBackward(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }

    // Move to the last node.
    Node* curr = head;

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    // Follow prev pointers.
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }

    cout << endl;
}

// TODO 2: Delete the first node containing value.
void deleteValue(Node*& head, int value) {
    Node* curr = head;

    // Find the node.
    while (curr != nullptr && curr->data != value) {
        curr = curr->next;
    }

    // Value was not found.
    if (curr == nullptr) {
        return;
    }

    // Update the previous node.
    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }
    else {
        head = curr->next;
    }

    
    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    delete curr;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "CSCI 325 - Lab 6: Activity 2" << endl;

    cout << "\nOriginal list:" << endl;
    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(head);

    cout << "\nDelete first node (10):" << endl;
    deleteValue(head, 10);

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(head);

    cout << "\nDelete middle node (30):" << endl;
    deleteValue(head, 30);

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(head);

    cout << "\nDelete last node (40):" << endl;
    deleteValue(head, 40);

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(head);

    cout << "\nDelete missing value (99):" << endl;
    deleteValue(head, 99);

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(head);

    // Free remaining memory.
    while (head != nullptr) {
        deleteValue(head, head->data);
    }

    return 0;
}
