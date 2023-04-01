#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor 
    Node (int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor
    ~Node () {
        int val = this->data;
        if (this->next != NULL && this->prev != NULL) {
            delete next;
            this->next = NULL;
            this->prev = NULL;
        }
        cout << "Node deleted with value: " << val <<"\n";

    }
};

class DoublyLinkedList {
    public:
    // insert at Head
    void insertAtHead (Node* &head, int d) {
        Node* temp = new Node(d);
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    
    // insert at tail
    void insertAtTail (Node* &tail, int d) {
        Node* temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    // insert at any position
    void insertAtPosition (Node* &head, Node* tail, int position, int d) {
        if (position == 1) {
            insertAtHead(head, d);
            return;
        }
        Node* temp = head;
        int cnt = 1;
        while (cnt < position-1) {
            temp = temp->next;
            cnt++;
        }

        if (temp->next == NULL) {
            insertAtTail(tail, d);
            return;
        }

        Node* nodeToInsert = new Node(d);
        nodeToInsert->prev = temp;
        temp->next->prev = nodeToInsert;
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }

    // delete node from any position
    void deleteNode (Node* &head, int position) {
        if (position == 1) {
            Node* node = head;
            head->next->prev = NULL;
            head = head->next;
            node->next = NULL;
            delete node;
        }
        else {
            Node* curr = head;
            Node* prev = NULL;
            int cnt = 1;
            while (cnt < position) {
                prev = curr;
                curr = curr->next;
                cnt++;
            }

            prev->next = curr->next;
            curr->next->prev = prev;
            curr->prev = NULL;
            curr->next = NULL;
            delete curr;
        }
    }

    // length of doubly linked list
    int lenDLL (Node* head) {
        Node* temp = head;
        int len = 0;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    // print the Doubly Linked List
    void printDLL(Node* &head) {
        Node* node = head;
        while (node != NULL) {
            cout << node->data << " <=> ";
            node = node->next;
        }
        cout << "\n";
    }
};

int main()
{
    Node* node = new Node(5);
    DoublyLinkedList dll;
    Node* head = node;
    Node* tail = node;
    dll.insertAtHead(head, 7);
    dll.insertAtTail(tail, 11);
    dll.insertAtPosition(head, tail, 3, 9);
    dll.printDLL(head);
    // dll.deleteNode(head, 1);
    dll.deleteNode(head, 3);
    dll.printDLL(head);
    
    cout << "Head: " << head->data <<"\n";
    cout << "Tail: " << tail->data <<"\n";
    cout << "Size of DLL: " << dll.lenDLL(head) <<"\n";

    return 0;
}