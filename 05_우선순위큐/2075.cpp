#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//최소히프에서 작은것들 날리고 남은 n개중에 가장 작은거 = 찾는수
int nthNum(int n) {
	priority_queue<int, vector<int>,greater<>>pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int el;
			cin >> el;
			pq.push(el);
		}
		while (pq.size() > n) {
			pq.pop();
		}
	}
	int res = pq.top();
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int res = nthNum(n);
	cout << res;
	return 0;
}