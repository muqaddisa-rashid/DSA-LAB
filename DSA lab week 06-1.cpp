#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBefore(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    if (head== NULL) {
        head = newNode;
        head->next = head;
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
    cout << "Inserted " << value << " at beginning." << endl;
}

void insertAfter(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        newNode->next = head->next;
        head->next = newNode;
       head = newNode;
    }
    cout << "Inserted " << value << " at end." << endl;
}

void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* curr = head->next;
    Node* prev = head;
    do {
        if (curr->data == key) {
            if (curr == head && curr->next == head) 
			head = NULL;
            else if (curr == head->next) head->next = curr->next;
            else if (curr == head) {
                prev->next = head->next;
                head = prev;
            } else prev->next = curr->next;
            delete curr;
            cout << "Deleted " << key << " successfully." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head->next);
    cout << "Node not found." << endl;
}

void display1() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head->next;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head->next);
    cout << endl;
}

int main() {
    insertBefore(10);
    insertBefore(20);
    insertAfter(30);
    display1();
    deleteNode(20);
    display1();
    deleteNode(10);
    display1();
    deleteNode(30);
    display1();
    return 0;
}
