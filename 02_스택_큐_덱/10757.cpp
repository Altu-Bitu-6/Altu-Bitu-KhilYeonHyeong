#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sum(string a, string b) {
  //숫자를 문자열로 받고, 0000xxx와 같은 형태로 확장해서 자릿수별로 계산
	int carry = 0;
	string result;
  //확장시 길이는 긴 쪽(자릿수 더 많은 쪽)에 맞춤
	int len = max(a.length(), b.length());
	a = string(len - a.length(), '0') + a;
	b = string(len - b.length(), '0') + b;
  //낮은 자릿수부터 계산
  for (int i = len - 1; i >= 0; i--) {
    //같은 자릿수의 두 숫자 합
    int tmp_sum = (a[i] - '0') + (b[i] - '0') + carry;
    //합이 10보다 클 경우 다음 자릿수 계산 시 1 더함
    if (tmp_sum > 9) carry = 1;
    else carry = 0;
    //result에는 앞에서부터 string으로 저장
    result += (tmp_sum % 10) + '0';
  }
  //맨 마지막에 carry 값 남았는지 확인
	if (carry == 1) result += '1';
  //각 자릿수 계산 결과값은 일의자리부터 result에 순서대로 저장되었으므로 실제 결과는 reverse해줘야 함
	reverse(result.begin(), result.end());
	return result;
}


int main() {
	string a, b;
	cin >> a >> b;
	cout << sum(a, b);
}

