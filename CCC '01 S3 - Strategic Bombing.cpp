#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int adjM[26][26];

bool bfs(){
  bool visited[26];
  for(int i = 0; i < 26; i++){
    visited[i] = false;
  }
  queue <int> q;
  q.push(0);
  visited[0] = true;
  while(!q.empty()){
    int cN = q.front();
    q.pop();
    for(int i = 0; i < 26; i++){
      if(adjM[cN][i] == 1 && visited[i] == false){
        q.push(i);
        visited[i] = true;
      }
    }
  }
  if(visited[1] == false){ //b got cut off
    return true;
  }
  else{ //b still connected
    return false;
  }
}

int main() {
  
  string R = "";
  char n1, n2;
  int E = 0;
  int dRoads = 0;
  queue < pair<int, int> > removeOrd;
  cin >> R;
  
  while(R != "**"){
    E++;
    n1 = R[0];
    n2 = R[1];
    adjM[n1-'A'][n2-'A'] = 1;
    adjM[n2-'A'][n1-'A'] = 1;
    removeOrd.push({n1-'A',n2-'A'});
    cin >> R;
  }
  for(int i = 0; i < E; i++){
    //remove the road
    adjM[removeOrd.front().first][removeOrd.front().second] = 0;
    adjM[removeOrd.front().second][removeOrd.front().first] = 0;
    bool bCon = bfs();
    if(bCon == true){
      char x = removeOrd.front().first+65;
      char y = removeOrd.front().second+65;
      cout << x << y << "\n";
      dRoads++;
    }
    //put it back
    adjM[removeOrd.front().first][removeOrd.front().second] = 1;
    adjM[removeOrd.front().second][removeOrd.front().first] = 1;
    removeOrd.pop();
  }

  cout << "There are " << dRoads << " disconnecting roads." << "\n";
}