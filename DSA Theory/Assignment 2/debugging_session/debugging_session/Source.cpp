#include <iostream>
#include <fstream>
using namespace std;
class MyFloat
{
public:
	MyFloat() { setValue(0.0); count++; };
	MyFloat(const float& v) { setValue(v); count++; };
	MyFloat(const MyFloat& mf) { setValue(mf.value); count++; };
	float getValue() const { return value; }
	void setValue(const float& v) { value = v; }
	void display() const { cout << value << endl; };
	MyFloat add(const MyFloat& a);
	bool isEqual(const MyFloat& a);
	MyFloat subtract(const MyFloat& a);
	bool isGreater(const MyFloat& a);


	static int getCount() { return count; }
private:
	static int count;
	float value;
};
int MyFloat::count = 0;
bool MyFloat::isEqual(const MyFloat& a)
{
	bool result;
	float va = a.getValue();
	float vb = getValue();
	result = (va == vb);
	return result;
}
MyFloat MyFloat::add(const MyFloat& a)
{
	MyFloat result;
	float va = a.getValue();
	float vb = getValue();
	float v = va + vb;
	result.setValue(v);
	return result;
}
MyFloat add(const MyFloat& a, const MyFloat& b)
{
	MyFloat result;
	float va = a.getValue();
	float vb = b.getValue();
	float v = va + vb;
	result.setValue(v);
	return result;
}

MyFloat MyFloat::subtract(const MyFloat& a)
{
	MyFloat result;
	float va = a.getValue();
	float vb = getValue();
	float v = vb - va; // Subtract the value of `a` from `this`
	result.setValue(v);
	return result;
}

bool MyFloat::isGreater(const MyFloat& a)
{
	float va = a.getValue();
	float vb = getValue();
	return vb > va; // Returns true if `this` is greater than `a`
}

int main()
{
	MyFloat x(1.5);
	MyFloat y(3.5);
	MyFloat z = x.add(y);
	z.display();
	MyFloat w = x.subtract(y);
	w.display();
	cout << "count = " << MyFloat::getCount() << endl;
	cout << "count = " << x.getCount() << endl;
	cout << "count = " << y.getCount() << endl;
	cout << "count = " << w.getCount() << endl;
	cout << "count = " << z.getCount() << endl;
	cout << "count = " << w.getCount() << endl;
	if (x.isGreater(y))
	{
		x.display();
	}
	else
	{
		x.display();
		y.display();
	}
	MyFloat a(.5);
	if (x.isGreater(a))
	{
		a.display();
	}
	else
	{
		x.display();
		a.display();
	}
	//cout << "Object Count = " << MyFloat::getCount() << endl;

	MyFloat values[2] = { MyFloat(1.1), MyFloat(2.2) };
	values[0].display();
	values[1].display();
	cout << "Object Count = " << MyFloat::getCount() << endl;
	MyFloat* p = new MyFloat[2]{ MyFloat(11.1), MyFloat(12.2) };
	p[0].display();
	p[1].display();
	cout << "Object Count = " << MyFloat::getCount() << endl;

	return 0;
}