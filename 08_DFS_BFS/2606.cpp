#include <iostream>
#include <vector>

using namespace std;
vector<bool>visited;

int dfs(int n, int index, vector<vector<int>>&li) {
	visited[index] = true;
  //감염된 컴퓨터 개수 1로 초기화
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (li[index][i] == 1 && !visited[i]) { //아직 방문하지 않았고 연결되어 있다면
			cnt+=dfs(n, i, li); //감염된 컴퓨터 개수 추가
		}
	}
	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;
	visited.assign(n, false);
	vector<vector<int>>li(n+1, vector<int>(n+1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		li[a][b] = li[b][a] = 1;
	}

  //1번 컴퓨터 방문
	visited[1] = true;
  //1번 컴퓨터로부터 전파될 수 있는 컴퓨터 개수
	int answer = dfs(n,1, li);
  //1번 컴퓨터는 개수에 포함X
	cout << answer - 1;

	return 0;
}
