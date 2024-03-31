#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int>& a) {
    vector<int>dp(n + 1, 0);
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        //1로 초기화
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) { //이전 값이 작아야 증가하는 부분수열
                dp[i] = max(dp[i], dp[j] + 1); //더 긴 길이가 되도록
            }
        }
        //증가하는 부분수열들 중 가장 긴 길이
        if (max_num < dp[i]) {
            max_num = dp[i];
        }
    }
    return max_num;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int answer = solution(n, a);
    cout << answer;
    return 0;
}
