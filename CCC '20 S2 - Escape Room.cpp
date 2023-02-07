//  ccc j5 2020
#include <iostream>
#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;
int M, N, room[1001][1001];
bool explored[1001][1001], usednumbers [1000001];
queue <pair<int,int>> q;

int main() {
    bool flag = false;
    //scanf("%d %d",&M, &N);
    cin >> M >> N;
   
    for(int i = 1; i <= M; i++){
        for(int b = 1; b <= N; b++) cin >> room[i][b];//scanf("%d",&room[i][b]);
    }
    q.push({1,1});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        if(r == M && c == N){
            explored[r][c] = true;
            break;
        }
        q.pop();
        int a = room[r][c];
        if(usednumbers[a] != true){
            for(int i = 1; i < sqrt(a) +1; i++){
                if(a % i == 0){
                    int z = a/i;
    //                cout << "factors found: " << i << " " << z << "\n";
                    if((z == M && i == N) || (z == N && i == M)){
                        flag = true;
                        explored[M][N] = true;
                        break;
                    }
                    if(i <= M && z <= N && explored[i][z] != true){
                        q.push({i,z});
                        explored[i][z] = true;
                    }
                    if(i <= N && z <= M && explored[z][i] != true){
                        q.push({z,i});
                        explored[z][i] = true;
                    }
                }
            }
            usednumbers[a] = true;
        }
        if(flag) break;
    }
    if(explored[M][N]) printf("yes");
    else printf("no");
}