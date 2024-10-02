/*
Library Catalog System [15]: Implement a library catalogue system that manages
books in a library. Each book can be represented as a node in the linked list.
The system should support functionalities such as adding new books, removing
books, searching for books by title or author. There can be multiple books by
the same author and same name. The system should also have the following
functions:
1. books_by_author(): Get an authors name as input and display number of books
   by that Author in the catalog.
2. display_catalogue(): On execution, display all the books and number of copies
   of each book present in the list. This means that one book should be
   displayed only once with the number of copies in the list.
*/

#include <iostream>
#include <string>
using namespace std;

class LibraryCatalogSystem {
   private:
    struct Book {
        string title;
        string author;
        int copies;
        Book *next;
    };
    Book *head, *tail;

   public:
    // Constructor and destructor
    LibraryCatalogSystem() {
        head = nullptr;
        tail = nullptr;
    }
    ~LibraryCatalogSystem() {}

    // Method definitions
    void add_book(string title, string author, int copies = 1) {
        // if book already exists, increase the number of copies else add a new
        // book to the list with the given number of copies
        Book *current = head;
        while (current != nullptr) {
            if (current->title == title && current->author == author) {
                current->copies += copies;
                return;
            }
            current = current->next;
        }

        Book *new_book = new Book;
        new_book->title = title;
        new_book->author = author;
        new_book->copies = copies;
        new_book->next = nullptr;

        if (head == nullptr) {
            head = new_book;
            tail = new_book;
        } else {
            tail->next = new_book;
            tail = new_book;
        }
    }

    void remove_book(string title, string author, int copies = 1) {
        // remove the given number of copies of the book from the list
        Book *current = head, *prev = head;

        while (current != nullptr) {
            if (current->title == title && current->author == author) {
                if (current->copies > copies) {
                    current->copies -= copies;
                } else {
                    // remove the book from the list
                    if (current == head) {
                        head = head->next;
                    } else {
                        while (prev->next != current) {
                            prev = prev->next;
                        }
                        prev->next = current->next;
                    }
                    if (current == tail) {
                        tail = prev;
                    }
                    delete current;
                }
                return;
            }
            current = current->next;
        }

        cout << "- Book not found!" << endl;
    }

    void search_by_title(string title) {
        // search for books by title and display the number of copies
        Book *current = head;
        while (current != nullptr) {
            if (current->title == title) {
                cout << "- Title: " << current->title
                     << ", Author: " << current->author
                     << ", Copies: " << current->copies << endl;

                return;
            }

            current = current->next;
        }

        cout << "- Book not found!" << endl;
    }

    void search_by_author(string author) {
        // search for books by author and display all the books by the author
        Book *current = head;
        int valid = 0;
        while (current != nullptr) {
            if (current->author == author) {
                cout << "- Title: " << current->title
                     << ", Copies: " << current->copies << endl;
                valid = 1;
            }

            current = current->next;
        }

        if (valid == 0) {
            cout << "- No books found by " << author << endl;
        }
    }

    void books_by_author(string author) {
        // get an authors name as input and display number of books by that
        // author in the catalog
        int count = 0;
        Book *current = head;
        while (current != nullptr) {
            if (current->author == author) {
                count += current->copies;
            }

            current = current->next;
        }

        if (count > 0) {
            cout << "- Number of books by " << author << ": " << count << endl;
        } else {
            cout << "- No books found by " << author << endl;
        }
    }

    void display_catalogue() {
        Book *current = head;
        while (current != nullptr) {
            cout << "- Title: " << current->title
                 << ", Author: " << current->author
                 << ", Copies: " << current->copies << endl;

            current = current->next;
        }
    }
};

int main() {
    LibraryCatalogSystem library;

    cout << "Adding books to the library:" << endl;
    library.add_book("The Great Gatsby", "F. Scott Fitzgerald");
    library.add_book("To Kill a Mockingbird", "Harper Lee");
    library.add_book("This Side of Paradise", "F. Scott Fitzgerald");
    library.display_catalogue();

    cout << "\nAdding more copies of the same book:" << endl;
    library.add_book("The Great Gatsby", "F. Scott Fitzgerald", 2);
    library.display_catalogue();

    cout << "\nRemoving book copies:" << endl;
    library.remove_book("The Great Gatsby", "F. Scott Fitzgerald");
    library.display_catalogue();

    cout << "\nSearching for books by title:" << endl;
    library.search_by_title("To Kill a Mockingbird");

    cout << "\nSearching for books by author:" << endl;
    library.search_by_author("Harper Lee");
    library.search_by_author("M. Twain");

    cout << "\nGetting number of books by author:" << endl;
    library.books_by_author("F. Scott Fitzgerald");

    return 0;
}