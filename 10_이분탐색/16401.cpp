#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int m, n;

int solution(int left, int right, vector<int>& arr) {
    int answer = 0;
    while (left <= right) { //나눠줄 수 있는 길이로 이분탐색
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += floor(arr[i] / mid); //해당 길이로 얻을 수 있는 과자 개수
        }
        if (cnt >= m) { //나눠줄 수 있으면 - 최대길이 구해야 하니까 오른쪽으로 탐색
            left = mid + 1;
            answer = mid;
        }
        else { //나눠줄 수 없으면 - 길이 줄여서 왼쪽으로 탐색
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << solution(1, arr[n - 1], arr);
    
    return 0;
}