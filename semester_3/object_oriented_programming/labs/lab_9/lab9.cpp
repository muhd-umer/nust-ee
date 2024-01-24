#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	string name;
	virtual void getData() = 0;

	void getName() {
		cout << "\nEnter a name: ";
		getline(cin, name);
	}
};

class Professor : public Person {

public:
	int numPubs;
	void getData()
	{
		cout << "Enter Number of Publications of the Professor: ";
		cin >> numPubs;
	}
};

class Student : public Person {


public:
	float GPA;
	void getData()
	{
		cout << "Enter GPA of the Student: ";
		cin >> GPA;
	}

};
int main() {
	Professor prof;
	Student stud;

	int n_student = 0, n_professor = 0, n = 0;
	cout << "\tEnter the number of Students: ";
	cin >> n_student;
	
	string st_name[n_student];
	float st_gpa[n_student];

	string prof_name[n_student];
	int prof_pubs[n_student];

	for (int i = 0; i < n_student; i++){
		cin.ignore();
		stud.getName();
		stud.getData();
		st_gpa[i] = stud.GPA;
		st_name[i] = stud.name;
	}

	cout << "_____________________________\n\n";
	cout << "\tEnter the number of Professors: ";
	cin >> n_professor;

	for (int i = 0; i < n_professor; i++){
		cin.ignore();
		prof.getName();
		prof.getData();
		prof_pubs[i] = prof.numPubs;
		prof_name[i] = prof.name;
	}

	cout << "_____________________________\n";

	cout << "\n\tInformation of Students";
	for (int x = 0; x < n_student; x++)
	{

		cout << "\nName of Student: " << st_name[x];
		cout << "\nGPA of Student: " << st_gpa[x];
	}

	cout << "\n_____________________________";

	cout << "\n\n\tInformation of Professors";
	for (int y = 0; y < n_professor; y++)
	{

		cout << "\nName of Professor: " << prof_name[y];
		cout << "\nPublications of Professor: " << prof_pubs[y];
	}

	cout << "\n_____________________________\n\n";

	system("pause");
	return 0;
}
