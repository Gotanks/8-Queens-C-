// Rat class i.e. a class for rational numbers
#include <iostream>
#include <cmath>
#include <complex>
using namespace std;


class Rat{
private:
int n;
int d;
public:
    // constructors

    // default constructor
    Rat (){
n = 0;
d = 1;
}

    // 2 parameter constructor
    Rat (int i, int j){
n = i;
d = j;
}
    // conversion constructor
    Rat (int i){
n = i;
d = 1;
}
    //accessor functions (usually called get() and set(...) )
  int getN (){
return n;
}

int getD (){
return d;
}

void setN (int i){
n = i;
}

void setD (int i){
d = i;
}
    //arithmetic operators
    Rat operator+ (Rat r){
Rat t;
t.n = n * r.d + d * r.n;
t.d = d * r.d;
return t;
}

Rat operator- (Rat r){
Rat t;
t.n = n * r.d - d * r.n;
t.d = d * r.d;
return t;
}

Rat operator* (Rat r){
Rat t;
t.n = n * r.n;
t.d = d * r.d;
lowestterm (t);
improperFraction (t);
return t;
}

Rat operator/ (Rat r){
Rat t;
t.n = n * r.d / d * r.n;
t.d = d * r.d;
lowestterm (t);
improperFraction (t);
return t;
}

int gcd (int a, int b){				//Could Euclidean Algorithm be used?
    if (b == 0){
return a;
}
    else{
return gcd (b, a % b);
  }
}
				//This GCD method is used with recursion
void lowestterm (Rat & t){				//reducing the fraction to its lowest term
    int x = t.gcd (t.getN (), t.getD ());
t.n /= x;
t.d /= x;
}

void improperFraction (Rat & t)
  {
if (t.n > t.d){
cout << t.n / t.d << " ";
t.n %= t.d;
  }
}
    // 2 overloaded i/o operators
    friend ostream & operator<< (ostream & os, Rat r);
friend istream & operator>> (istream & is, Rat & r);
};				// end Rat
// operator<<() is NOT a member function but since it was declared a friend of
// Rat
// it has access to its private parts.
  ostream & operator<< (ostream & os, Rat r){
os << r.n << " / " << r.d << endl;
return os;
}
// operator>>() is NOT a member function but since it was declared a friend of
// Rat
// it has access to its provate parts.
  istream & operator>> (istream & is, Rat & r){
is >> r.n >> r.d;
return is;
}

int main (){

int x, y, a, b;
cout << "enter numerator ";
cin >> x;
cout << "enter denominator ";
cin >> y;
cout << "enter second numerator ";
cin >> a;
cout << "enter second denominator ";
cin >> b;
Rat r1 (x, y), r2 (a, b);
cout << "r1: " << r1 << endl;
cout << "r2: " << r2 << endl;
cout << "r1 + r2: " << r1 + r2 << endl;
cout << "r1 - r2: " << r1 - r2 << endl;
cout << "r1 * r2: " << r1 * r2 << endl;
cout << "r1 / r2: " << r1 / r2 << endl;
cout << endl;
r1 = r2;
r2 = r1 * r2;
cout << "r1: " << r1 << endl;
cout << "r2: " << r2 << endl;
cout << "r1 + r2: " << r1 + r2 << endl;
cout << "r1 - r2: " << r1 - r2 << endl;
cout << "r1 * r2: " << r1 * r2 << endl;
cout << "r1 / r2: " << r1 / r2 << endl;
cout << endl;
r1 = r2 + r1 * r2 / r1;
r2 = r2 + r1 * r2 / r1;
cout << "r1: " << r1 << endl;
cout << "r2: " << r2 << endl;
cout << "r1 + r2: " << r1 + r2 << endl;
cout << "r1 - r2: " << r1 - r2 << endl;
cout << "r1 * r2: " << r1 * r2 << endl;
cout << "r1 / r2: " << r1 / r2 << endl;
cout << "Last check:" << endl;
Rat c (6, 9), d (9, 6), e;
cout << c;
e = c + d;
cout << e;
c.setN (3);
d.setD (2);
e = c + d;
cout << e;
return 0;
return 0;
}
