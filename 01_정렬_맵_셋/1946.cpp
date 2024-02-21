#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a, b;
		vector<pair<int, int>> score;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			score.push_back(make_pair(a,b));
		}
		sort(score.begin(), score.end()); //comp함수없이 pair자료형 정렬시 first기준으로 소트
		int flag = 0;
		int res = 1;
		for (int i = 0; i < n; i++) {
			if (score[i].second < score[flag].second) {
				res++;
				flag = i;
			}
		}
		cout << res << '\n';
	}
}