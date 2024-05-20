#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

int playGame(int n, vector<vector<int>>board, map<int, char>cmd) {
	//방향전환: 우 상 좌 하
	int dr[4] = { 0,-1,0,1 };
	int dc[4] = { 1,0,-1,0 };

	deque<ci>snake;
	//뱀 초기위치 세팅
	snake.push_front({ 0,0 });
	board[0][0] = 1;

	int t = 0, head = 0;
	while (true) {
		t++;
		//다음 머리 위치
		int nr = snake.front().first + dr[head];
		int nc = snake.front().second + dc[head];
		//종료 조건 (벽에 박거나 자기자신과 부딪힘)
		if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1) {
			break;
		}
		if (board[nr][nc] != 2) {
			//사과 없으면 마지막 칸 비워줌
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		//머리 이동
		snake.push_front({ nr,nc });
		board[nr][nc] = 1;

		//방향전환
		if (cmd[t] == 'L') head = (head + 1) % 4;
		if (cmd[t] == 'D') head = (head + 3) % 4;
	}
	return t;
}

int solution(int n, int k, int l, vector<vector<int>>apple, vector<int>rot_d, vector<char>rot_t) {
	vector<vector<int>>board(n, vector<int>(n));
	for (int i = 0; i < k; i++) {
		board[apple[i][0] - 1][apple[i][1] - 1] = 2; //보드에 사과 표시
	}
	map<int, char>cmd;
	for (int i = 0; i < l; i++) {
		cmd[rot_d[i]] = rot_t[i];
	}
	int ans = playGame(n, board, cmd);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, l;
	//입력
	cin >> n >> k;
  
	vector<vector<int>> apple(k, vector<int>(2));
	for (int i = 0; i < k; i++) //사과 위치
		cin >> apple[i][0] >> apple[i][1];

	cin >> l;
	vector<int> rotation_t(l); //시간
	vector<char> rotation_d(l); //방향
	for (int i = 0; i < l; i++) //회전 정보
		cin >> rotation_t[i] >> rotation_d[i];

	int answer = solution(n, k, l, apple, rotation_t, rotation_d);
	cout << answer;
	return 0;
}
