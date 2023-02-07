#include <iostream>
using namespace std;
string arrStreet[100000];
string arrDir[100000];
int main() {
  string streetName = "";
  string direction = "";
  int x = 0;
  arrStreet[0] = "HOME";
  while(true) {
    cin >> direction;
    arrDir[x] = direction;
    cin >> streetName;
    if (streetName == "SCHOOL"){
      break;
    }
    arrStreet[x+1] = streetName;
    x++;
  }
  int a = x - 1;
  for (int i = 0; i <= x; i++) {
    if (arrDir[a+1] == "R") {
      cout << "Turn LEFT";
    }
    else {
      cout << "Turn RIGHT";
    }
    if (arrStreet[a+1] == "HOME"){
      cout << " into your HOME.";
    }
    else{
      cout << " onto " + arrStreet[a+1] + " street.";
    }
    a--;
    cout << endl;
  }
}