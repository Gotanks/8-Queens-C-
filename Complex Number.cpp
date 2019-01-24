#include <iostream>
using namespace std;
class Complex {
private:
	double r;
	double i;

public:
	// constructors

	// default constructor
	Complex() {
		r = 0;
		i = 0;
	}

	Complex(double r1) { 
	  r = r1;//fill this in
	  i = 0;
	}
	
	Complex(double r1, double i1) {
		r = r1;//fill this in
		i = i1;
	}

	// setters and getters (these should be easy)
	int getR() {//getters
		return r;
	}
	
	int getI() {
		return i;
	}
	
	void setR(double r1) {//setters
		r = r1;
	}
	
	void setI(double i1) {
		i = i1;
	}

	// arithmetic operators

	Complex operator+(Complex c) {
	  Complex add;
	  add.r = r + c.r;
		add.i = i + c.i;
		return add;
	}
	
	
	Complex operator-(Complex c) {
	  Complex subtract;
	  subtract.r = r - c.r;
		subtract.i = i - c.i;
		return subtract;
	}
	
	
	Complex operator*(Complex c) {
	  Complex multi;
	  
	  multi.r = (r * c.r) - (i * c.i);
	  multi.i = (r * c.i) + (i * c.r);
		return multi;
	}
	
	
	Complex operator/(Complex c) {
	  Complex division;
	  float square_conj = (c.r * c.r) + (c.i * c.i);
	  
	  division.r = (r * c.r) + (i * c.i);
	  division.r /= square_conj;
	  
	  division.i = (i * c.r) - (r * c.i);
	  division.i /= square_conj;
	  
		return division;
	}
	
	//We only need to output for this one
	friend ostream &operator<<(ostream &os, Complex c);
}; // end of Complex Class

ostream &operator<<(ostream &os, Complex c) {
  if (c.i == 0)
    os << c.r;
  else 
    os << c.r << " + " << c.i << "i";
  return os;
}

int main() { 
	Complex c1, c2(1), c3(3,1);
	
	Complex c4(4, 5);
	Complex c5(7, -3);
	
	c4 = c4 * c5;
	cout << c4 << endl;
	
	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	
	c1 = c2 + c3;
	cout << c1 << endl;
	
	c3 = c1 * c2;
	cout << c3 << endl;
	
	c3 = c3 / c2;
	cout << c3 << endl;
	
	c2 = c2 - c2;
	cout << c2 << endl;

  c1 = c2 * c3;
  cout << c1 <<endl;
  
	return 0;
}