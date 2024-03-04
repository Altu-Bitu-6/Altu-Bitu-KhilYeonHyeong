#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string luckyWheel(int n, vector<pair<int,char>>&rec) {
	vector<char> wheel(n, '?');
	vector<bool> check(26, false); //알파벳 중복확인
	string res = "";
	int index = 0;
	for (int i = 0; i < rec.size(); i++) {
		int rot = rec[i].first;
		char alp = rec[i].second;
    //인덱스가 바퀴 칸 수를 넘으면 안됨
		index = (index - rot % n + n) % n;
		if (wheel[index] == alp) {
			continue;
		}
		if (wheel[index] != '?' || check[alp - 'A']) {
      //넣으려는 자리에 이미 다른 알파벳이 들어가 있거나 중복 사용된 알파벳이라면 해당하는 바퀴 없음
			return "!";
		}
		wheel[index] = alp;
		check[alp - 'A'] = true;
	}

	//마지막 회전에서 화살표가 가리키는 문자부터 출력
	int last_index = index;
	int start = index;
	do {
		res += wheel[last_index];
		last_index = (last_index + 1) % n;
	} while (last_index != start);

	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, char>>record(k, {0, 0});
	for (int i = 0; i < k; i++) {
		cin >> record[i].first >> record[i].second;
	}
	cout << luckyWheel(n, record);
	return 0;
}