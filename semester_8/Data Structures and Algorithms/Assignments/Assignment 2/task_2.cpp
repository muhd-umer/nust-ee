/*
Requirements:
1. Implement a queue data structure in C++.
2. Implement functions to enqueue (add to the end of the queue) and dequeue
   (remove from the front of the queue).
3. Implement a function to display the current state of the queue.
4. Users should be able to submit print jobs to the queue with the number of
   pages to be printed.
5. The program should display the status of the printing queue, including the
   number of jobs in the queue and their details (e.g., job number, number of
   pages).
6. The printer should process print jobs in the order they were received,
   printing each job's pages and removing it from the queue once completed.
7. Display appropriate messages to inform users about their actions and the
   status of their print jobs.

Instructions:
a) Implement the Queue data structure using either arrays or linked lists while
justifying your choice.
b) Design a menu with options for users like submit print jobs or exit the
program.
c) Use appropriate error handling to prevent queue underflow or overflow.
d) Test your program with multiple scenarios to ensure its correctness.
*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int pages;
    string job;
    Node *next;
};

class Queue {
   private:
    Node *front;
    Node *rear;

   public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string job, int pages) {
        Node *new_node = new Node;
        new_node->job = job;
        new_node->pages = pages;
        new_node->next = nullptr;

        if (rear == nullptr) {
            front = new_node;
            rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    string dequeue() {
        if (front == nullptr) {
            return "\0";
        }

        string job = front->job;
        Node *temp = front;
        front = front->next;
        delete temp;
        return job;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node *temp = front;
        int job_number = 1;
        cout << "Printing Queue:" << endl;
        cout << "----------------" << endl;
        while (temp != nullptr) {
            cout << "#" << job_number << " -> " << temp->job << " ("
                 << temp->pages << " pages)" << endl;
            temp = temp->next;
            job_number++;
        }
    }
};

class Printer {
   private:
    Queue print_queue;

   public:
    void submit_job(string job, int pages) {
        print_queue.enqueue(job, pages);
        cout << "Job " << job << " submitted!" << endl;
    }

    void process_job() {
        string job = print_queue.dequeue();
        if (job == "\0") {
            cout << "No jobs in the queue!" << endl;
            return;
        }
        cout << "Printing job (" << job << ") ..." << endl;
    }

    void display_queue() { print_queue.display(); }
};

void display_menu() {
    cout << "**== Printing Queue ==**" << endl;
    cout << "1) -> Submit print job" << endl;
    cout << "2) -> Process print job" << endl;
    cout << "3) -> Display print queue" << endl;
    cout << "4) -> Exit" << endl;
}

int main() {
    Printer printer;
    int choice;
    string job;
    int pages;
    display_menu();

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin >> job;
                cout << "Enter number of pages: ";
                cin >> pages;
                printer.submit_job(job, pages);
                break;
            case 2:
                printer.process_job();
                break;
            case 3:
                printer.display_queue();
                break;
            case 4:
                cout << "Exiting the program ..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}