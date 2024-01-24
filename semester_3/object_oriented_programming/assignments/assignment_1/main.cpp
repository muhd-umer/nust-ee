// Student Grade & Record System

// Importing libraries
#include <iostream>
#include <string>
using namespace std;

// Common Class to both Student and Instructor
class Person {
    protected:
        string name;
        int age, rollNumber;
    public:
        void setInfo();

};

// Scoped Function of Person Class
void Person::setInfo(){
    cout << "\n\tInput a Name: ";   // Prompt
    getline(cin, name);
    cout << "\tInput an Age: ";     // Prompt
    cin >> age;
    cout << "\tInput an ID: ";     // Prompt
    cin >> rollNumber;
    cout << "\t\t  Successfully Assigned Data!\n";
}

// Forward Declaration
class Instructor;

// Constructing Student Class with inherent properties of Person
class Student : public Person {
    private:
        int huMarks, mathMarks, eeMarks, csMarks;
        double average;
        char grade;

    public:
        // Default constructor that initializes data to their minimum values
        Student() {
            huMarks = 0;
            mathMarks = 0;
            eeMarks = 0;
            csMarks = 0;
            grade = 'F';
        }
        
        // Parametrized Constructor (for hard coding the results)
        Student(int a, int b, int c, int d, char f) : huMarks(a), mathMarks(b), 
                                                        eeMarks(c), csMarks(d),
                                                        grade(f) {}

        // Prototyping functions that are used in the display function
        double computeAverage();
        void inputData();

        // Display function called within the forward declared class Instructor
        void displayData();

        friend class Instructor;
        
};

// Scoped Functions of Student Class
// Provides the necessary prompts to input data for records
void Student::inputData(){
    int i = 0;

    // A straightforward loop that keeps on repeating until unless
    // the instructor enters marks within the range of 0 - 100
    do
    {
        if (i > 0) {
            cout << "\n\tPlease input the marks in the range of 0 - 100!\n";
        }

        cout << "\nGrade Marking Prompts";
        cout << "\n\tEnter marks in HU Course: ";
        cin >> huMarks;
        cout << "\tEnter marks in MATH Course:  ";
        cin >> mathMarks;
        cout << "\tEnter marks in CS Course:  ";
        cin >> csMarks;
        cout << "\tEnter marks in EE Course:  ";
        cin >> eeMarks;
        i++;

    } while (!((huMarks > 0 && huMarks < 100) && (csMarks > 0 && csMarks < 100) 
                && (mathMarks > 0 && mathMarks < 100) && (eeMarks > 0 && eeMarks < 100)));
    
}

// Computing average of all the subjects
double Student::computeAverage(){
    average = (huMarks + mathMarks + eeMarks + csMarks) / 4;
    return average;    
}

// Record Output Interface
void Student::displayData(){
    cout << "\n\t\t   Student Record";

    // Printing Information
    cout << "\n\t_________________________________";
    cout << "\n\t|\t             " <<"\t\t|";           // Spacing
    cout << "\n\t|\tName: " << name <<"\t|";
    cout << "\n\t|\tRoll Number: " << rollNumber <<"\t|";
    cout << "\n\t|\tAge: " << age <<"\t\t\t|";
    cout << "\n\t|\t             " <<"\t\t|";           // Spacing
    
    // Printing out results
    cout << "\n\t|\tHU    Marks: " << huMarks <<"\t\t|";              
    cout << "\n\t|\tMATH  Marks: " << mathMarks <<"\t\t|";                
    cout << "\n\t|\tCS    Marks: " << csMarks <<"\t\t|";              
    cout << "\n\t|\tEE    Marks: " << eeMarks <<"\t\t|";              
    cout << "\n\t|\t             " <<"\t\t|";           // Spacing
    cout << "\n\t|\tAverage Marks: " << computeAverage() << "\t|";
    cout << "\n\t|\tGrade: " << grade <<"\t\t|";
    cout << "\n\t ________________________________";
    // End
}

// Constructing Instructor Class with inherent properties of Person
class Instructor : private Person {
    public:
        void accessInh(){
            setInfo();
        }

        // Controls and modifies the data members within the Student class
        void controlRecord(Student s){
            s.inputData();
            cout << "\nInput a Grade for the Current Student: ";
            cin >> s.grade;
            s.displayData();      
        }
        friend void digSignature(Instructor);   // Friend function to display the information of Instructor
                                                // incase a student may have a query about grading

        // Destructor
        ~Instructor(){
            cout << "Destructor was called!\n";
        }
};

// Body of Friend Function
void digSignature(Instructor i){
    cout << "\n\n\t\tGraded by: " << i.name << ", ID: " << i.rollNumber;
    cout << "\n\n";
}

// Main Program, Instantiating Objects and Printing Records
int main() {
    // Welcome message
    cout << "\n\t\tStudent Grade & Record System";
    // Initializing Student Object
    Student s_A;
    cin.ignore();
    cout << "\nSet Information for Student";
    s_A.setInfo();

    // Initializing Instructor Object and Accessing Student Data Members
    // And modifying them through the friend class
    Instructor c;
    cin.ignore();
    cout << "\nSet Information for Instructor";
    c.accessInh();
    c.controlRecord(s_A);
    digSignature(c);
    return 0;
}
