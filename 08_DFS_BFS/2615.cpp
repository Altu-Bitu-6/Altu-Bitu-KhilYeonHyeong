#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 19;

//게임판
vector<vector<int>>board(MAX, vector<int>(MAX, 0));
//각 위치에서 방향별로 visited 표시
bool dfs_visited[MAX][MAX][4];
//연속된 바둑돌 위치저장
vector<pair<int, int>> stones(5, { 0,0 });

//왼->오, 위->아래로 탐색하니까 해당 4방향만 탐색
int dx[4] = { 1,1,0,-1 }; //오른쪽 오른쪽아래 아래 왼쪽아래
int dy[4] = { 0,1,1,1 };

//해당방향(k)에 같은 색 돌이 있는지 탐색
int dfs(int x, int y, int k, int color, int cnt) {
	dfs_visited[y][x][k] = true;
	stones.push_back({ y,x });
	int nx = x + dx[k];
	int ny = y + dy[k];
  //판 밖으로 나갔거나 현재 탐색중인 색이 아닐 때(연속되지 않을 때)
	if (!(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX) || board[ny][nx] != color) {
		//현재까지의 카운트 반환
    return cnt;
	}
  //그렇지 않으면 순환호출해서 계속 탐색
	return dfs(nx, ny, k, color, cnt + 1);
}

//가장 왼쪽에 있는 바둑알부터 정렬하기 위한 비교함수
//세로줄 기준 오름차순 정렬. 세로로 일자라면 제일 위(가로줄 기준 오름차순 정렬)
bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int solution() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (board[i][j] == 0) continue;
      //4방향 확인
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX) {
          //같은 색 돌이고 아직 방문하지 않았다면
					if (board[ny][nx] == board[i][j] && !dfs_visited[i][j][k]) {
            //돌 위치 저장할 배열 비우고 현재위치 삽입
						stones.clear();
						stones.push_back({ i,j });
						dfs_visited[i][j][k] = true;
						if (dfs(nx, ny, k, board[i][j], 2) == 5) { //반환된 값이 정확히 5일 때만
              //위치 배열 정렬
							sort(stones.begin(), stones.end(), cmp);
              //이긴 돌 색 반환하고 종료
							return board[i][j];
						}
					}
				}
			}
		}
	}
  //아무도 이기지 않았다면 진행 중(0)
	return 0;
}

int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> board[i][j];
		}
	}
	int answer = solution();
	cout << answer << "\n";
  //이긴 사람이 있을 때만 가장 왼쪽 돌 위치 출력
  //줄번호는 1번부터니까 1 더해서 출력
	if (answer) {
		cout << stones[0].first + 1 << ' ' << stones[0].second + 1;
	}
	

	return 0;
}
