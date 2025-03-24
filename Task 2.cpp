#include <iostream>

using namespace std;

class Employee {
public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    double fixedSalary;
public:
    FullTimeEmployee(double salary) : fixedSalary(salary) {}
    double calculateSalary() const override {
        return fixedSalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hoursWorked, hourlyRate;
public:
    PartTimeEmployee(double hours, double rate) : hoursWorked(hours), hourlyRate(rate) {}
    double calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }
};

int main() {
    FullTimeEmployee fullTime(5000.0);
    PartTimeEmployee partTime(20, 15.0);

    cout << "Full-Time Employee Salary: " << fullTime.calculateSalary() << endl;
    cout << "Part-Time Employee Salary: " << partTime.calculateSalary() << endl;

    return 0;
}