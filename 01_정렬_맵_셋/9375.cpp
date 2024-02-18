#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	
	while (n--) {
		map<string, int>closet;
		string name, part;

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> name >> part;
			if (closet.find(part) == closet.end()) {
				closet[part] = 1;
			}
			else {
				closet[part] += 1;
			}
		}
		int res = 1;
		for (auto iter = closet.begin(); iter != closet.end(); iter++) {
			res *= iter->second + 1;
		}
		res--;
		cout << res << '\n';
	}
}