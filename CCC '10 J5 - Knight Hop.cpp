#include <iostream>
#include <queue>
using namespace std;

const int inf = 1e9;

int main() {
  int ax, ay, bx, by, x, y;
  cin >> ax >> ay >> bx >> by;

//   int board[8][8];
  int dist[8][8];

  //distance to infinite
  for(int i = 1; i < 9; i++){
    for (int b = 1; b < 9; b++){
      dist[i][b] = inf;
    }
  }

  //start node to 0
  dist[ay][ax] = 0;

  queue < pair<int, int> > q;
  q.push({ay,ax});

  while(!q.empty()){
    // cout << "joe";
    x = q.front().second, y = q.front().first;
    q.pop();
    
    //L to the right 2 and up 1
    if(x+2 < 9 && y+1 < 9 && dist[y][x] + 1 < dist[y+1][x+2]){
      q.push({y+1,x+2});
      dist[y+1][x+2] = dist[y][x] + 1;
    }
    //L to the right 2 and down 1
    if(x+2 < 9 && y-1 >= 1 && dist[y][x] + 1 < dist[y-1][x+2]){
      q.push({y-1,x+2});
      dist[y-1][x+2] = dist[y][x] + 1;
    }
    //L to the left 2 and up 1
    if(x-2 >= 1 && y+1 < 9 && dist[y][x] + 1 < dist[y+1][x-2]){
      q.push({y+1,x-2});
      dist[y+1][x-2] = dist[y][x] + 1;
    }
    //L to the left 2 and down 1
    if(x-2 >= 1 && y-1 >= 1 && dist[y][x] + 1 < dist[y-1][x-2]){
      q.push({y-1,x-2});
      dist[y-1][x-2] = dist[y][x] + 1;
    }
    //L to the right 1 and up 2
    if(x+1 < 9 && y+2 < 9 && dist[y][x] + 1 < dist[y+2][x+1]){
      q.push({y+2,x+1});
      dist[y+2][x+1] = dist[y][x] + 1;
    }
    //L to the right 1 and down 2
    if(x+1 < 9 && y-2 >= 1 && dist[y][x] + 1 < dist[y-2][x+1]){
      q.push({y-2,x+1});
      dist[y-2][x+1] = dist[y][x] + 1;
    }
    //L to the left 1 and up 2
    if(x-1 >= 1 && y+2 < 9 && dist[y][x] + 1 < dist[y+2][x-1]){
      q.push({y+2,x-1});
      dist[y+2][x-1] = dist[y][x] + 1;
    }
    //L to the left 1 and down 2
    if(x-1 >= 1 && y-2 >= 1 && dist[y][x] + 1 < dist[y-2][x-1]){
      q.push({y-2,x-1});
      dist[y-2][x-1] = dist[y][x] + 1;
    }
  }
  cout << dist[by][bx];
}