#include <iostream>
#include <string>
#include <stack>

using namespace std;

void checkBalance(string s, stack<char>basket) {
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
    // 왼쪽 괄호는 스택에 삽입
		case '(': case '[':
			basket.push(s[i]);
			break;
    // 오른쪽 괄호를 만나면 스택의 top을 확인, 짝이 맞으면 스택에 있던 왼쪽 괄호 제거
    // 짝이 안 맞으면 오른쪽 괄호를 push
		case ')':
			if (!basket.empty() && basket.top() == '(') basket.pop();
			else {
				basket.push(')');
			}
			break;
		case ']':
			if (!basket.empty() && basket.top() == '[') basket.pop();
			else {
				basket.push(']');
			}
			break;
		}
	}
  //문자열을 모두 돌았는데 스택이 비어있지 않으면 불균형
	if (basket.empty()) cout << "yes\n";
	else cout << "no\n";
}


int main() {

	while (true) {
		string s;
		getline(cin, s);
		stack<char> basket;
		if (s[0] == '.') break;
		checkBalance(s, basket);
	}
}

