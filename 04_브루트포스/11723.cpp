#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
//공집합 초기화
int s = 0;

void add(int n) {
	//추가: 해당 인덱스를 1로 표기
  //원래 0이었든 1이었든 add하면 1이 되어야 하니 (1<<n)과 or
	s = s | (1 << n);
}
void remove(int n) {
	//삭제: 해당 인덱스를 0으로 표기
	//1을 0으로 바꿔야하니까 ~(1<<n)과 and
	s = s & ~(1 << n);
}

int check(int n) {
	//and했을때 1이면 1, 0이면 0
	if (s & (1 << n)) {
		return 1;
	}
	else return 0;
}

void toggle(int n) {
  //check와 동일한 로직, 있으면 지우고 없으면 추가
	if (s & (1 << n)) {
		remove(n);
	}
	else add(n);
}

void all(){
  //20자리를 전부 1로 바꿔야하니 21자리 바꾼것에서 1 빼기
	s = (1 << 21) - 1;
}

void empty() {
  //공집합으로...
	s = 0;
}

int solution(string op, int x) {
	if (op == "add") {
		add(x);
	}
	else if (op == "remove") {
		remove(x);
	}
	else if (op == "check") {
		return check(x);
	}
	else if (op == "toggle") {
		toggle(x);
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	for (int i = 0; i < m;i++) {
		string op;
		cin >> op;
    //all, empty는 피연산자를 받지 않으니 따로 처리
		if (op == "all") {
			all();
		}
		else if (op == "empty") {
			empty();
		}
		else {
			int x;
			cin >> x;
			int ans = solution(op, x);
      //check가 호출될 때(리턴값이 -1이 아닐 때)만 답 출력
			if (ans != -1) cout << ans << "\n";
		}
	}

	return 0;
}