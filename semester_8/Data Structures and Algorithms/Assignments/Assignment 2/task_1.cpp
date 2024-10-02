/*
Implement a stack data structure in C++ to create a simple text editor with undo
and redo functionality. The stack will be used to store the history of text
changes, allowing users to undo their actions and redo them if needed.

Requirements:
1. Implement a stack data structure in C++ to store text strings.
2. Develop a text editor program that allows users to perform the following
   operations:
   a)  Insert text: Add a new text string to the editor.
   b)  Delete text: Remove text from the editor.
   c)  Undo: Revert the last text operation (insertion or deletion).
   d)  Redo: Restore the text operation that was undone.

3. Ensure that undo and redo operations are properly managed using the stack
   data structure.
4. Handle edge cases such as undo/redo when there are no actions to perform.
5. Implement a user-friendly menu-driven interface to interact with the text
   editor.
*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
   private:
    Node* top;

   public:
    Stack() { top = nullptr; }

    void push(string data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = top;
        top = new_node;
    }

    string pop() {
        if (top == nullptr) {
            return "Stack is empty!";
        }

        string data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    string peek() {
        if (top == nullptr) {
            return "Stack is empty!";
        }
        return top->data;
    }

    bool is_empty() { return top == nullptr; }
};

class TextEditor {
   private:
    Stack undo_stack;
    Stack redo_stack;
    string text = "";  // initial text

   public:
    void insert_text(string new_text) {
        undo_stack.push(text);
        text += new_text;  // two strings are concatenated
    }

    void delete_text(int num_chars) {
        if (num_chars > text.length()) {
            cout << "Invalid number of characters to delete!" << endl;
            return;
        }

        undo_stack.push(text);
        text = text.substr(
            0, text.length() - num_chars);  // remove last n characters
    }

    void undo() {
        if (undo_stack.is_empty()) {
            cout << "Nothing to undo!" << endl;
            return;
        }

        // push current text to redo stack and pop from undo stack
        redo_stack.push(text);
        text = undo_stack.pop();
        cout << "Undo successful!" << endl;
    }

    void redo() {
        if (redo_stack.is_empty()) {
            cout << "Nothing to redo!" << endl;
            return;
        }

        // push current text to undo stack and pop from redo stack
        undo_stack.push(text);
        text = redo_stack.pop();
        cout << "Redo successful!" << endl;
    }

    void display() { cout << text << endl; }
};

void display_menu() {
    cout << "**== Text Editor Menu ==**" << endl;
    cout << "1) -> Insert text" << endl;
    cout << "2) -> Delete text" << endl;
    cout << "3) -> Undo" << endl;
    cout << "4) -> Redo" << endl;
    cout << "5) -> Display text" << endl;
    cout << "6) -> Exit" << endl;
}

int main() {
    TextEditor editor;
    int choice;
    string new_text;
    int num_chars;
    display_menu();

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter text to insert: ";
                cin.ignore();  // clear input buffer
                getline(cin, new_text);
                editor.insert_text(new_text);
                break;
            case 2:
                cout << "Enter number of characters to delete: ";
                cin >> num_chars;
                editor.delete_text(num_chars);
                break;
            case 3:
                editor.undo();
                break;
            case 4:
                editor.redo();
                break;
            case 5:
                editor.display();
                break;
            case 6:
                cout << "Exiting the program ..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}