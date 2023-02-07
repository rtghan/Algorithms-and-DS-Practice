#include <bits/stdc++.h>
using namespace std;

int dcities[10000], djset[10000], N, M, D,lowestW = 1e9, n1, n2, w, dc;
bool visited[10000];
pair<int,pair<int,int>> E[100000];
vector <pair<int,int>> aL[10001]; //alist, goes weight, connected node

int find(int n){
  if(djset[n] != n) return djset[n] = find(djset[n]);
  else return n;
}

bool connect(int n1, int n2){
  int n1p = find(n1), n2p = find(n2);
  if(n1p != n2p){
    djset[n2p] = n1p;
    return true;
  }
  else return false;
}
bool dCityVisited(){
  for(int i = 0; i < D; i++){
    if(!visited[dcities[i]]){
      return true;
    }
  }
  return false;
}

void dfs(int cN){
  visited[cN] = true;
  // if(aL[pN][cN].first < lowestW) lowestW = aL[pN][cN].first;
  if(dCityVisited()){
    for(int i = 0; i < aL[cN].size(); i++){
      if(!visited[aL[cN][i].second]){
        if(aL[cN][i].first < lowestW) lowestW = aL[cN][i].first;
        dfs(aL[cN][i].second);
      }
    }
  }
  
}
int main(){
  scanf("%d",&N), scanf("%d",&M), scanf("%d",&D); 

  for(int i = 1; i <= N; i++) djset[i] = i; //root parent to themselves

  for(int i = 1; i <= M; i++){
    scanf("%d",&n1),scanf("%d",&n2),scanf("%d",&w);
    E[i]={w,{n1,n2}};
  }
  sort(E+1,E+M+1);
  
  for(int i = 0; i < D; i++){//holds destination cities
    scanf("%d",&dc);
    dcities[i] = dc;
  }

  for(int i = M; i >= 1; i--){//make alist
    if(connect(E[i].second.first,E[i].second.second)){
      aL[E[i].second.first].push_back({E[i].first,E[i].second.second});
      aL[E[i].second.second].push_back({E[i].first,E[i].second.first});
    }
  }
  dfs(1);
  printf("%d\n", lowestW);
}
