#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int>& stair) {
    //stair[0]: 1번째 계단 점수, stair[1]: 2번째 계단 점수...
    //dp[1] : 1번째 계단을 오르는 최대점수, dp[2]: 2번째 계단을 오르는 최대점수...
    vector<int> dp(n + 1, 0);
    dp[1] = stair[0]; // 첫 번째 계단을 오르는 경우는 한가지
    dp[2] = stair[0] + stair[1]; //두 번째 계단을 오르는 경우도 한가지 (점수가 자연수이니 0에서 2칸 가는것보다 1칸+2칸 가는게 무조건 더 크니까)
    for (int i = 3; i <= n; i++) { //n번째 계단 밟아야 하니까 n까지
        //n-2에서 2칸 오르기 or n-3에서 2칸 + 1칸 오르기 중 큰 값
        dp[i] = max(dp[i - 2] + stair[i - 1], dp[i - 3] + stair[i - 2] + stair[i - 1]);
    }
    return dp[n];
;}

int main() {
    int n;
    cin >> n;
    vector<int> stair(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> stair[i];
    }
    int answer = solution(n, stair);
    cout << answer;
    return 0;
}
