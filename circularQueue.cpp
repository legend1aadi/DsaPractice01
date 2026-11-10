//AADITYA SAINI
//24/94045

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* cursor;
    int size;

public:
    CircularLinkedList() {
        cursor = nullptr;
        size = 0;
    }

    ~CircularLinkedList() {
        if (!isEmpty()) {
            Node* current = cursor->next;
            Node* toDelete;
            
            while (current != cursor) {
                toDelete = current;
                current = current->next;
                delete toDelete;
            }
            delete cursor;
        }
    }

    bool isEmpty() {
        return cursor == nullptr;
    }

    int getSize() {
        return size;
    }

    void addAfterCursor(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            cursor = newNode;
            cursor->next = cursor;
        } else {
            newNode->next = cursor->next;
            cursor->next = newNode;
        }
        size++;
        cout << "Added " << value << " after cursor\n";
    }

    void addBeforeCursor(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            cursor = newNode;
            cursor->next = cursor;
        } else {
            Node* temp = cursor;
            while (temp->next != cursor) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = cursor;
        }
        size++;
        cout << "Added " << value << " before cursor\n";
    }

    void removeAtCursor() {
        if (isEmpty()) {
            cout << "List is empty! Nothing to remove.\n";
            return;
        }

        if (cursor->next == cursor) {
            delete cursor;
            cursor = nullptr;
        } else {
            Node* prev = cursor;
            while (prev->next != cursor) {
                prev = prev->next;
            }
            
            prev->next = cursor->next;
            Node* toDelete = cursor;
            cursor = cursor->next;
            delete toDelete;
        }
        size--;
        cout << "Removed element at cursor\n";
    }

    void advanceCursor() {
        if (!isEmpty()) {
            cursor = cursor->next;
            cout << "Cursor advanced. Current element: " << cursor->data << "\n";
        } else {
            cout << "List is empty!\n";
        }
    }

    int getCurrent() {
        if (!isEmpty()) {
            return cursor->data;
        }
        throw runtime_error("List is empty!");
    }

    void display() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        cout << "Circular List (size: " << size << "): ";
        Node* current = cursor;
        
        do {
            if (current == cursor) {
                cout << "[" << current->data << "] ";
            } else {
                cout << current->data << " ";
            }
            current = current->next;
        } while (current != cursor);
        
        cout << "\n";
    }

    int search(int value) {
        if (isEmpty()) return -1;

        Node* current = cursor;
        int position = 0;
        
        do {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        } while (current != cursor);
        
        return -1;
    }
};

int main() {
    CircularLinkedList list;
    
    cout << "=== Circular Linked List with Cursor Demo ===\n\n";
    
    list.addAfterCursor(10);
    list.addAfterCursor(20);
    list.addBeforeCursor(5);
    list.display();
    
    list.advanceCursor();
    list.display();
    
    list.addAfterCursor(25);
    list.addBeforeCursor(15);
    list.display();
    
    int searchVal = 20;
    int pos = list.search(searchVal);
    if (pos != -1) {
        cout << "Found " << searchVal << " at position " << pos << " from cursor\n";
    } else {
        cout << searchVal << " not found in the list\n";
    }
    
    list.removeAtCursor();
    list.display();
    
    list.advanceCursor();
    list.advanceCursor();
    list.display();
    
    return 0;
}