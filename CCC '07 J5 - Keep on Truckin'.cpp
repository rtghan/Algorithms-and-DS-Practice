#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long motels[7001] = {0,990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010}, A, B, memoise[7001];

long long traverse(int pos){
  //if this motel has already has its unique paths calculated, return its unique paths
  if(memoise[pos] != 0) return memoise[pos];
  
  //iterate through all reachable motels
  for(int i = 1; motels[pos] + B >= motels[pos+i]; i++){
      if(motels[pos] + A <= motels[pos+i]) memoise[pos] += traverse(pos+i);//pass the minimum condition
  }
  //can it reach the end?
  if(motels[pos] + B >= 7000 && motels[pos] + A <= 7000) return ++memoise[pos];
    //it cant :(
  return memoise[pos];
}

int main() {
  int N;
  //input
  scanf("%lld\n%lld\n%d", &A, &B, &N); 
  //add motels
  for(int i = 14; i < 14+N; i++) scanf("%lld", &motels[i]); 
  //order by distance
  sort(motels, motels+14+N);
  //calculate paths and output
  traverse(0);
  cout << memoise[0] << "\n";
}