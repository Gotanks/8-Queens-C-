//http://venus.cs.qc.edu/~waxman/211/integration.pdf
#include <iostream>
using namespace std;

typedef double (*FUNC)(double);
double integrate(FUNC f, double a, double b);
double line (double x);
double square(double x);
double cube(double x);

int main() {
  double x, y;
cout<< "Please enter a starting number"<<endl;
cin>> x;
cout<< "Please enter an end number"<<endl;
cin>> y;
while(x>y){
  cout<<"Invalid entry, starting number is greater than the end number"<<endl;
  cin>>x;
}
cout<< "The integral of f(x)=x between "<<x<< " and "<<y<< " is: "<<integrate(line, x, y)<<endl;
cout<< "The integral of f(x)=x^2 between "<<x<< " and "<<y<< " is: "<<integrate(square, x, y)<<endl;
cout<< "The integral of f(x)=x^3 between "<<x<< " and "<<y<< " is: "<<integrate(cube, x, y)<<endl;
return 0;
}
double integrate(FUNC f, double a, double b){
    double area=0.0;
    for (double i=a; i<=b; i+=.0001)
        area+=f(i)*.0001;
    return area;
}

double line (double x){
  return x;
}

double square(double x){
  return x*x;
}

double cube(double x){
  return x*x*x;
}
