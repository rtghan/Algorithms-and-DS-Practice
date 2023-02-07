#include <iostream>
#include <stdio.h>
using namespace std;
int cages[26][26], paths[26][26], R, C, cats, path;

int traverse(int r, int c){
  if(r == R && c == C) return 1; //reached the end cage, the cage that called this function will be marked to have 1 (more) path to get to the end
  if(paths[r][c] != 0) return paths[r][c]; //the cage that connected to the current cage will be marked to have an addition x number of paths, knowing that this cage has x number of paths to the end cage
  if(cages[r+1][c] != 1 && r < R) paths[r][c] += traverse(r+1, c); //down
  if(cages[r][c+1] != 1 && c < C) paths [r][c] += traverse (r, c+1); //right
  return paths[r][c]; //the cage can't go any further/has already traversed its possible cages, return its value to the cage before this one
}

int main() {
  int cR, cC;
  scanf("%d %d %d", &R, &C, &cats);

  for(int i = 0; i < cats; i++){
    scanf("%d %d", &cR, &cC);
    cages[cR][cC] = 1; //1 denotes a cat cage
  }

  traverse(1, 1);
  cout << paths[1][1];
}