#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree; //정점 u를 루트로 하는 서브트리에 속한 정점개수

int solution(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true; //정점 방문 표시
    int cnt = 1;
    //정점 수 구하기
    for (int child : graph[node]) {
        if (!visited[child]) { //방문하지 않은 정점만 탐색
            cnt += solution(child, graph, visited);
        }
    }
    subtree[node] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, q, v1, v2, x;
    cin >> n >> r >> q;
    vector<vector<int>> graph(n + 1);
    subtree.resize(n + 1, 0);
    vector<bool> visited(n + 1, false); //방문여부 기록 배열

    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    solution(r, graph, visited);

    for (int i = 0; i < q; i++) {
        cin >> x;
        cout << subtree[x] << "\n";
    }

    return 0;
}
