#include <iostream>
#include <stdio.h>
using namespace std;
int memoise[101][101] = {-1}, pyramid[101][101], rows, high = -1, inp;

void traverse(int r, int c, int sum){
  if(r < rows && sum > memoise[r][c]){
    memoise[r][c] = sum;
    traverse(r+1, c, sum + pyramid[r+1][c]);  //left
    traverse(r+1, c+1, sum + pyramid[r+1][c]);  //right
  }
  else if(sum > high) high = sum;
}

int main() {
  scanf("%d", &rows);
  for(int i = 0; i <= rows; ++i){
    for(int j = 0; j < i; ++j){
      scanf("%d", &inp);
      pyramid[i][j] = inp;
    }
  }
  traverse(0,0,pyramid[0][0]);
  printf("%d\n", high);
}