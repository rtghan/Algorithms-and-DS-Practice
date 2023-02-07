using namespace std;
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

const int inf = 1e9;

int main()
{
    int N, M, n1, n2, w;
    vector<vector<pair<int, int>>> aL(1001); //weight, node
    int dist[1001];
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 1; i <= M; i++) {
        scanf("%d", &n1), scanf("%d", &n2), scanf("%d", &w);
        aL[n1].push_back(make_pair(w, n2));
        aL[n2].push_back(make_pair(w, n1));
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = inf;
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int cN = q.front();
        q.pop();

        for (int i = 0; i < aL[cN].size(); i++) {
            int dN = aL[cN][i].second; //destination node
            if (dist[cN] + aL[cN][i].first < dist[dN]) {
                dist[dN] = dist[cN] + aL[cN][i].first;
                q.push(dN);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i] != inf)
            printf("%d\n", dist[i]);
        else
            printf("-1\n");
    }
}