#include <iostream>
#include <queue>
using namespace std;

const int inf = 1e9;
const int mSize = 1001;
char grid[mSize][mSize];
int dist[mSize][mSize];
int R, C, sx, sy, mx, my, tn, ty, tx; // rows, columns, starting x, starting y, main office x, main office y, number of teleporters, teleporter x, teleporter y

int bfs(){
  //setting all dist to inf
  for(int i = 0; i < mSize; i++){
    for(int b = 0; b < mSize; b++){
      dist[i][b] = inf;
    }
  }
  int x, y;
  queue < pair<int,int> > q;
  q.push({sy,sx});
  dist[sy][sx] = 0;

  while (!q.empty()){
    x = q.front().second, y = q.front().first;
    q.pop();
    if(grid[y][x] == 'T' && dist[y][x] < dist[my][mx]){
      dist[my][mx] = dist[y][x];
      break;
    }
    
    if(x + 1 < C && dist[y][x]+1 < dist[y][x+1] && grid[y][x+1] != 'X'){
      q.push({y, x+1});
      dist[y][x+1] = dist[y][x] + 1;
    }

    if(x - 1 >= 0 && dist[y][x]+1 < dist[y][x-1] && grid[y][x-1] != 'X'){
      q.push({y, x-1});
      dist[y][x-1] = dist[y][x] + 1;
    }

    if(y + 1 < R && dist[y][x]+1 < dist[y+1][x] && grid[y+1][x] != 'X'){
      q.push({y+1, x});
      dist[y+1][x] = dist[y][x] + 1;
    }

    if(y - 1 >= 0 && dist[y][x]+1 < dist[y-1][x] && grid[y-1][x] != 'X'){
      q.push({y-1, x});
      dist[y-1][x] = dist[y][x] + 1;
    }
  }
  return dist[my][mx];
}

int main() {
  cin >> R >> C >> sy >> sx >> my >> mx;
  char x;

  for(int i = 0; i < R; i++){
    for(int b = 0; b < C; b++){
      cin >> x;
      grid[i][b] = x;
    }
  }
  int noT = bfs();
  cin >> tn;
  for(int i = 0; i < tn; i++){
    cin >> ty >> tx;
    grid[ty][tx] = 'T';
  }
  int wT = bfs();
  if(noT - wT > 0){
    cout << noT - wT;
  }
  else{
    cout << "0";
  }
}