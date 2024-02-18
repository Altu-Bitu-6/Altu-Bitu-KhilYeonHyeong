#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string s) {
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])) {
			res += (s[i] - '0');
		}
	}
	return res;
}

bool comp(string s1, string s2) {
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length();
	}
	if (sum(s1) != sum(s2)) {
		return sum(s1) < sum(s2);
	}
	return s1 < s2;
	
}

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) {
		cout << v[i] << '\n';
	}

}

