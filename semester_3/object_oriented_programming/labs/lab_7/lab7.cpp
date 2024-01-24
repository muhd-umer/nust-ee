#include <iostream>
using namespace std;

int random(int min, int max);

class TeamProto;

class Employees {
public:
    double employeeSalary = 25000; // $ p/h
};

class Company {
    friend class TeamProto;
    int totalProjects;
    double netProfit;

public:
    Company(double projectCount1, double projectCount2, double sumSalaries1,
        double sumSalaries2)
    {
        totalProjects = projectCount1 + projectCount2;
        netProfit = (random(75000, 90000) * totalProjects) - sumSalaries1 - sumSalaries2;
    }

    void displayInfo()
    {
        cout << "\t\tCompany Data" << endl;
        cout << "Total Projects Completed: " << totalProjects << endl;
        cout << "Net Profit: " << netProfit << endl;
    }
};

class TeamProto : public Employees {
    double employee_1, employee_2, employee_3, employee_4;
    double performanceIncrement = 0.1;

public:
    int projectCount;
    TeamProto(int a) { projectCount = a; }
    void setSalaries(int x)
    {
        employee_1 = random(33050, 42000) + (employeeSalary * performanceIncrement * x);
        employee_2 = random(33050, 42000) + (employeeSalary * performanceIncrement * x);
        employee_3 = random(33050, 42000) + (employeeSalary * performanceIncrement * x);
        employee_4 = random(33050, 42000) + (employeeSalary * performanceIncrement * x);
    }
    double sumSalaries = employee_1 + employee_2 + employee_3 + employee_4;

    friend void employeeData(TeamProto);
    friend void teamData(TeamProto);
};

int random(int min, int max) // range : [min, max]
{
    static bool first = true;
    if (first) {
        srand(time(NULL)); // seeding for the first time only!
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

void employeeData(TeamProto team)
{
    cout << "Employee 1 Salary: " << team.employee_1 << endl;
    cout << "Employee 2 Salary: " << team.employee_2 << endl;
    cout << "Employee 3 Salary: " << team.employee_3 << endl;
    cout << "Employee 4 Salary: " << team.employee_4 << endl;
}

void teamData(TeamProto team)
{
    cout << "\nCollective Team Salary: "
         << team.employee_1 + team.employee_2 + team.employee_3 + team.employee_4
         << endl;
    cout << "Project Count: " << team.projectCount << endl;
}

int main()
{
    TeamProto team1(3), team2(6);
    team1.setSalaries(team1.projectCount);
    team2.setSalaries(team2.projectCount);

    Company Z(team1.projectCount, team2.projectCount, team1.sumSalaries,
        team2.sumSalaries);
    Z.displayInfo();

    cout << "\tData of Team 1";
    teamData(team1);
    employeeData(team1);

    cout << "\n\tData of Team 2";
    teamData(team2);
    employeeData(team2);
    return 0;
}

