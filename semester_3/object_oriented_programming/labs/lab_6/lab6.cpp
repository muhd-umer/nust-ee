#include <iostream>
#include <string>
using namespace std;

class BenAndJerry {
 private:
  string flavour;
  string wafer_opt;
  int n_scoops;
  float price, wafer_price = 50;

 public:
  void getChoice() {
    cout << "Enter your flavour choice: ";
    getline(cin, flavour);

    //////////////////////////////

    if (flavour != "Chocolate" && flavour != "Vanilla" &&
        flavour != "Strawbaerry" && flavour != "Tutti Fruiti" &&
        flavour != "Mango" && flavour != "Almong Crunch" &&
        flavour != "Coffee") {
      cout << "Invalid Choice!";
      exit(0);
    }

    //////////////////////////////

    cout << "Enter your wafer choice: ";
    getline(cin, wafer_opt);

    if (wafer_opt != "Yes" && wafer_opt != "No") {
      cout << "Invalid Choice!";
      exit(0);
    }

    //////////////////////////////

    cout << "How many scoops would you like? ";
    cin >> n_scoops;

    if (n_scoops != 2 && n_scoops != 3) {
      cout << "Invalid Choice!";
      exit(0);
    }
  }

  void displayChoice() {
    cout << "\nYour choice of Ice Cream is as follows: " << endl;
    cout << "\nFlavour = " << flavour;
    cout << "\nNumber of Scoops = " << n_scoops;
    if (wafer_opt == "Yes"){   
        cout << "\nWafer is required.";
    }
    if (wafer_opt == "No"){   
        cout << "\nWafer is not required.";
    }
    cout << "\nTotal price is " << priceCalculator();
    cout << endl;
  }

  int priceCalculator() {
    price = 0;
    if (flavour == "Chocolate") {
      if (n_scoops == 2) {
        price = 220;
      }
      if (n_scoops == 3) {
        price = 280;
      }
    }

    else {
      if (n_scoops == 2) {
        price = 200;
      }
      if (n_scoops == 3) {
        price = 250;
      }
    }

    if (wafer_opt == "Yes") {
      price += wafer_price;
    }

    return price;
  }

  void displayMenu() {
    cout << "\t\tWelcome to Ben & Jerry!" << endl;
    cout << "\tFill and shape out your Ice Cream!" << endl;
  }

  ~BenAndJerry() { cout << "Thank you for visiting Ben & Jerry!"; }
};

int main() {
  BenAndJerry cust;
  cust.displayMenu();
  cust.getChoice();
  cust.displayChoice();

  return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;

// class Vision {
//  private:
//   double length, width, price, area;

//  public:
//   void setLength() {
//     cout << "Input your desired TV length: ";
//     cin >> length;
//   }

//   void setWidth() {
//     cout << "Input your desired TV width: ";
//     cin >> width;
//   }

//   void display(int a) {
//     cout << "\nThe details of order # " << a << " are: " << endl;
//     cout << "Length: " << length << endl;
//     cout << "Width: " << width << endl;
//     cout << "Price: " << priceCalculator() << " Rs" << endl;
//   }

//   int areaCalculator() {
//     area = length * width;
//     return area;
//   }

//   int priceCalculator() {
//     price = areaCalculator() * 65;
//     return price;
//   }

//   Vision(int a, int b) {
//     length = a;
//     width = b;
//   }

//   Vision(float a, float b) {
//     length = a;
//     width = b;
//   }

//   Vision() {
//     setLength();
//     setWidth();
//   }
// };

// int main() {
//   cout << "Welcome to VISION TV Portal!\n";
//   Vision t1;
//   t1.display(1);

//   Vision t2(int(25), int(32));
//   t2.display(2);

//   Vision t3(float(27.5), float(32.75));
//   t3.display(3);

//   Vision t4(t3);
//   t4.display(4);

//   return 0;
// }