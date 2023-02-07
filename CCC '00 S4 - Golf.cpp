using namespace std;
#include <iostream>
#include <stdio.h>
#include <queue>
int d, n, clubs[32], dp[5281];
bool visited[5281];
int main()
{
    scanf("%d", &d);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &clubs[i]);
    }

    for (int i = 0; i < d; i++) {
        if (visited[i] || i == 0) {
            for (int b = 0; b < n; b++) {
                if (dp[i + clubs[b]] > dp[i] + 1 || dp[i + clubs[b]] == 0) {
                    dp[i + clubs[b]] = dp[i] + 1;
                    visited[i + clubs[b]] = true;
                }
            }
        } 
    }
    if (dp[d] != 0){
        printf("Roberta wins in %d strokes.", dp[d]);
    }
        
    else {
        printf("Roberta acknowledges defeat.");
    }
        

}