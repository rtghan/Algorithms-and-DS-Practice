#include <iostream>
#include <stdio.h>
using namespace std;


int main() {
  int N, h[100001][3], dp[100001][4];
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 3; j++){
      scanf("%d", &h[i][j]);
    }
  }
  dp[0][0] = h[0][0];
  dp[0][1] = h[0][1];
  dp[0][2] = h[0][2];
  for(int i = 1; i < N; i++){
    for(int j = 0; j < 3; j++){
      if(j == 0) dp[i][j] = max(dp[i-1][1], dp[i-1][2]) + h[i][j];
      else if(j == 1) dp[i][j] = max(dp[i-1][0], dp[i-1][2]) + h[i][j];
      else dp[i][j] = max(dp[i-1][1], dp[i-1][0]) + h[i][j]; // j == 2
    }
  }
  printf("%d", max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])));
}