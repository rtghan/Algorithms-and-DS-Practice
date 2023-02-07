#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
	int s, inp, selection, percent, level = 0;
	vector<vector<double>> streams(1000);

	scanf("%d", &s);
	for (int i = 1; i <= s; i++) {
		scanf("%d", &inp);
		streams[0].push_back(double(inp));
	}
	
	while (inp != 77) {
		scanf("%d", &inp);

		if (inp == 99) {
			scanf("%d", &selection);
			scanf("%d", &percent);

			//copy over the flow values before the stream to be split
			for (int i = 0; i < selection-1; i++) 
				streams[level + 1].push_back(streams[level][i]);

			//split the stream
			double left = streams[level][selection-1] * double(percent) / 100.0;
			double right = streams[level][selection-1] - left;

			//add it
			streams[level + 1].push_back(left);
			streams[level + 1].push_back(right);

			//continue copying vals from idx. selection
			for (int i = selection; i < streams[level].size(); i++)
				streams[level + 1].push_back(streams[level][i]);
		}
		else if (inp == 88) {
			scanf("%d", &selection);

			//copy over the flow values before the stream to be split
			for (int i = 0; i < selection - 1; i++)
				streams[level + 1].push_back(streams[level][i]);

			//merge
			streams[level + 1].push_back(streams[level][selection - 1] + streams[level][selection]);

			//copy remaining
			for (int i = selection + 1; i < streams[level].size(); i++)
				streams[level + 1].push_back(streams[level][i]);
		}
		++level;
	}
	for (auto i : streams[level-1])
	    printf("%d ", int(i));
}