#include <bits/stdc++.h>
using namespace std;
int npi, nP, pieDP[251][251]; //amount of pie, # people, unique cases, array to hold cases of recursion
int givePie(int pi, int p){//pie, people
  if(p > pi) return 0;
  else if(p == 1 || p == pi) return 1; //only one possibility if only one person or equal amount of ppl and cake
  else if(pieDP[pi][p] != 0) return pieDP[pi][p];
  else return pieDP[pi][p] = givePie(pi-1,p-1) + givePie(pi-p,p);
}
int main() {
  scanf("%d%d",&npi,&nP);
  printf("%d",givePie(npi,nP));
}