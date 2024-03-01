#include <iostream>
#include <queue>

using namespace std;

void josephus(queue<int> q, int n, int k) {
  //입력
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
  //출력
	cout << "<";
	while (q.size() != 0) {
    //k-1번 요소를 pop하고 뒤쪽에 다시 집어넣음
		for (int i = 0; i < k - 1; i++) {
			int deletedP = q.front();
			q.pop();
			q.push(deletedP);
		}
    //k번째 요소 출력하고 pop
		if (q.size() != 1) {
			cout << q.front() << ", ";
			q.pop();
		}
    //맨 마지막 요소일 경우 > 같이 출력
		else {
			cout << q.front() << '>';
			q.pop();
		}
	}
}


int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	josephus(q, n, k);
	return 0;
}

