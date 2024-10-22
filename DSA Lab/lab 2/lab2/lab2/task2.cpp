//#include<iostream>
//using namespace std;
//
//class Employee {
//public:
//	virtual void calculateSalary() = 0;
// };
//
//class FullTimeEmployee : public Employee {
//private:
//	int fixedSalary;
//public:
//	FullTimeEmployee(int s) : fixedSalary(s) {};
//	void calculateSalary() {
//		cout << "full time salary of permenant employee is: " << fixedSalary << endl;
//	}
//};
//
//class PartTimeEmployee : public Employee {
//private:
//	int hourlyRate;
//	int hoursWorked;
//public:
//	PartTimeEmployee(int hr, int hw) : hourlyRate(hr), hoursWorked(hw) { };
//	void calculateSalary() {
//		cout << "part time salary of temporary employee is: " << hourlyRate * hoursWorked << endl;
//	}
//};
//
//
//int main() {
//
//	FullTimeEmployee a(10000);
//	a.calculateSalary();
//
//	PartTimeEmployee b(20, 40);
//	b.calculateSalary();
//
//
//
//
//	return 0;
//}