#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#define MAX 1000000
using namespace std;

//소수판정(에라토스테네스의 체)
vector<bool> isPrime(int n) {
	vector<bool>is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (!is_prime[i]) {
			continue;
		}
		for (int j = i * i; j <= n; j += i) {
			if (!is_prime[j]) {
				continue;
			}
			is_prime[j] = false;
		}
	}
	return is_prime;
}

//상근수 판정
bool isSgs(int n) {
  //이미 계산해서 나왔던 수가 다시 나오면 무한 반복되므로 방문여부 기록
	map<int, bool> is_visited;
	int tmp = n;
	while (1) {
		int res = 0;
    //각 자리수 제곱 합 계산
		while (tmp) {
			res += (tmp % 10) * (tmp % 10);
			tmp /= 10;
		}
    //1이 나오면 상근수, 반복 종료
		if (res == 1) {
			return true;
		}
    //처음 나온 숫자라면 방문여부 기록
		if (!is_visited[res]) {
			is_visited[res] = true;
		}
    //이미 나왔던 수라면 상근수 아님
		else {
			return false;
		}
    //다음 반복을 위해 tmp 값 변경
		tmp = res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
  //입력범위 안에서 에라토스테네스의 체로 소수 구하기
	vector<bool>is_prime = isPrime(MAX);
	for (int i = 0; i < n; i++) {
    //소수이면서 상근수라면 소수상근수
		if (is_prime[i] && isSgs(i)) {
			cout << i << "\n";
		}
	}

	return 0;
}