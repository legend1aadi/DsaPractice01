#include <iostream>
using namespace std;

class Node{
public:
    Node*next;
    int data;
    Node(int data){
        next=nullptr;
        data=data;
    }
};
class cllADT{
private:
    Node*cursor;
    int size;
public:
    cllADT(){
        cursor=nullptr;
        size=0;
    }
    bool  isEmpty(){
        return cursor==nullptr;
    }
    int getSize(){
        return size
    }
    void addAfterCursor(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            // First element - points to itself
            cursor = newNode;
            cursor->next = cursor;
        } else {
            // Insert after cursor
            newNode->next = cursor->next;
            cursor->next = newNode;
        }
        size++;
        cout << "Added " << value << " after cursor\n";
    }



}