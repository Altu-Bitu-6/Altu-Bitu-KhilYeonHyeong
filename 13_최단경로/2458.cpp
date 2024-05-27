#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e7;

//플로이드-워셜 알고리즘
void floyd(int n, vector<vector<int>>& graph) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>>graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) { //자기자신과의 거리
        graph[i][i] = 0;
    }
    for (int i = 0; i < m; i++) { //키순서가 주어져있으면 1 표시
        cin >> a >> b;
        graph[a][b] = 1;
    }
    floyd(n, graph);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] != INF || graph[j][i] != INF) { //상호 키 순위를 알 수 있으면 cnt 증가
                cnt++;
            }
        }
        if (cnt==n){ //모두와의 순위를 알 수 있다면 ans(정답 값) 증가
            ans++;
        }
    }
    
    cout << ans;

    return 0;
}
