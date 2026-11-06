#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
}

// Display the list.
void display(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }

    cout << "nullptr" << endl;
}

// TODO 1: Insert a node at the beginning.
void insertFront(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// TODO 2: Search for a value.
bool search(Node* head, int value) {
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data == value) {
            return true;
        }

        curr = curr->next;
    }

    return false;
}

// TODO 3: Count the number of nodes.
int countNodes(Node* head) {
    int count = 0;
    Node* curr = head;

    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }

    return count;
}

// TODO 4: Delete the first node containing value.
void deleteValue(Node*& head, int value) {
    if (head == nullptr) {
        return;
    }

    // Delete the first node.
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Find the node before the one to delete.
    Node* curr = head;

    while (curr->next != nullptr &&
           curr->next->data != value) {
        curr = curr->next;
    }

    // Delete the node if found.
    if (curr->next != nullptr) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "CSCI 325 - Lab 6: Activity 1" << endl;

    cout << "\nOriginal list: ";
    display(head);

    cout << "\nInsert 5 at the beginning:" << endl;
    insertFront(head, 5);
    display(head);

    cout << "\nSearch for 20: ";
    cout << (search(head, 20) ? "Found (true)" : "Not found (false)") << endl;

    cout << "Search for 99: ";
    cout << (search(head, 99) ? "Found (true)" : "Not found (false)") << endl;

    cout << "\nNumber of nodes: " << countNodes(head) << endl;

    cout << "\nDelete first node (5):" << endl;
    deleteValue(head, 5);
    display(head);

    cout << "\nDelete middle node (20):" << endl;
    deleteValue(head, 20);
    display(head);

    cout << "\nDelete last node (40):" << endl;
    deleteValue(head, 40);
    display(head);

    cout << "\nDelete missing value (99):" << endl;
    deleteValue(head, 99);
    display(head);

    cout << "\nRemaining nodes: " << countNodes(head) << endl;

    // Free remaining memory.
    while (head != nullptr) {
        deleteValue(head, head->data);
    }

    return 0;
}
