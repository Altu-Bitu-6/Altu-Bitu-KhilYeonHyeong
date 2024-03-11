#include <iostream>
#include <string>

using namespace std;

int getNum(int n) {
	int cnt = 0;
	int start = 666;
  //666부터 1씩 증가시키며 완전탐색
	while (1) {
    //숫자를 문자열로 변환
		string start_str = to_string(start);
    //666이 포함된 숫자면 cnt 증가
		if (start_str.find("666") != string::npos) {
			cnt++;
		}
    //n번째에 도달했다면 종료
		if (cnt == n) {
			break;
		}
		start++;
	}
	return start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << getNum(n);
	return 0;
}