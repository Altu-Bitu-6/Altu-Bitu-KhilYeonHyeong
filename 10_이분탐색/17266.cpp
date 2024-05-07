#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;

bool checkLight(int h, vector<int>&arr) {
    if (arr[0] - h > 0) { //첫번째 위치 -가로등 길이 h가 길의 맨 처음까지 비출 수 없다면 불가
        return false;
    }
    if (arr[arr.size()-1] + h < n) { //마지막 위치 - 가로등이 길 끝까지 비출 수 있는지 확인
        return false;
    }
    for (int i = 1; i < m; i++) { //중간 위치
        if (arr[i - 1] + h < arr[i] - h) { //이전 가로등이 비추는 오른쪽 끝과 현재 가로등이 비추는 왼쪽 끝 비교
            return false;
        }
    }
    return true;
}

int solution(int left, int right, vector<int>& arr) {
    int answer = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (checkLight(mid, arr)) { //비출 수 있다면 - 최소높이 찾아야하니 왼쪽으로 탐색
            right = mid - 1;
            answer = mid;
        }
        else { //비출 수 없다면 - 높이 늘리기
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    vector<int> arr(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    cout << solution(0, n, arr);
    
    return 0;
}