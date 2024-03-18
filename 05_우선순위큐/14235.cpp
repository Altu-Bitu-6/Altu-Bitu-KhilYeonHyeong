#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//최대히프
priority_queue<int, vector<int>>pq;

int solution(int a) {
	int res = 0;
  //갖고있는 것들 중에 가장 큰 수(top)출력하고 제거
	if (a == 0) {
    //없으면 -1
		if (pq.empty()) {
			res = -1;
		}
		else {
			res = pq.top();
			pq.pop();
		}
	}
  //0이 안 들어오면 출력하지 말아야하니까 -2를 리턴하고 메인함수에서 출력 안하게 설정
	else {
    //a개의 선물을 pq에 큰 것부터 저장
		for (int i = 0; i < a; i++) {
			int gift;
			cin >> gift;
			pq.push(gift);
		}
		res = -2;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		int res = solution(a);
		if (res != -2) {
			cout << res << "\n";
		}
	}
	return 0;
}