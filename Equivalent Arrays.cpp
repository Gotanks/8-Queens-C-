//http://venus.cs.qc.edu/~waxman/211/eqivalent%20arrays.pdf
#include <iostream>
using namespace std;
bool equivalent(int a[], int b[], int n)
{
  int f = 0;//failed counter
//int temp[]= {a, b}; Originally thought to make an temp array of the two arrays, but it's not possible
  for (int i = 0; i<n; i++){
      if(a[i] != b[(f+i)%n]){
        f++;//fail counter
        i=0;//resets index of array back if shift fails
        if(f>=n)//if fails are equal to the numbers in the array
          return false;
      }
  }
  return true;
}
int main() {
  string string_a, string_b;
  cin >> string_a;
  cin >> string_b;
  int n = string_a.size();
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    a[i] = string_a[i];
    b[i] = string_b[i];
  }
  cout << equivalent(a,b,n);
}
