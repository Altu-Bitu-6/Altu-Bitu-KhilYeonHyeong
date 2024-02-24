#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void nge(vector<int>v, int n) {
	stack<int>s;
	vector<int>res(n);

  //스택에는 들어온 수의 인덱스를 저장함
	for (int i = 0; i < n; i++) {
    //새로 들어온 값이 스택 top을 차지하고 있는 값보다 크면: 새로 들어온 값이 스택top을 차지하고 있는 값의 오큰수
    //결과배열 res의 해당 인덱스에 오큰수 값을 넣어주고, 오큰수를 구했으니 top에 있던 값은 삭제
		while (!s.empty() && (v[i] > v[s.top()])) {
			res[s.top()] = v[i];
			s.pop();
		}
    //다음 요소의 오큰수를 찾기 위해 새로 들어온 값 인덱스를 push
		s.push(i);
	}
  //위 과정으로 입력 배열을 다 돌았는데도 스택에 남아있다는 것 => 오큰수가 없음
	while (!s.empty()) {
		res[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
}

int main() {
	int n;
	cin >> n;
	stack<int>s;
	vector<int>v(n);
	for(int i=0;i<n;i++) {
		cin >> v[i];
	}
	nge(v, n);
}

