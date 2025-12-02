#include <iostream>
#include <string>
using namespace std;

struct Node2 {
    string name;
    Node2* next;
};

Node2* last2 = NULL;

void addEmployee(string n) {
    Node2* newNode = new Node2;
    newNode->name = n;
    if (last2 == NULL) {
        last2 = newNode;
        last2->next = last2;
    } else {
        newNode->next = last2->next;
        last2->next = newNode;
        last2 = newNode;
    }
    cout << n << " added successfully." << endl;
}

void deleteEmployee(string n) {
    if (last2 == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node2* curr = last2->next;
    Node2* prev = last2;
    do {
        if (curr->name == n) {
            if (curr == last2 && curr->next == last2) last2 = NULL;
            else if (curr == last2->next) last2->next = curr->next;
            else if (curr == last2) {
                prev->next = last2->next;
                last2 = prev;
            } else prev->next = curr->next;
            delete curr;
            cout << n << " deleted successfully." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last2->next);
    cout << n << " not found." << endl;
}

void searchEmployee(string n) {
    if (last2 == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node2* temp = last2->next;
    do {
        if (temp->name == n) {
            cout << n << " found successfully." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != last2->next);
    cout << n << " not found." << endl;
}

void display2() {
    if (last2 == NULL) {
        cout << "No employees." << endl;
        return;
    }
    Node2* temp = last2->next;
    cout << "Employees: ";
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != last2->next);
    cout << endl;
}

int main() {
    addEmployee("Ali");
    addEmployee("Sara");
    addEmployee("bareera");
    display2();
    searchEmployee("Sara");
    deleteEmployee("bareera");
    display2();
    deleteEmployee("hanaan");
    return 0;
}
