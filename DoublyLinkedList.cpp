#include<iostream>
using namespace std;

typedef char Elem;               // list element type
class DNode {                     // doubly linked list node
private:
    Elem elem;                    // node element value
    DNode* prev;                  // previous node in list
    DNode* next;                  // next node in list
    friend class DLinkedList;      // allow DLinkedList access
};

class DLinkedList {               // doubly linked list
public:
    DLinkedList();                 // constructor
    ~DLinkedList();                // destructor
    bool empty() const;            // is list empty?
    const Elem& front() const;     // get front element
    const Elem& back() const;      // get back element
    void addFront(const Elem& e);  // add to front of list
    void addBack(const Elem& e);   // add to back of list
    void removeFront();            // remove from front
    void removeBack();             // remove from back
    void print() const;            // print the list
    bool isPalindrome() const;     // check if the list is a palindrome
    void deleteNode(const Elem& e); // delete a node with a specific value
    void insertNode(int index, const Elem& e); // insert a node at a specific position
private:                          // local type definitions
    DNode* header;                // list sentinels
    DNode* trailer;
protected:                         // local utilities
    void add(DNode* v, const Elem& e); // insert new node before v
    void remove(DNode* v);              // remove node v
};

DLinkedList::DLinkedList() {          // constructor
    header = new DNode;               // create sentinels
    trailer = new DNode;
    header->next = trailer;           // have them point to each other
    trailer->prev = header;
}

bool DLinkedList::empty() const       // is list empty?
{
    return (header->next == trailer);
}

const Elem& DLinkedList::front() const  // get front element
{
    return header->next->elem;
}

const Elem& DLinkedList::back() const   // get back element
{
    return trailer->prev->elem;
}

void DLinkedList::remove(DNode* v) {   // remove node v
    DNode* u = v->prev;                // predecessor
    DNode* w = v->next;                // successor
    u->next = w;                       // unlink v from list
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront()        // remove from front
{
    remove(header->next);
}

void DLinkedList::removeBack()         // remove from back
{
    remove(trailer->prev);
}

// insert new node before v
void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode; u->elem = e; // create a new node for e
    u->next = v;                       // link u in between v
    u->prev = v->prev;                  // ...and v->prev
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(const Elem& e)    // add to front of list
{
    add(header->next, e);
}

DLinkedList::~DLinkedList() {           // destructor
    while (!empty()) removeFront();    // remove all but sentinels
    delete header;                     // remove the sentinels
    delete trailer;
}

void DLinkedList::addBack(const Elem& e)  // add to back of list
{
    add(trailer, e);
}

void DLinkedList::print() const {        // print the list
    DNode* current = header->next;
    while (current != trailer) {
        cout << current->elem << " ";
        current = current->next;
    }
    cout << endl;
}

bool DLinkedList::isPalindrome() const { // check if the list is a palindrome
    DNode* left = header->next;
    DNode* right = trailer->prev;

    while (left != right && left->prev != right) {
        if (left->elem != right->elem)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

void DLinkedList::deleteNode(const Elem& e) { // delete a node with a specific value
    DNode* current = header->next;
    while (current != trailer) {
        if (current->elem == e) {
            remove(current);
            return; // Node found and removed, exit function
        }
        current = current->next;
    }
    cout << "Element " << e << " not found in the list." << endl;
}

void DLinkedList::insertNode(int index, const Elem& e) { // insert a node at a specific position
    if (index < 0) {
        cout << "Invalid index." << endl;
        return;
    }

    DNode* current = header->next;
    int currentIndex = 0;

    while (current != trailer && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current == trailer && currentIndex < index) {
        cout << "Index out of bounds." << endl;
        return;
    }

    add(current, e); // Insert the node at the specified position
}

int main() {
    DLinkedList L1;
    L1.addBack('A');
    L1.addBack('B');
    L1.addBack('C');
    L1.addBack('D');
    L1.addBack('E');

    cout << "List elements: ";
    L1.print();

    // Insert 'X' at position 2
    L1.insertNode(2, 'X');
    cout << "After inserting 'X' at position 2: ";
    L1.print();

    // Insert 'Z' at position 0 (front)
    L1.insertNode(0, 'Z');
    cout << "After inserting 'Z' at position 0: ";
    L1.print();

    // Try inserting at an invalid index
    L1.insertNode(10, 'Y');

    L1.deleteNode('Z');
    L1.print();

    return 0;
}
