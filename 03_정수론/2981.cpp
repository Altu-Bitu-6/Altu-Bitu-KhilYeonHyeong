#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

/*
	6 = 4*1 + 2
	34 = 4*8 + 2
	38 = 4*9 + 2
  -----------------
	(34-6) = 4*(8-1)
	(38-34) = 4*(9-1)
	...
	-> M은 x[1]-x[0], x[2]-x[1], x[3]-x[2]... 의 공약수
  그 공약수의 1을 제외한 약수들은 모두 M이 될 수 있음
*/

//유클리드 호제법
int gcdIter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

//인접한 두 항의 차를 저장하는 벡터 생성
vector<int> makeDiffVec(vector<int>num) {
	int n = num.size();
	vector<int>diff(n - 1);
	for (int i = 1; i <= n - 1; i++) {
		diff[i - 1] = abs(num[i] - num[i - 1]);
	}
	return diff;
}


vector<int> findNums(vector<int>diff) {
	vector<int>res;
  //차 벡터 요소들의 공약수 구하기
	int gcd = diff[0];
	for (int i = 1; i < diff.size(); i++) {
		gcd = gcdIter(gcd, diff[i]);
	}
  //공약수의 모든 약수 구하기(1은 제외)
	for (int i = 2; i <= gcd / 2; i++) {
		if (gcd % i == 0) {
			res.push_back(i);
		}
	}
  //효율을 위해 gcd/2로 반복했으니 마지막에 자기자신 추가
	res.push_back(gcd);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int>num(n, 0);
	vector<int>diff(n - 1);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	diff = makeDiffVec(num);
	
	vector<int>res = findNums(diff);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
  
	return 0;
}