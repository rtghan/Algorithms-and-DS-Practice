#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector <string> compress[100];
  int x;
  string a, charcounts;
  scanf("%d", &x);
  for(int i = 0; i < x; i++){
    cin >> a;
    char cchar = a[0];
    int charcount = 1;
    for(int b = 1; b < a.length(); b++){
      
      if(a[b] == cchar) charcount++;
      else{
        cout << charcount << " " << cchar << " ";
        charcount = 1;
        cchar = a[b];
      }
    }
    cout << charcount << " " << cchar << "\n";
  }
}