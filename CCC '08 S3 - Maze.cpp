#include <iostream>
#include <queue>
using namespace std;

const int MAX = 21, inf = 1e9;
char grid[MAX][MAX];

int bfs(int R, int C){
  queue < pair<int,int>> q;
  int dist[MAX][MAX];
  for(int i = 0; i < MAX; i++){
    for(int b = 0; b < MAX; b++){
      dist[i][b] = inf;
    }
  }
  dist[0][0] = 1;
  q.push({0,0});
  while(!q.empty()){
    int x = q.front().second; int y = q.front().first;
    q.pop();
    if(grid[y][x] == '+'){
      if(grid[y][x+1] != '*' && x+1 < C && dist[y][x]+1<dist[y][x+1]){
        q.push({y,x+1});
        dist[y][x+1] = dist[y][x]+1;
      }
      if(grid[y][x-1] != '*' && x-1 >= 0 && dist[y][x]+1<dist[y][x-1]){
        q.push({y,x-1});
        dist[y][x-1] = dist[y][x]+1;
      }
      if(grid[y+1][x] != '*' && y+1 < R && dist[y][x]+1<dist[y+1][x]){
        q.push({y+1,x});
        dist[y+1][x] = dist[y][x]+1;
      }
      if(grid[y-1][x] != '*' && y-1 >= 0 && dist[y][x]+1<dist[y-1][x]){
        q.push({y-1,x});
        dist[y-1][x] = dist[y][x]+1;
      }
    }
    if(grid[y][x] == '-'){
      if(grid[y][x+1] != '*' && x+1<C && dist[y][x]+1<dist[y][x+1]){
        q.push({y,x+1});
        dist[y][x+1] = dist[y][x]+1;
      }
      if(grid[y][x-1] != '*' && x-1 >= 0 && dist[y][x]+1<dist[y][x-1]){
        q.push({y,x-1});
        dist[y][x-1] = dist[y][x]+1;
      }
    }
    if(grid[y][x] == '|'){
      if(grid[y+1][x] != '*' && y+1 < R && dist[y][x]+1<dist[y+1][x]){
        q.push({y+1,x});
        dist[y+1][x] = dist[y][x]+1;
      }
      if(grid[y-1][x] != '*' && y-1 >= 0 && dist[y][x]+1<dist[y-1][x]){
        q.push({y-1,x});
        dist[y-1][x] = dist[y][x]+1;
      }
    }
  }
  if(dist[R-1][C-1] == inf){
    return -1;
  }
  else{
    return dist[R-1][C-1];
  }
}

int main() {
  int T, R, C;
  char x;
  cin >> T;

  for(int t = 0; t < T; t++){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
      for(int b = 0; b < C; b++){
        cin >> x;
        grid[i][b] = x;
      }
    }
    cout << bfs(R,C) << "\n";
  }
}
