#include <iostream>
#include <vector>
#include <string>

using namespace std;
int cnt[10]; // 0~9까지 숫자 개수
int answer = 0;

//소수 판정
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void backtracking(string res, int idx, int len) {
    //종료: 지정한 길이에 도달
    if (idx == len) {
        int tmp = stoi(res);
        //소수면 정답 개수 추가
        if (isPrime(tmp)) {
            answer++;
        }
        return;
    }

    //0부터 9까지 숫자 넣어보기
    for (int i = 0; i < 10; i++) {
      //해당 숫자가 더 이상 없거나 처음에 오는 0은 무시
        if (cnt[i] == 0 || (idx == 0 && i == 0)) continue;
        //해당 숫자 사용
        cnt[i]--;
        //백트래킹
        backtracking(res + to_string(i), idx + 1, len);
        //숫자 반납
        cnt[i]++;
    }
}

int solution(string numbers) {
  //입력 스트링에서 각 숫자의 개수 세어 cnt에 저장
    for (int i = 0; i < numbers.size(); ++i) {
        cnt[numbers[i] - '0']++;
    }
    int len = numbers.length();
    for (int i = 1; i <= len; i++) {
        //만들어진 숫자의 길이(1~len) 전부 탐색
        backtracking("", 0, i);
    }
    return answer;
}

int main() {
    string input;
    cin >> input;
    cout << solution(input);
    return 0;
}