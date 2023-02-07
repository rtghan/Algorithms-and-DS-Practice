#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <map>
#include <cstring>
using namespace std;
int cards[12002], maxPoint = -1, mPoint[10][12002]; //map the pos and questions wrong to a point

void maxPoints(int points, int qR, int pos, int ncards){
  if(pos == ncards*2) { //reached the end
    maxPoint  = (maxPoint > points) ? maxPoint: points;
    return;
  }

  if(points > mPoint[qR][pos]){ //points greater than the previously known max points for this position and qs wrong
    mPoint[qR][pos] = points; //update

    if(qR < 9) maxPoints(points + cards[pos], qR + 1, pos + 1, ncards);   //question right

     maxPoints(points - 1, 0, (pos/2)*2+2, ncards);  //question wrong, (pos/2)*2+2 goes to the next even, since dividing by an int by 2 will floor to the nearest lower even num
  }
}

int main() {
  int ncards;
  memset(mPoint, -1, sizeof(mPoint)); //set default value to -1 (otherwise the first point check against the mPoints array will fail)
  for(int i = 0; i < 10; i++){ //10 cases
    cin >> ncards;
    for(int j = 0; j < ncards*2; j++) cin >> cards[j];
    maxPoint = -1; //reset values
    memset(mPoint, -1, sizeof(mPoint)); //reset values
    maxPoints(0, 0, 0, ncards); 
    cout << maxPoint << "\n";
  }
}