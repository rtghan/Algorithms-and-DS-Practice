#include <iostream>
using namespace std;
#include <queue>

const int mSize = 51, inf = 1e9;
char grid[51][51];
int dist[mSize][mSize];

void bfs(int columns, int rows, int cx, int cy, int wx, int wy){
  //setting all dist to inf
  for(int i = 0; i < mSize; i++){
    for(int b = 0; b < mSize; b++){
      dist[i][b] = inf;
    }
  }
  int x, y;
  queue < pair<int,int> > q;
  q.push({cy,cx});
  dist[cy][cx] = 0;

  while (!q.empty()){
    x = q.front().second, y = q.front().first;
    q.pop();


    if(x + 1 < columns && dist[y][x]+1 < dist[y][x+1] && grid[y][x+1] != 'X'){
      q.push({y, x+1});
      dist[y][x+1] = dist[y][x] + 1;
    }

    if(x - 1 >= 0 && dist[y][x]+1 < dist[y][x-1] && grid[y][x-1] != 'X'){
      q.push({y, x-1});
      dist[y][x-1] = dist[y][x] + 1;
    }

    if(y + 1 < rows && dist[y][x]+1 < dist[y+1][x] && grid[y+1][x] != 'X'){
      q.push({y+1, x});
      dist[y+1][x] = dist[y][x] + 1;
    }

    if(y - 1 >= 0 && dist[y][x]+1 < dist[y-1][x] && grid[y-1][x] != 'X'){
      q.push({y-1, x});
      dist[y-1][x] = dist[y][x] + 1;
    }
  }
  if (dist[wy][wx] < 60){
    cout << dist[wy][wx] << endl;
  }
  else{
    cout << "#notworth" << endl;
  }
  return;
}

int main() {
  
  char x;
  int T, C, R, cx, cy, wx, wy;
  
  
  cin >> T;
  for(int i = 0; i < T; i++){
    cin >> C >> R;
    //makes the grid
    for(int b = 0; b < R; b++){
      for(int z = 0; z < C; z++){
        cin >> x;

        //looking for start and end points
        if(x == 'C'){
          cx = z;
          cy = b;
        }
        if(x == 'W'){
          wx = z;
          wy = b;
        }

        grid[b][z] = x;

      }
    }
    bfs(C,R,cx,cy,wx,wy);
  }

  
}
