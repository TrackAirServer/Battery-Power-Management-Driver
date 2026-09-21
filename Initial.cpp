#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class Employee {
public:
    Employee(const std::string& name, const std::string& department, double salary)
        : name(name), department(department), salary(salary) {}

    const std::string& getName() const {
        return name;
    }

    const std::string& getDepartment() const {
        return department;
    }

    double getSalary() const {
        return salary;
    }

private:
    std::string name;
    std::string department;
    double salary;
};

class Company {
public:
    void addEmployee(const std::string& name, const std::string& department, double salary) {
        employees.emplace_back(name, department, salary);
    }

    void sortBySalary() {
        std::sort(employees.begin(), employees.end(),
            [](const Employee& a, const Employee& b) {
                return a.getSalary() > b.getSalary();
            });
    }

    double totalSalary() const {
        double total = 0.0;

        for (const auto& employee : employees) {
            total += employee.getSalary();
        }

        return total;
    }

    void printReport() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Company Report\n";
        std::cout << "==============\n";

        for (const auto& employee : employees) {
            std::cout << employee.getName()
                      << " | "
                      << employee.getDepartment()
                      << " | $"
                      << employee.getSalary()
                      << '\n';
        }

        std::cout << "==============\n";
        std::cout << "Employees: " << employees.size() << '\n';
        std::cout << "Total Salary: $" << totalSalary() << '\n';
        std::cout << "Average Salary: $"
                  << totalSalary() / employees.size()
                  << '\n';
    }

private:
    std::vector<Employee> employees;
};

int main() {
    Company company;

    company.addEmployee("Alice", "Engineering", 6200.00);
    company.addEmployee("Brian", "Marketing", 4700.50);
    company.addEmployee("Clara", "Design", 5300.75);
    company.addEmployee("David", "Finance", 5800.25);

    company.sortBySalary();
    company.printReport();

    return 0;
}