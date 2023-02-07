#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
  int yearDig[5];
  int year;
  string yearLength = "";
  cin >> year;
  bool unique = false;
  while(unique == false){
    year++;
    yearLength = to_string(year);
    for (int i = 0; i < yearLength.size(); i++){
      int tenPow = pow(10,yearLength.size()-i);\
      int tenPow2 = pow(10,yearLength.size()-(i+1));
      yearDig[i] = ((year % tenPow) - (year % tenPow2))/tenPow2;
    }
    bool bFlag = false;
    bool singCheck = false;
    for (int i = 0; i < yearLength.size(); i++){
      for(int b = 0; b < yearLength.size()-(i+1); b++){
        singCheck = true;
        if(yearDig[i] == yearDig[b+i+1]){
          unique = false;
          bFlag = true;
          break;
        }
        else{
          unique = true;
        }
      }
      if(singCheck == false){
        unique = true;
        break;
      }
      if(bFlag == true){
        break;
      }
    }
  }
  cout << year;
  

}
