#include <iostream>
using namespace std;
int factorValue;
int main() {
  int number;
  cin >> number;
  for (int i = 0; i < number; i++) {
    int x;
    cin >> x;
    int divisor = 0;
    for (int a = 0; a < x - 1; a++) {
      divisor++;
      if (x % divisor == 0) {
        factorValue = factorValue + divisor;
      }
    }
  cout << x; 
  //cout << factorValue;
  if (factorValue > x) {
    cout << " is an abundant number." << endl;
  }
  if (factorValue == x) {
    cout << " is a perfect number." << endl;
  }
  if (factorValue < x) {
    cout << " is a deficient number." << endl;
  }
  factorValue = 0;
  }
}