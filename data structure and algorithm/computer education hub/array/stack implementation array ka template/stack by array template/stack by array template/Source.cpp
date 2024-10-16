#include"myArray.h"
#include<string>


int main() {
	
	

	myArray<int> a(10);
	int i = 0;
	while (!a.isFull()) {
		a.addValue(++i);
	}
	a.display();
	a.addValue(10);

	cout <<  "removed value: ";
	while (!a.isEmpty()) {
		cout  << a.removeValue() << " ";
	}cout << endl;

	a.removeValue();

	cout << endl << endl << endl;

	myArray<string> b(3);
	b.addValue("apples");
	b.addValue("bananas");
	b.addValue("avagandu");
	b.addValue("nigga");
	b.display();


	myArray<const char*> c(4);
	c.addValue("aloo");
	c.addValue("lele");
	c.addValue("sabzi");
	c.addValue("lelo");
	c.display();

	myArray<double> d(2);
	d.addValue(10.42);
	d.display();
	cout << "peeking value: " << d.peek() <<endl;
	d.display();
	d.removeValue();
	d.peek();
	d.removeValue();
	return 0;
}