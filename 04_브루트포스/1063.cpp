#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int>ct;

vector<pair<char,char>> chess(string king, string stone, vector<string>op, int n) {
  //킹과 돌의 초기 위치
	ct k = { king[0], king[1] };
	ct s = { stone[0], stone[1] };
  //각 명령에 대한 움직임
	map<string, ct>move = { {"R",{1,0}}, {"L",{-1,0}}, {"B",{0,-1}}, {"T",{0,1}},
	{"RT",{1,1}}, {"LT",{-1,1}}, {"RB",{1,-1}}, {"LB",{-1,-1}} };

	for (int i = 0; i < n; i++) {
    //현재 움직임 정보
		ct cur_move = move[op[i]];
    //킹의 새 위치
		int k_next_x = k.first + cur_move.first;
		int k_next_y = k.second + cur_move.second;
    //킹의 새 위치가 체스판 밖으로 나가지 않을 때만 수행
		if (k_next_x <= 72 && k_next_y <= 56 && k_next_x > 64 && k_next_y > 48) {
			if (k_next_x == s.first && k_next_y == s.second) { //킹이 이동한 위치=돌 위치일 때
        //돌도 cur_move를 사용해 이동시킴
				int s_next_x = s.first + cur_move.first;
				int s_next_y = s.second + cur_move.second;
        //돌의 새 위치도 체스판 밖으로 나가지 않아야 함
				if (s_next_x <= 72 && s_next_y <= 56 && s_next_x > 64 && s_next_y > 48) {
          //킹과 돌의 수정된 위치 적용
					k = { k_next_x, k_next_y };
					s = { s_next_x, s_next_y };
				}
			}
			else {
        //킹이 이동한 위치 != 돌 위치일 때
        //돌은 놔두고 킹만 이동
				k = { k_next_x, k_next_y };
			}
		}
	}
  //좌표로 위치를 표현해야 하므로 char로 변환
	vector<pair<char, char>>result(2);
	result[0] = { char(k.first),char(k.second) };
	result[1] = { char(s.first),char(s.second) };
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string king, stone;
	cin >> king >> stone >> n;
	vector<string>op(n);
	for (int i = 0; i < n; i++) {
		cin >> op[i];
	}
	vector<pair<char, char>>ans = chess(king, stone, op, n);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << ans[i].second << "\n";
	}

	return 0;
}