#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor 
    Node (int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node () {
        int val = this->data;
        if (this->next != NULL) {
            this->next = NULL;
            delete next;
        }
        cout << "Memory is free for node with value: " << val << "\n";
    }

};

class CircularLinkedList {
    public:

    // insertion of new node
    void insertNode (Node* &tail, int element, int d) {
        // Assumming that the element is present in the list

        // expty list
        if (tail == NULL) {
            Node * newNode = new Node (d);
            tail = newNode;
            newNode->next = newNode;
            return;
        }

        else {
            Node * curr = tail;

            if (tail->next == tail) {
                Node * temp = new Node(d);
                Node* curr = tail;
                Node* forward = curr->next;
                curr->next = temp;
                temp->next = forward;
                return;
            }
            else {
                while (curr->data != element)
                {
                    curr = curr->next;
                }

                if (curr->next != tail->next) {
                    Node* temp = new Node (d);
                    temp->next = curr->next;
                    curr->next = temp;
                }
                else {
                    Node* temp = new Node (d);
                    temp->next = curr->next;
                    curr->next = temp;
                }
            }
            
        }
    }

    // size of circular linked list
    int lenCLL(Node* tail) {
        Node* temp = tail;
        int len = 0;
        if (tail == NULL) 
            return 0;
        do
        {
            len++;
            tail = tail->next;
        } while (tail != temp);
        return len;
    }

    // print circular linked list
    void printCLL(Node* tail) {
        Node* temp = tail;
        cout << "( ";
        do {
            cout << tail->data << " -> ";
            tail = tail->next;
        } while (tail != temp);

        cout << ")\n";
    }
};


int main()
{
    CircularLinkedList cll;

    Node* tail = NULL;
    cll.insertNode(tail, 3, 5);
    cll.insertNode(tail, 5, 8);
    cll.insertNode(tail, 5, 3);
    cll.insertNode(tail, 8, 9);
    cll.insertNode(tail, 3, 6);
    cll.insertNode(tail, 9, 11);
    cll.printCLL(tail);

    cout << "Size of Circular Linked List: " << cll.lenCLL(tail) <<"\n";

    return 0;
}