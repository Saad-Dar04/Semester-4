//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class Shape {
//public:
//	Shape() {};
//	// this is pure virtual function , which makes this class an abstract class
//	// all of the functions need be redefined in the classes that would be made 
//	// underneath this one.
//	virtual void area() = 0;
//};
//
//class Circle : public Shape {
//
//private:
//	int radius; 
//public:
//	// constructor
//	Circle(int &r) : radius(r) {};
//
//	// redifiniton of pure virtual function in the derived class
//	void area() {
//		cout << "area of the circle is: " << 3.141 * radius * radius << endl;
//	}
//
//};
//
//class Rectangle : public Shape {
//private:
//	int lenght;
//	int width;
//public:
//	Rectangle(int& l, int& w) : lenght(l), width(w) {};
//	void area() {
//		cout << "area of the reactangle is: " << lenght * width << endl;
//	}
//};
//
//
//int main() {
//	int radius = 0;
//	cout << "enter the radius: ";
//	cin >> radius;
//	Circle a(radius);
//	a.area();
//
//	int lenght = 0;
//	int width = 0; 
//	cout << "enter the lenght of the rectangle" << endl;
//	cin >> lenght;
//	cout << "enter the width of the rectangle" << endl;
//	cin >> width;
//	Rectangle b(lenght, width);
//	b.area();
//
//	return 0;
//}