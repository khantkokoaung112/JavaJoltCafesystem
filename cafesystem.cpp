#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Employee {
    string employeeID;
    string name;
    string position;
    string employeeType; // 'f' for full-time, 'p' for part-time
    string startDate;
    double basicSalary;
    int leaveDays;
    int overtimeHours;
};

class PayrollSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee() {
        Employee emp;
        cout << "Enter Employee ID: ";  
        cin >> emp.employeeID;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, emp.name);

        cout << "Select Position:\n";
        cout << "1. Barista\n2. Cashier\n3. Kitchen Staff\n4. Cleaner\n5. Waiter/Waitress\n6. Supervisor\n";
        int positionChoice;
        cin >> positionChoice;
        cin.ignore();

        switch (positionChoice) {
            case 1: emp.position = "Barista"; break;
            case 2: emp.position = "Cashier"; break;
            case 3: emp.position = "Kitchen Staff"; break;
            case 4: emp.position = "Cleaner"; break;
            case 5: emp.position = "Waiter/Waitress"; break;
            case 6: emp.position = "Supervisor"; break;
            default: emp.position = "Unknown"; break;
        }

        cout << "Enter Employee Type (f for full-time, p for part-time): ";
        cin >> emp.employeeType;
        cin.ignore();

        cout << "Enter Start Date (YYYY-MM-DD): ";
        cin >> emp.startDate;

        cout << "Enter Basic Salary: ";
        cin >> emp.basicSalary;

        cout << "Enter Leave Days: ";
        cin >> emp.leaveDays;

        cout << "Enter Overtime Hours: ";
        cin >> emp.overtimeHours;

        employees.push_back(emp);
        cout << "Employee added successfully!\n";
    }

    void updateEmployee() {
        string empID;
        cout << "Enter Employee ID to update: ";
        cin >> empID;
        cin.ignore();

        for (auto& emp : employees) {
            if (emp.employeeID == empID) {
                cout << "Enter updated details for Employee ID " << empID << ":\n";

                cout << "Enter Name: ";
                getline(cin, emp.name);

                cout << "Select Position:\n";
                cout << "1. Barista\n2. Cashier\n3. Kitchen Staff\n4. Cleaner\n5. Waiter/Waitress\n6. Supervisor\n";
                int positionChoice;
                cin >> positionChoice;
                cin.ignore();

                switch (positionChoice) {
                    case 1: emp.position = "Barista"; break;
                    case 2: emp.position = "Cashier"; break;
                    case 3: emp.position = "Kitchen Staff"; break;
                    case 4: emp.position = "Cleaner"; break;
                    case 5: emp.position = "Waiter/Waitress"; break;
                    case 6: emp.position = "Supervisor"; break;
                    default: emp.position = "Unknown"; break;
                }

                cout << "Enter Employee Type (f for full-time, p for part-time): ";
                cin >> emp.employeeType;
                cin.ignore();

                cout << "Enter Start Date (YYYY-MM-DD): ";
                cin >> emp.startDate;

                cout << "Enter Basic Salary: ";
                cin >> emp.basicSalary;

                cout << "Enter Leave Days: ";
                cin >> emp.leaveDays;

                cout << "Enter Overtime Hours: ";
                cin >> emp.overtimeHours;

                cout << "Employee updated successfully!\n";
                return;
            }
        }
        cout << "Employee with ID " << empID << " not found.\n";
    }

    void viewEmployee() {
        cout << "\nEmployee Details:\n";
        cout << left << setw(15) << "Employee ID" << setw(20) << "Name" << setw(20) << "Position"
             << setw(15) << "Salary" << setw(15) << "Leave Days" << setw(15) << "Overtime Hours" << setw(15) << "Net Salary" << endl;

        cout << string(80, '-') << endl;

        for (const auto& emp : employees) {
            double salary = emp.basicSalary;

            // Add bonus based on leave days
            if (emp.leaveDays == 0) {
                salary += 300;
            } else if (emp.leaveDays == 1) {
                salary += 200;
            } else if (emp.leaveDays == 2) {
                salary += 100;
            }
                // no bonus for leavedays> 2

            // Deduct penalty for excessive leave days
            if (emp.leaveDays > 4 && emp.overtimeHours > 0) {
                salary -= salary * 0.01; // Deduct 1% of salary
            }

            // Add overtime pay
            salary += (emp.overtimeHours * 15);  // Assuming overtime pay is 15 per hour

            // Deduct taxes
            salary -= (salary * 0.02); // Income tax (2%)
            salary -= 10;             // Social security tax ($10)

            cout << left << setw(15) << emp.employeeID << setw(20) << emp.name << setw(20) << emp.position
                 << "$" << fixed << setprecision(2) << setw(15) << emp.basicSalary << setw(15) << emp.leaveDays
                 << setw(15) << emp.overtimeHours << "$" << fixed << setprecision(2) << setw(15) << salary << endl;
        }
    }

    void generateMonthlyReport() {
        if (employees.empty()) {
            cout << "No employees to include in the report.\n";
            return;
        }

        cout << "\nMonthly Payroll Report:\n";
        cout << left << setw(15) << "Employee ID" << setw(20) << "Name" << setw(20) << "Net Salary" << "\n";
        cout << string(55, '-') << "\n";

        for (const auto& emp : employees) {
            double salary = emp.basicSalary;

            // Add bonus based on leave days
            if (emp.leaveDays == 0) {
                salary += 300;
            } else if (emp.leaveDays == 1) {
                salary += 200;
            } else if (emp.leaveDays == 2) {
                salary += 100;
            }

            // Deduct penalty for excessive leave days
            if (emp.leaveDays > 4 && emp.overtimeHours > 0) {
                salary -= salary * 0.01; // Deduct 1% of salary
            }

            // Add overtime pay
            salary += (emp.overtimeHours * 15);  // Assuming overtime pay is 15 per hour

            // Deduct taxes
            salary -= (salary * 0.02); // Income tax (2%)
            salary -= 10;             // Social security tax ($10)

            cout << left << setw(15) << emp.employeeID << setw(20) << emp.name << "$" << fixed << setprecision(2) << salary << "\n";
        }
    }
};

int main() {
    PayrollSystem system;
    int choice;

    do {
        cout << "\nPayroll System Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Update Employee\n";
        cout << "3. View Employee\n";
        cout << "4. Generate Monthly Report\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addEmployee();
                break;
            case 2:
                system.updateEmployee();
                break;
            case 3:
                system.viewEmployee();
                break;
            case 4:
                system.generateMonthlyReport();
                break;
            case 5:
                cout << "Exiting Payroll System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
