#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define MAX 1000000

using namespace std;

//에라토스테네스의 체
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

string goldbach(int n, vector<bool>& is_prime) {
	string s = "Goldbach's conjecture is wrong.";
  //두 수는 무조건 홀수여야 함
	for (int i = 1; i <= (n/2); i=i+2) {
		int tmp = n - i;
    //i(=a)=1부터 도니까 b-a는 계속 작아질것...
    //a,b 모두 소수이고 b도 홀수라면 골드바흐 추측대로 나타낼 수 있으니 식 출력하고 중단
		if (is_prime[i] && is_prime[tmp] && tmp % 2 != 0) {
			s = to_string(n) + " = " + to_string(i) + " + " + to_string(tmp);
			break;
		}
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
  //시간초과를 막기 위해 인풋값 맥스로 미리 소수배열 구해놓고 시작..
	vector<bool>is_prime = isPrime(MAX);
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << goldbach(n, is_prime) << "\n";
	}
	return 0;
}

