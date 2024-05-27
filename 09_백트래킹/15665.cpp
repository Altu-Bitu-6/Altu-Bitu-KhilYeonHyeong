#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
const int MAX = 7;

int n, m;
int sequence[MAX];
set<vector<int>> result; //중복을 출력하지 않기 위해 결과를 set에 저장

void backtracking(int cnt, vector<int>& arr) {
    if (cnt == m) { //종료조건: m개의 수를 모두 고름
        vector<int>tmp; //수열을 result에 옮겨야 하므로 sequence에 있는 int들을 옮겨담을 tmp 벡터 설정
        for (int i = 0; i < m; i++) {
            tmp.push_back(sequence[i]);
        }
        result.insert(tmp); //set에 수열을 insert
        tmp.clear(); //tmp는 초기화
        return;
    }

    //같은 수 여러 번 골라도 되므로 다른 조건 없이 그냥 반복문에 순환호출
    for (int i = 0; i < n; i++) {
        sequence[cnt] = arr[i];
        backtracking(cnt + 1, arr);
    }
}

int main() {
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); // 입력된 수열을 사전 순으로 정렬
    backtracking(0, arr);
    
    //set 출력
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        vector<int> res = *iter;
        for (int i = 0; i < m; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
