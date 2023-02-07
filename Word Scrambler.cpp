using namespace std;
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

vector<string> c;
int length;
string s;

bool contains(char a, string b) {
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == a) return true;
	}
	return false;
}
void scramble(string n, int clength) {
	if (clength == length) {
		c.push_back(n);
	}
	else{
		int left = length - clength;
		int count = 0;
		while (left > 0 && count < length) {
			if (!contains(s[count], n)) {
				scramble(n + s[count], clength + 1);
				left--;
			}
			count++;
		}
	}
	
}

int main()
{

	cin >> s;
	length = s.length();
	scramble("", 0);
	sort(c.begin(), c.end());
	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << "\n";
	}
}