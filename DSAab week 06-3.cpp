#include <iostream>
#include <string>
using namespace std;

struct Book {
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;
};

struct Node {
    Book data;
    Node* next;
};

Node* head = NULL;

void addBook(string id, string name, double price, string author, string isbn) {
    Node* newNode = new Node;
    newNode->data.bookId = id;
    newNode->data.bookName = name;
    newNode->data.bookPrice = price;
    newNode->data.bookAuthor = author;
    newNode->data.bookISBN = isbn;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    cout << "Book added successfully" << endl;
}

// Remove book by ID
void removeBook(string id) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node *curr = head, *prev = NULL;

    // Find the node to delete
    do {
        if (curr->data.bookId == id)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    if (curr->data.bookId != id) {
        cout << "Book not found" << endl;
        return;
    }

    if (curr == head && curr->next == head) {
        head = NULL;
    } else if (curr == head) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        head = head->next;
    } else {
        prev->next = curr->next;
    }

    delete curr;
    cout << "Book deleted successfully" << endl;
}

// Update book details by ID
void updateBook(string id, string name, double price, string author, string isbn) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        if (temp->data.bookId == id) {
            temp->data.bookName = name;
            temp->data.bookPrice = price;
            temp->data.bookAuthor = author;
            temp->data.bookISBN = isbn;
            cout << "Book updated successfully" << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Book not found" << endl;
}

// Print all books
void printBooks() {
    if (head == NULL) {
        cout << "No books in the list" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << "Book ID: " << temp->data.bookId << endl;
        cout << "Name: " << temp->data.bookName << endl;
        cout << "Price: " << temp->data.bookPrice << endl;
        cout << "Author: " << temp->data.bookAuthor << endl;
        cout << "ISBN: " << temp->data.bookISBN << endl;
        cout << "------------------------" << endl;
        temp = temp->next;
    } while (temp != head);
}

// Print single book by ID
void printBook(string id) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        if (temp->data.bookId == id) {
            cout << "Book ID: " << temp->data.bookId << endl;
            cout << "Name: " << temp->data.bookName << endl;
            cout << "Price: " << temp->data.bookPrice << endl;
            cout << "Author: " << temp->data.bookAuthor << endl;
            cout << "ISBN: " << temp->data.bookISBN << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Book not found" << endl;
}

int main() {
    addBook("B1", "BookA", 500, "AuthorA", "ISBN001");
    addBook("B2", "BookB", 600, "AuthorB", "ISBN002");
    addBook("B3", "BookC", 700, "AuthorC", "ISBN003");
    addBook("B4", "BookD", 800, "AuthorD", "ISBN004");
    addBook("B5", "BookE", 900, "AuthorE", "ISBN005");
    
    cout << endl << "All Books:" << endl;
    printBooks();

    cout << endl << "Print one book (B5):" << endl;
    printBook("B5");

    cout << endl << "Remove book B3 (valid)" << endl;
    removeBook("B3");

    cout << "Remove book B100 (invalid)" << endl;
    removeBook("B100");

    cout << endl << "Books after deletion:" << endl;
    printBooks();

    cout << endl << "Update book B2:" << endl;
    updateBook("B2", "BookB_Updated", 650, "AuthorB_Updated", "ISBN002_UPDATED");

    cout << endl << "Print updated book (B2):" << endl;
    printBook("B2");

    return 0;
}
