using namespace std;
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
int main()
{
	int n, speed, t;
	vector<pair<int, int>> obs;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		scanf("%d", &speed);
		obs.push_back(make_pair(t, speed));
	}
	sort(obs.begin(), obs.end());
	double maxs = 0, temp;
	for (int i = 0; i < n - 1; i++) {
		temp = double(abs(obs[i].second - obs[i + 1].second)) / double(abs(obs[i].first - obs[i + 1].first));
		maxs = max(temp, maxs);
	}
	printf("%f", maxs);
}