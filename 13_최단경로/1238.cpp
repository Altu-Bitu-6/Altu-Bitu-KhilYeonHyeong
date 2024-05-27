#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int>ci;
const int INF = 2e5;

//다익스트라 알고리즘
vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
    vector<int>dist(v + 1, INF);
    priority_queue<ci, vector<ci>, greater<>>pq;

    dist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (weight > dist[node]) {
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node });
            }
        }
    }
    return dist;
}

int main() {
    int n, m, x, a, b, w;
    cin >> n >> m >> x;
    vector<vector<ci>>graph(n + 1, vector<ci>(0));
    for (int i = 0; i < m; i++) { //입력값 설정
        cin >> a >> b >> w;
        graph[a].push_back({ b, w });
    }
    int max = 0;
    vector<int>back = dijkstra(x, n, graph); //x에서 집으로 돌아오는 최단경로
    for (int i = 1; i <= n; i++) {
        vector<int>go = dijkstra(i, n, graph); //학생이 집에서 x까지 가는 최단경로
        int res = go[x] + back[i]; //x까지 가는 시간 + x에서 집까지 오는 시간 = 전체시간
        if (res > max) {
            max = res; //최대값 저장
        }
    }
    cout << max;

    return 0;
}
