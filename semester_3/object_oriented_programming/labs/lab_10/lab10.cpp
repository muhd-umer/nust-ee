// Inclusion of Libraries
#include <iostream>
#include <string>
using namespace std;

// Base Class Body
class Cake {
protected:
    string name;
    double rate;

public:
    double price;
    Cake(){
        name = "Cake";
        rate = 0.01;
    }

    Cake(string n, double r){
        name = n;
        rate = r;
    }

    // Pure Virtual Function
    virtual double calcPrice() = 0;

    void getData(){
        cout << "\tInput the Name of Cake: ";
        cin.ignore();
        getline(cin, name);
        cout << "\tInput Rate: ";
        cin >> rate;
    }
    string toString(){
        return name + "\t" + to_string(rate);
    }

};

// Dervied Class for Ordered Cakes
class orderCake : public Cake {
protected:
    double weight;

public:
    orderCake(){
        weight = 5.00;
    }

    orderCake(double w){
        weight = w;
    }

    double calcPrice(){
        price = weight * rate;
        return price;
    }
};

// Derived Class for Ready Made Cakes
class readymadeCake : public Cake {
protected:
    int quantity;
public:
    readymadeCake(){
        quantity = 1;
    }

    readymadeCake(int q){
        quantity = q;
    }

    double calcPrice(){
        price = quantity * rate;
        return price;
    }
};

int main() {
    Cake *c[2];
    double weight, temp_price;
    int quantity;

    char choice;
    cout << "\t\tInput Data for Cakes!\n";

    // Loop to iterate over the base class array
    for (int i = 0; i < 2; i++){
        cout << "Input your choice: Order or Readymade?\n";
        cin >> choice;
        if (choice == 'o')
        {
            cout << "\tInput Weight: ";
            cin >> weight;

            // Dynamically assign derived class object to 
            // the base class array's index
            c[i] = new orderCake(weight);

            c[i]->getData();
            temp_price = c[i]->calcPrice();
            cout << "\nPrice of Cake: " << temp_price << " $" << "\n\n";
        }

        if (choice == 'r')
        {
            cout << "\tInput Quantity: ";
            cin >> quantity;
            
            // Dynamically assign derived class object to 
            // the base class array's index
            c[i] = new readymadeCake(quantity);
            c[i]->getData();
            temp_price = c[i]->calcPrice();
            cout << "\nPrice of Cake: " << temp_price << " $" << "\n\n";
        }
    }

    // Block to calculate the total price of all cakes
    double tp = 0;
    for (int i = 0; i < 2; i++){
        tp += c[i]->calcPrice();
    }
    cout << "\nTotal Price of All Cakes: " << tp << " $" << endl;

    // Block to find the information about 
    // the highest valued cake

    int rt_index = 1;
    for (rt_index = 1; rt_index < 2; ++rt_index)
    {
       if(c[0]->price < c[rt_index]->price) 
       {
           c[0]->price = c[rt_index]->price;
       }
    }
    --rt_index;

    string hi_info;
    hi_info = c[rt_index]->toString();

    // Printing information about highest priced cake
    cout << "\n\tCake Sold at the Highest Price\n";
    cout << "Name and Rate: " << hi_info << endl;
    cout << "Price: " << c[rt_index]->price << " $" << endl;

    return 0;
}


