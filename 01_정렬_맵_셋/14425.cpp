#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, int> words;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		words[s] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (words[s] == 1) cnt++;
	}
	cout << cnt;
}