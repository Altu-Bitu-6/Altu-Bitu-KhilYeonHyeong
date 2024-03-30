#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;

//문장에서 각 알파벳 개수를 세는 함수
vector<int> alpCnt(string str) {
	vector<int>cnt(SIZE, 0);
	for (int i = 0; i < str.size(); i++) {
		cnt[str[i] - 'A']++;
	}
	return cnt;
}

string solution(string str) {
	vector<int>cnt = alpCnt(str);
  //팰린드롬의 앞 / 가운데 / 뒤 파트
	string p1 = "", p2 = "", p3 = "";

	for (int i = 0; i < SIZE; i++) {
    //알파벳 개수가 홀수개라면 - 팰린드롬 가운데에 들어가야 함
		if (cnt[i] % 2 == 1) {
      //이미 팰린드롬 가운데가 차 있다면 만들 수 없음
			if (p2.size() == 1) return "I'm Sorry Hansoo";
			p2 = (char)(i + 'A');
		}
    //남은 알파벳을 반씩 앞과 뒤에 넣어줌
		for (int j = 0; j < cnt[i] / 2; j++) {
			p1 = p1 + (char)(i + 'A');
			p3 = (char)(i + 'A') + p3;
		}
	}
	return p1 + p2 + p3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	cout << solution(s);
	
}
