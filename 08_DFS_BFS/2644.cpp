#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<bool>visited;

int bfs(int n, int a, int b, vector<vector<int>>&li) {
  //촌수 저장할 배열
	vector<int>dist(n + 1, -1);
	queue<int> q;

  //첫번째 사람을 시작점으로 bfs
	q.push(a);
	visited[a] = true;
	dist[a] = 0;

	while (!q.empty()) {
		int current_v = q.front();
		q.pop();
    //b에 도달하면 촌수 리턴
		if (current_v == b) {
			return dist[current_v];
		}
		for (int i = 1; i <= n; i++) {
			if (li[current_v][i] == 1 && !visited[i]) {
        //연결되어 있으면 방문 표시, 큐에 삽입, 촌수 증가
				visited[i] = true;
				dist[i] = dist[current_v] + 1;
				q.push(i);
			}
		}
	}
  //친척관계 없으면 -1
	return -1;
}

int main() {
	int n, a,b, m;
	cin >> n >> a>> b>> m;
	visited.assign(n+1, false);
	vector<vector<int>>li(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		li[x][y] = li[y][x] = 1;
	}
	int ans = bfs(n, a, b, li);
	cout << ans;

	return 0;
}
