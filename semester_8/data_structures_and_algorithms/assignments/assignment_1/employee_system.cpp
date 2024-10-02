/*
Employee Management System [10]: Implement an employee management system where
each employee is represented as a node in the linked list. Each employee must
have the following fields: employee ID, name, contact_number, age, salary,
marital_status. The system should support operations such as adding new
employees, removing employees based on searching for employee id, updating
employee information based on searching for employee id, and displaying the list
of employees.
*/

#include <iostream>
#include <string>
using namespace std;

void input_details(string &name, string &contact_number, int &age,
                   double &salary, string &marital_status) {
    string input;

    cout << "Enter name (or 'skip' to keep current): ";
    getline(cin, input);
    if (input != "skip") {
        name = input;
    }

    cout << "Enter contact number (or 'skip' to keep current): ";
    getline(cin, input);
    if (input != "skip") {
        contact_number = input;
    }

    cout << "Enter age (or 'skip' to keep current): ";
    getline(cin, input);
    if (input != "skip") {
        age = stoi(input);
    }

    cout << "Enter salary (or 'skip' to keep current): ";
    getline(cin, input);
    if (input != "skip") {
        salary = stod(input);
    }

    cout << "Enter marital status (or 'skip' to keep current): ";
    getline(cin, input);
    if (input != "skip") {
        marital_status = input;
    }
}

class EmployeeManagementSystem {
   private:
    struct Employee {
        int employee_id;
        string name;
        string contact_number;
        int age;
        double salary;
        string marital_status;

        Employee *next;
    };

    Employee *head;

   public:
    EmployeeManagementSystem() { head = nullptr; }
    ~EmployeeManagementSystem() {}

    void add_employee(int employee_id, string name, string contact_number,
                      int age, double salary, string marital_status) {
        Employee *new_employee = new Employee;

        new_employee->employee_id = employee_id;
        new_employee->name = name;
        new_employee->contact_number = contact_number;
        new_employee->age = age;
        new_employee->salary = salary;
        new_employee->marital_status = marital_status;

        new_employee->next = head;
        head = new_employee;
    }

    void remove_employee(int employee_id) {
        Employee *current = head;
        Employee *previous = nullptr;

        if (head == nullptr)  // no employees
        {
            cout << "No employees to remove." << endl;
            return;
        }

        while (current != nullptr) {
            if (current->employee_id == employee_id) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }

                delete current;
                return;
            }

            // move to the next node
            previous = current;
            current = current->next;
        }

        cout << "Employee with ID " << employee_id << " not found." << endl;
    }

    void update_employee(int employee_id) {
        Employee *current = head;

        while (current != nullptr) {
            if (current->employee_id == employee_id) {
                cout << "Enter new details for employee with ID " << employee_id
                     << endl;

                // input new details, skip to keep current
                input_details(current->name, current->contact_number,
                              current->age, current->salary,
                              current->marital_status);

                return;
            }

            current = current->next;
        }

        cout << "Employee with ID " << employee_id << " not found." << endl;
    }

    void display_employees() {
        Employee *current = head;

        while (current != nullptr) {
            cout << "- Employee ID: " << current->employee_id << endl;
            cout << "- Name: " << current->name << endl;
            cout << "- Contact Number: " << current->contact_number << endl;
            cout << "- Age: " << current->age << endl;
            cout << "- Salary: " << current->salary << endl;
            cout << "- Marital Status: " << current->marital_status << endl;
            cout << endl;

            current = current->next;
        }
    }
};

int main() {
    EmployeeManagementSystem system;

    system.add_employee(345834, "Umer", "923350526986", 21, 50000, "single");
    system.add_employee(345835, "Ali", "923350526987", 22, 60000, "married");
    system.add_employee(345836, "Ahmed", "923350526988", 23, 70000, "single");

    cout << "Initial Employees: " << endl;
    system.display_employees();

    system.remove_employee(345835);
    cout << "After removing employee with ID 345835: " << endl;
    system.display_employees();

    system.update_employee(345836);
    cout << "After updating employee with ID 345836: " << endl;
    system.display_employees();

    return 0;
}