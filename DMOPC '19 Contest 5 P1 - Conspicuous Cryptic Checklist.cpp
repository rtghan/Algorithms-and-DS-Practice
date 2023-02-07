#include <iostream>
using namespace std;
int item, assignments;
string items[201];
bool check(string n){
  for(int i = 0; i < item; i++){
    if(items[i] == n) return true;
  }
  return false;
}

int main() {
  int passignments = 0;
  cin >> item >> assignments;
  
  for(int i = 0; i < item; i++){
    cin >> items[i];
  }

  for(int i = 0; i < assignments; i++){
    int ritems;
    bool possible = true;
    cin >> ritems;

    for(int b = 0; b < ritems; b++){
      string aitem;
      cin >> aitem;
      if(!check(aitem)) possible = false;
    }
    if(possible) passignments++;
  }
  cout << passignments;

}