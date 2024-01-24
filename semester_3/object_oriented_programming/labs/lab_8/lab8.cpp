// #include <iostream>
// #include <string>
// using namespace std;

// class Teacher {
//  protected:
//   string name_1;
//   int age_1;

//  public:
//   Teacher() {
//     age_1 = 45;
//     name_1 = "Kaleo";
//   }
//   Teacher(string a, int b) {
//     age_1 = b;
//     name_1 = a;
//   }
//   ~Teacher(){};
// };

// class Scholar : public Teacher {
//  protected:
//   int age_2;
//   string name_2;

//  public:
//   Scholar() {
//     age_2 = 35;
//     name_2 = "Felix";
//   }
//   Scholar(string a, int b) {
//     age_2 = b;
//     name_2 = a;
//   }
//   ~Scholar(){};
// };

// class Author : public Scholar {
//  protected:
//   int age_3;
//   string name_3;

//  public:
//   Author() {
//     age_3 = 99;
//     name_3 = "Dump";
//   }
//   Author(string a, int b) {
//     age_3 = b;
//     name_3 = a;
//   }

//   void setAge() { cin >> age_3; }

//   void setName() { getline(cin, name_3); }

//   void displayInheritedData() {
//     cout << "\nName of Teacher Class (Inherited): " << name_1 << endl;
//     cout << "Age of Teacher Class (Inherited): " << age_1 << endl;

//     cout << "\nName of Scholar Class (Inherited): " << name_2 << endl;
//     cout << "Age of Scholar Class (Inherited): " << age_2 << endl;

//     cout << "\nName of Author Class: " << name_3 << endl;
//     cout << "Age of Author Class: " << age_3 << endl;
//   }

//   void displayData() {
//     cout << "\nName of Author Class: " << name_3 << endl;
//     cout << "Age of Author Class: " << age_3 << endl;
//   }
//   ~Author() { cout << "\nDestructor was called."; };
// };

// int main() {
//   Author m;
//   cout << "\t\tInherited Data";
//   m.displayInheritedData();
//   cout << "\nInput a name to Mutator (Name): ";
//   m.setName();
//   cout << "Input a number to Mutator (Age): ";
//   m.setAge();
//   cout << "\n\t\tMutated Data";
//   m.displayData();

//   cout << "\n\tProgram Executed!\n";
//   return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// class Person {
//  public:
//   int age;
//   string name;
//   Person() {
//     age = 45;
//     name = "Kaleo";
//   }
//   Person(string a, int b) {
//     age = b;
//     name = a;
//   }
//   ~Person() { cout << "\nPerson Destructor was called."; }
// };

// class Teacher : public Person {
//  public:
//   Teacher() {
//     age = 45;
//     name = "Kaleo";
//   }
//   Teacher(string a, int b) {
//     age = b;
//     name = a;
//   }
//   ~Teacher() { cout << "\nTeacher Destructor was called."; };
// };

// class Scholar : public Teacher {
//  public:
//   Scholar() {
//     age = 35;
//     name = "Felix";
//   }
//   Scholar(string a, int b) {
//     age = b;
//     name = a;
//   }
//   ~Scholar() { cout << "\nScholar Destructor was called."; };
// };

// class Author : public Scholar {
//  public:
//   Author() {
//     age = 99;
//     name = "Dump";
//   }
//   Author(string a, int b) {
//     age = b;
//     name = a;
//   }

//   void setAge() { cin >> age; }

//   void setName() { getline(cin, name); }

//   void displayInheritedData() {
//     cout << "\nName of Teacher Class (Inherited): " << name << endl;
//     cout << "Age of Teacher Class (Inherited): " << age << endl;

//     cout << "\nName of Scholar Class (Inherited): " << name << endl;
//     cout << "Age of Scholar Class (Inherited): " << age << endl;

//     cout << "\nName of Author Class: " << name << endl;
//     cout << "Age of Author Class: " << age << endl;
//   }

//   void displayData() {
//     cout << "\nName of Author Class: " << name << endl;
//     cout << "Age of Author Class: " << age << endl;
//   }
//   ~Author() { cout << "\nAuthor Destructor was called."; };
// };

// int main() {
//   Author m;
//   cout << "\t\tInherited Data";
//   m.displayInheritedData();
//   cout << "\nInput a name to Mutator (Name): ";
//   m.setName();
//   cout << "Input a number to Mutator (Age): ";
//   m.setAge();   
//   cout << "\n\t\tMutated Data";
//   m.displayData();

//   cout << "\n\tProgram Executed!\n";
//   return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// class Item {
//   string title;
//   double price;
//   double record[3];

//  public:
//   virtual void getData() {
//     cout << "\nEnter name of Item: ";
//     cin.clear();
//     cin.sync();
//     getline(cin, title);
//     cout << "Enter price of Item: ";
//     cin >> price;
//     cout << "Enter sales of last three months: ";
//     cin >> record[0] >> record[1] >> record[2];
//   }

//   virtual void DisplayData() {
//     cout << "\nItem: " << title << endl;
//     cout << "Price: " << price << " Rs" << endl;
//     cout << "Record: " << record[0] << " Rs " << record[1] << " Rs "
//          << record[2] << " Rs " << endl;
//   }
// };

// class HardwareItem : public Item {
//   string title, manufacturer;
//   double price;
//   double record[3];

//  public:
//   void getData() {
//     cout << "\nEnter name of Item: ";
//     cin.clear();
//     cin.sync();
//     getline(cin, title);
//     cout << "Enter price of Item: ";
//     cin >> price;
//     cout << "Enter manufacturer's name: ";
//     cin.clear();
//     cin.sync();
//     getline(cin, manufacturer);
//     cout << "Enter sales of last three months: ";
//     cin >> record[0] >> record[1] >> record[2];
//   }

//   void DisplayData() {
//     cout << "\nItem: " << title << endl;
//     cout << "Price: " << price << " Rs" << endl;
//     cout << "Record: " << record[0] << " Rs " << record[1] << " Rs "
//          << record[2] << " Rs " << endl;
//   }
// };

// class SoftwareItem : public Item {
//   string title, supported_os;
//   double price;
//   double record[3];

//  public:
//   void getData() {
//     cout << "\nEnter name of Item: ";
//     cin.clear();
//     cin.sync();
//     getline(cin, title);
//     cout << "Enter price of Item: ";
//     cin >> price;
//     cout << "Enter supported OS: ";
//     cin.clear();
//     cin.sync();
//     getline(cin, supported_os);
//     cout << "Enter sales of last three months: ";
//     cin >> record[0] >> record[1] >> record[2];
//   }

//   void DisplayData() {
//     cout << "\nItem: " << title << endl;
//     cout << "Price: " << price << " Rs" << endl;
//     cout << "Record: " << record[0] << " Rs " << record[1] << " Rs "
//          << record[2] << " Rs " << endl;
//   }
// };

// int main() {
//   Item* it = new Item;
//   HardwareItem h1;
//   SoftwareItem* s = new SoftwareItem;
//   it->getData();
//   it->DisplayData();
//   h1.getData();
//   h1.DisplayData();
//   s->getData();
//   s->DisplayData();
//   delete it;

//   return 0;
// }

