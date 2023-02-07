#include <iostream>
#include <stdio.h>

using namespace std;
int N, nums[100001], len[100001] = {0}, mLen = -1;
void calc(int pos, int cLen, int last, int lastpos, bool start){
  if(pos == N-1) {
    if(nums[pos]&last){ //last included
      if(cLen+1 > mLen) mLen = cLen+1;
      len[lastpos] = 2;
    }
    else if(cLen > mLen){ //last ommitted
      mLen = cLen;
    }
  }
  else if(len[pos] != 0 && lastpos != 0){
    if(nums[pos]&last){ //last included
      if(len[pos] + 1 > len[lastpos]){
        len[lastpos] = 1 + len[pos];
      }
      if(cLen+len[pos] > mLen) mLen = cLen+len[pos];
    }
    else{ //ommitted
      calc(pos+1, cLen, last, lastpos, false);
    }
  }
  else if(pos < N){
    //include
    if(nums[pos]&last || start) calc(pos+1, cLen+1, nums[pos], pos, false);
    //omit
    calc(pos+1, cLen, last, lastpos, false);
  }
  
}

int main() {

  scanf("%d", &N);
  for(int i = 0; i  < N; i++) scanf("%d", &nums[i]);
  calc(0, 0, 1, 0, true);
  printf("%d", mLen);

}