#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	
	int w0, i0, t; //전 체중, 일일에너지섭취(=일일기초대사), 변화역치
	cin >> w0 >> i0 >> t;
	int d, i, a; //다이어트기간, 일일에너지섭취, 일일활동대사
	cin >> d >> i >> a;
	int cons = 0; //일일에너지소비
	int new_i = i0;
	int new_w = w0;
	int w = w0;


	for (int j = 0; j < d; j++) {
		cons = i0 + a;
		w += (i - cons);
	}
	if (w <= 0) {
		cout << "Danger Diet\n";
	}
	else {
		cout << w << ' ' << i0 << '\n';
	}
	
	/**/
	for (int j = 0; j < d; j++) {
		cons = new_i + a;
		new_w += (i - cons);
		if (abs(i - cons) > t) {
			new_i += floor((i - cons) / 2.0);
		}
	}

	string y;
	if ((i0 - new_i) <= 0) {
		y = "NO";
	}
	else {
		y = "YOYO";
	}

	if (new_w <= 0 || new_i <=0) {
		cout << "Danger Diet\n";
	}
	else {
		cout << new_w << ' ' << new_i << ' ' << y;
	}	
}
