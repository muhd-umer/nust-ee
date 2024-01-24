#include <iostream>

#include <string>

using namespace std;

class Student {
  // Defining few of the required attributes of a Student
 private:
  string name;
  double age;
  double roll_number;
  double marksSubject;

  // Defining get and set functions to access private members
 public:
  void set_name(string in) { name = in; }
  void set_age(double in) { age = in; }
  void set_roll(double in) { roll_number = in; }
  void set_marks(double in) { marksSubject = in; }

  string get_name() { return name; }
  int get_age() { return age; }
  int get_roll() { return roll_number; }
  int get_marks() { return marksSubject; }

  float gpa_calc(int n_subjects) {
    float GPA = 0, grade = 0, TGPA;
    float credit_hours = 0, t_credit_hours = 0;

    for (int i = 1; i <= n_subjects; i++) {
      cout << "   Enter the marks of subject (" << i << ") and credit hours: ";
      cin >> marksSubject >> credit_hours;
      // Defining the grades as per the credit hours
      if (marksSubject > 80) {
        grade = 4;
      } else if (marksSubject > 70) {
        grade = 3.5;
      } else if (marksSubject > 60) {
        grade = 3.0;
      } else if (marksSubject > 50) {
        grade = 2.5;
      } else if (marksSubject > 40) {
        grade = 2.0;
      } else if (marksSubject > 30) {
        grade = 0;
      }
      t_credit_hours += credit_hours;
      GPA += (grade * credit_hours);
    }
    cout << endl;
    TGPA = GPA / t_credit_hours;
    return TGPA;
  }

  float cgpa_calc(int n_semesters) {
    int n_subjects;
    float CGPA = 0, TGPA, sum = 0;
    for (int i = 1; i <= n_semesters; i++) {
      cout << "Enter number of subjects in Semester (" << i << "): ";
      cin >> n_subjects;
      TGPA = gpa_calc(n_subjects);
      sum += TGPA;
    }
    CGPA = sum / n_semesters;
    return CGPA;
  }
};

// Main Execution Code
int main() {
  int n_semesters;
  char grade;
  string name;
  float CGPA, percentage;
  double age, roll;
  Student BEE;

  // Inputting different soon to be set attributes
  cout << "Input Name, Age, Roll No.: " << endl;
  getline(cin, name);
  cin >> age >> roll;

  cout << endl;
  cout << "\t\tSemester Count: ";
  cin >> n_semesters;

  // Setting attributes through public methods
  BEE.set_name(name);
  BEE.set_age(age);
  BEE.set_roll(roll);

  // CGPA Calculator
  CGPA = BEE.cgpa_calc(n_semesters);

  if (CGPA >= 3.5) {
    grade = 'A';
  } else if (CGPA >= 3.0) {
    grade = 'B';
  } else if (CGPA >= 2.5) {
    grade = 'C';
  } else if (CGPA >= 2) {
    grade = 'D';
  } else if (CGPA < 2) {
    grade = 'F';
  }

  // Printing the summary
  cout << "\t\t\t\t\tSummary\n";
  cout << "Name: " << BEE.get_name() << endl;
  cout << "Roll Number: " << BEE.get_roll() << endl;
  cout << "Age: " << BEE.get_age() << endl;
  cout << "Percentage: " << percentage << "%" << endl;
  cout << "CGPA: " << CGPA << endl;
  cout << "Grade: " << grade << endl;

  return 0;
}