#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;

    Node (int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        // memory free
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data: " << value << "\n";
    }
};

class LinkedList {
    public:

    void insertAtHead(Node* &head, int d) {
        Node * temp = new Node(d);
        temp->next = head;
        head = temp;
    }

    void insertAtTail(Node* &tail, int d) {
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }

    void insertAtPosition (Node* &head, Node* &tail, int position, int d) {
        if (position == 1) {
            insertAtHead(head, d);
            return;
        }
        int count = 1;
        Node * temp = head;
        while (count < position-1) {
            temp = temp->next;
            count++;
        }

        // inserting at last position
        if (temp->next == NULL) {
            insertAtTail(tail, d);
            return;
        }

        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }

    int lenLL(Node* &head) {
        int len = 0;
        if (head == NULL) 
            return len;

        Node* node = head;
        while (node != NULL) {
            len++;
            node = node->next;
        }

        return len;
    }

    // Deletion of node at a given position
    void deleteNodeByPosition (Node* &head, int position) {

        // Deleting first or start node
        if (position == 1) {
            Node* node = head;
            head = head->next;
            // memory free start node
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
            curr->next = NULL;
            delete curr;
        }
        
        

    }

    void reverse(Node* &head, Node* &curr, Node* &prev){
        
        //base case
        if(curr == NULL){
            head = prev;
            return;
        }
        Node* forward = curr->next;
        reverse(head,forward,curr);
        curr->next = prev;
    }

    Node* reverseLL(Node* &head) {
        Node* curr = head;
        Node* prev = NULL;
        reverse(head,curr,prev);
        return head;
    }

    void printLL(Node* &head) {
        Node* node = head;
        while (node != NULL) {
            cout << node->data <<"->";
            node = node->next;
        }
        cout << "\n";
    }
};



int main ()
{
    Node* node1 = new Node(5);
    LinkedList ll;
    Node * head = node1; // Head pointed to node1
    // ll.insertAtHead(head, 7);
    // ll.printLL(head);
    Node* tail = node1;

    ll.insertAtTail(tail, 12);
    ll.insertAtTail(tail, 17);                 
    ll.insertAtPosition(head, tail, 2, 20);
    ll.insertAtPosition(head, tail, 4, 34);
    ll.insertAtPosition(head, tail, 6, 21);

    // ll.printLL(head);
    // cout << "Head -> " << head->data << "\n";
    // cout << "Tail -> " << tail->data << "\n";
    // ll.deleteNodeByPosition(head, 1);
    // ll.printLL(head);
    // cout << "Head -> " << head->data << "\n";
    // cout << "Tail -> " << tail->data << "\n";
    // ll.deleteNodeByPosition(head, 3);
    // ll.printLL(head);
    // cout << "Head -> " << head->data << "\n";
    // cout << "Tail -> " << tail->data << "\n";
    // ll.deleteNodeByPosition(head, 4);

    ll.printLL(head);
    cout << "Head -> " << head->data << "\n";
    cout << "Tail -> " << tail->data << "\n";

    ll.reverseLL(head);
    ll.printLL(head);
    cout << "Head -> " << head->data << "\n";
    cout << "Tail -> " << tail->data << "\n";
    cout << "Size of Linked List: " << ll.lenLL(head) << "\n";
    return 0;
}
