#include <iostream>
#include <string>
#include <stack>

using namespace std;

//연산자 우선순위 판별 함수
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void toPostfix(string exp) {
	char ch, top_op;
	int len = exp.length();
	stack<char>s;
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
    //연산자: 스택에 존재하는 연산자가 현재 처리중인 연산자보다 우선순위가 높으면 높은 것을 pop
		case '+': case '-': case '/': case '*':
			while (!s.empty() && (prec(s.top()) >= prec(ch)) ) {
				cout << s.top();
				s.pop();
			}
			s.push(ch);
			break;
    //왼쪽괄호: 스택에 삽입
		case '(':
			s.push(ch);
			break;
    //오른쪽괄호: 스택 안의 왼쪽 괄호가 없어질 때까지 왼쪽 괄호 위의 모든 연산자 출력
		case ')':
			top_op = s.top();
			s.pop();
			while (top_op != '(') {
				cout << top_op;
				top_op = s.top();
				s.pop();
			}
			break;
    //피연산자는 그냥 출력
		default:
			cout << ch;
			break;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	string exp;
	cin >> exp;
	toPostfix(exp);
}

