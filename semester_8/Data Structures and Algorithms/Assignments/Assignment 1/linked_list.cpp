/*
Implementation of Linked List [Marks: 5]:
Implement a linked list using classes in C++ for data type int. Your linked list
should support the following operations:

• Insertion of a new node at the beginning, middle, and end of the list.
• Deletion of a node from the list.
• Searching for a node based on a given value.
• Traversing and printing the contents of the list.
*/

#include <iostream>
using namespace std;

class LinkedList {
   private:
    struct Node {
        int data;
        Node *next;
    };
    Node *head, *tail;
    int length;  // length of the list

   public:
    // Constructor and destructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    ~LinkedList() {}

    // Method definitions
    void insert_beginning(int data) {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;

        // if this is the first node, it's also the tail
        if (length == 0) {
            tail = new_node;
        }

        length++;
    }

    void insert_middle(int data) {
        Node *new_node = new Node;
        Node *temp = head;
        new_node->data = data;

        // if the list is empty, insert at the beginning
        if (length == 0) {
            new_node->next = head;
            head = new_node;
            tail = new_node;
            length++;
            return;
        }

        int mid = (length % 2 == 0) ? length / 2 : (length / 2) + 1;

        while (--mid)  // runs the loop mid - 1 times
        {
            temp = temp->next;
        }  // temp is now pointing to the node before the middle node

        new_node->next = temp->next;
        temp->next = new_node;

        // if the new node is inserted at the end, update the tail
        if (new_node->next == nullptr) {
            tail = new_node;
        }

        length++;
    }

    void insert_end(int data) {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        // if the list is empty
        if (head == nullptr) {
            head = new_node;
        } else {
            tail->next = new_node;
        }

        // the new node is now the tail
        tail = new_node;
        length++;
    }

    void delete_node(int data) {
        Node *target = head;
        Node *prev = nullptr;

        // if the list is empty
        if (head == nullptr) {
            cout << "- List is empty, nothing to delete" << endl;
            return;
        }

        // if the node to be deleted is the head
        if (head->data == data) {
            head = head->next;
            delete target;
            length--;
            return;
        }

        while (target != nullptr && target->data != data) {
            prev = target;
            target = target->next;
        }

        // if the node is not found
        if (target == nullptr) {
            cout << "- No node with the given data found" << endl;
            return;
        }

        prev->next = target->next;

        // if the node to be deleted is the tail
        if (target == tail) {
            tail = prev;
        }

        delete target;
        length--;
    }

    void search_node(int data) {
        Node *temp = head;
        int index = 0;

        while (temp != nullptr) {
            if (temp->data == data) {
                cout << "- Node with data (" << data << ") found at position "
                     << index << endl;
                return;
            }
            temp = temp->next;
            index++;
        }

        cout << "- Node with data (" << data << ") not found" << endl;
    }

    void print_list() {
        Node *temp = head;

        if (length == 0) {
            cout << "- List is empty" << endl;
            return;
        }

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    cout << "Insertion at the beginning: " << endl;
    list.insert_beginning(5);
    list.insert_beginning(10);
    list.print_list();

    cout << "\nInsertion in the middle: " << endl;
    list.insert_middle(25);
    list.print_list();

    cout << "\nInsertion at the end: " << endl;
    list.insert_end(40);
    list.print_list();

    cout << "\nDeletion of nodes: " << endl;
    list.delete_node(25);
    list.delete_node(40);
    list.print_list();

    cout << "\nSearch for nodes: " << endl;
    list.search_node(5);
    list.search_node(50);

    return 0;
}