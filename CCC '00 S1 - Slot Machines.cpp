#include <iostream>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  int e = 0;
  while (true) {
    if (b == 34) {
      e++;
      a = a + 30;
      a--;
      if (a == 0) {
      break;
    }
      b = 0;
    }
    else {
      e++;
      a--;
      if (a == 0) {
      break;
    }
      b++;
    }
    if (c == 99) {
      e++;
      a = a + 60;
      a--;
      if (a == 0) {
      break;
    }
      c = 0;      
    }
    else {
      e++;
      a--;
      if (a == 0) {
      break;
    }
      c++;      
    }
    if (d == 9) {
      e++;
      a = a + 9;
      a--;  
      if (a == 0) {
      break;
    }   
      d = 0;
    }
    else {
      e++;
      a--;
      if (a == 0) {
      break;
    }
      d++;      
    }
  }
  cout << "Martha plays ";
  cout << e;
  cout << " times before going broke.";
}
