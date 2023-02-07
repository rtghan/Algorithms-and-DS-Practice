#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int djSet[1001], N, M, n1, n2, w, Q, o, edge;//disjointed set, # nodes, # edges, node 1, node 2, weight, # operations, operation
pair < pair<int,int>, pair < int,int > > E[5001]; //pair pair array holding weight, edge, node 1, node 2
vector <pair<int,int>> aL[1001]; // adjacency list for dfs holding connected node, weight
bool visited[1001]; //visited array for dfs


int find(int n){ //find the root parent
  if(djSet[n] != n){
    return djSet[n] = find(djSet[n]);
  }
  else{
    return n;
  }
}

bool connect(int n1, int n2){ //boolean cuz if i make an edge from this i input it into an aList i can run dfs thru it to find if they are connected
  
  int n1p = find(n1), n2p = find(n2);
  if(n1p != n2p){
    djSet[n2p] = n1p;
    return true;
  }
  else{
    return false;
  }
}

void dfs(int n1, int w){ //recursive dfs (i hope?)
  
  visited[n1] = true;

  for(int i = 0; i < aL[n1].size(); i++){
    if(aL[n1][i].second >= w && visited[aL[n1][i].first] == false){ //fulfills weight condition and not visited
      dfs(aL[n1][i].first, w); //immediately explores next node
    }
  }
}

int main(){
  
  scanf("%d", &N);
  scanf("%d", &M);
 

  for(int i = 1; i <= N; i++){ //all node root to themselves
        djSet[i] = i;
  }


  for(int i = 1; i <= M; i++){//input
    scanf("%d", &n1), scanf("%d", &n2), scanf("%d", &w);
    E[i] = {{w,i},{n1,n2}};
  }
  sort(E+1, E+M+1); //ordering array by weight, from edge one to edge m
 

  for(int i = M; i >= 1; i--){//connect edges, greatest to least weight
    //connects node 1 and 2 (if they dont make loop) and if a node was made puts into alist
    if(connect(E[i].second.first,E[i].second.second)){ //am forming (for dfs later in case first operation is a query)
      aL[E[i].second.first].push_back({E[i].second.second,E[i].first.first});
      aL[E[i].second.second].push_back({E[i].second.first,E[i].first.first});
      //bidirectional
    }
  }
  
  scanf("%d",&Q);//take in operations to be done
  // cout << Q << " operations \n";
  

  for(int i = 0; i < Q; i++){
    scanf("%d",&o); //take in which operation needs to be done
    
    if(o == 1){ //update operation
      for(int b = 0; b <= N; b++){
        aL[b].clear();
      }
      //clears the adjacency m of previous trees made in the case that the weight change makes a difference in the tree
      scanf("%d",&edge),scanf("%d",&w);
      // cin >> edge >> w;
      for(int b = 1; b <= M; b++){ //finding edge specified by looking thru array and finding index then updating the weight
      // cout << "current edge: " << E[b].first.second << "\n"; //check where edge is
        if(E[b].first.second == edge){
          E[b].first.first = w;
        }
      }

      for(int b = 1; b <= N; b++){ //all node root to themselves
        djSet[b] = b;
      }

      sort(E+1, E+M+1); //sort by high to low because we explore above a certain weight so starting at highest weight is best
      for(int b = M; b >= 1; b--){
      //connects node 1 and 2 (if they dont make loop) and if a node was made puts into alist

        if(connect(E[b].second.first,E[b].second.second)){ //alist forming
          aL[E[b].second.first].push_back({E[b].second.second,E[b].first.first});
          aL[E[b].second.second].push_back({E[b].second.first,E[b].first.first});
          //bidirectional
        }
      }


    }
    if(o == 2){ //query operation
      scanf("%d",&n1),scanf("%d",&n2),scanf("%d",&w);
      // cin >> n1 >> n2 >> w;

      for(int b = 0; b <= N; b++){//reset the visited of dfs
        visited[b] = false;
      }

      dfs(n1,w); //run dfs to explore connected nodes
      if(visited[n2] == true){
        cout << "1" << "\n";
      }
      else{
        cout << "0" << "\n";
      }
    }
  }
}