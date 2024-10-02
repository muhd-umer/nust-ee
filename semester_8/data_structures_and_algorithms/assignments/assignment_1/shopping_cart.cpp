/*
Shopping Cart [10]: Implement a shopping cart system for an online store. Each
item in the shopping cart can be represented as a node in the linked list. Each
node should have an item ID, item name and price. The system should support
functionalities such as adding items to the cart, removing items, updating
quantities for each item, calculating total price for the shopping cart (list),
and displaying the contents of the cart.
*/

#include <iostream>
#include <string>
using namespace std;

class ShoppingCart {
   private:
    struct Item {
        int id;
        string name;
        double price;
        int quantity;
        Item *next;
    };
    Item *head, *tail;

   public:
    // Constructor and destructor
    ShoppingCart() {
        head = nullptr;
        tail = nullptr;
    }
    ~ShoppingCart() {}

    // Method definitions
    void add_item(int id, string name, double price, int quantity = 1) {
        // if item already exists, increase the quantity else add a new
        // item to the list with the given quantity
        Item *current = head;
        while (current != nullptr) {
            if (current->id == id) {
                current->quantity += quantity;
                return;
            }
            current = current->next;
        }

        Item *new_item = new Item;
        new_item->id = id;
        new_item->name = name;
        new_item->price = price;
        new_item->quantity = quantity;
        new_item->next = nullptr;

        if (head == nullptr) {
            head = new_item;
            tail = new_item;
        } else {
            tail->next = new_item;
            tail = new_item;
        }
    }

    void remove_item(int id, int quantity = 1) {
        // remove the given number of items from the list
        Item *current = head;
        Item *prev = nullptr;

        while (current != nullptr) {
            if (current->id == id) {
                if (current->quantity > quantity) {
                    current->quantity -= quantity;
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

        cout << "- Item not found!" << endl;
    }

    void update_quantity(int id, int quantity) {
        // update the quantity of the item with the given id
        Item *current = head;
        while (current != nullptr) {
            if (current->id == id) {
                current->quantity = quantity;
                return;
            }
            current = current->next;
        }
    }

    double calculate_total_price() {
        // calculate the total price of all the items in the list
        double total_price = 0;
        Item *current = head;
        while (current != nullptr) {
            total_price += current->price * current->quantity;
            current = current->next;
        }
        return total_price;
    }

    void display_cart() {
        // display the contents of the shopping cart
        Item *current = head;
        while (current != nullptr) {
            cout << "- ID: " << current->id << ", Name: " << current->name
                 << ", Price: " << current->price
                 << ", Quantity: " << current->quantity << endl;
            current = current->next;
        }
    }
};

int main() {
    ShoppingCart cart;

    cout << "Adding items to the cart:" << endl;
    cart.add_item(1, "KitKat", 250, 3);
    cart.add_item(2, "Mouse", 5000, 1);
    cart.add_item(3, "Face Mask", 100, 4);
    cart.display_cart();
    cout << "\nTotal Price: " << cart.calculate_total_price() << endl;

    cout << "\nRemoving items from the cart:" << endl;
    cart.remove_item(3);
    cart.display_cart();

    cout << "\nUpdating quantities in the cart:" << endl;
    cart.update_quantity(1, 5);
    cart.display_cart();

    cout << "\nTotal Price: " << cart.calculate_total_price() << endl;

    return 0;
}