#include <iostream>
#include <vector>

using namespace std;

int pre[10001]; //전위순회 배열
int post[10001]; //후위순회 배열
int postIdx = 0; //후위순회 배열에서 쓸 인덱스

void solution(int x, int y) {
   // 종료조건-끝에 도달
    if (x >= y) return;
    if (x == y - 1) { //마지막 노드 출력
        post[postIdx++] = pre[x];
        return;
    }

    //루트보다 작은 부분이 왼쪽, 큰 부분이 오른쪽
    int idx = x + 1;
    while (idx < y && pre[idx] < pre[x]) { //루트가 작아지는 순간 => 왼쪽서브트리 부분이 끝나는 떄
        idx++;
    }
    solution(x + 1, idx); //왼쪽 서브트리 재귀 호출
    solution(idx, y); //오른쪽 서브트리 재귀 호출
    post[postIdx++] = pre[x];
}

int main() {
    int n, i = 0;
    while (cin >> n) {
        pre[i++] = n;
    }

    solution(0, i);

    for (int j = 0; j < postIdx; j++) {
        cout << post[j] << "\n";
    }

    return 0;
}
