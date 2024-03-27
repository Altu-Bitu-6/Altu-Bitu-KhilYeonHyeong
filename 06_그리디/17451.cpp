#include <iostream>
#include <vector>

using namespace std;

long solution(int n, vector<int>& arr) {
	//속도는 줄어들 수는 있지만 늘어날 수는 없으므로 뒤에서부터 탐색
	long answer = arr[n-1];
	for (int i = n - 2; i >= 0; i--) {
		if (answer < arr[i]) { //이전 것이 더 크면 속도가 감소해야 함
			answer = arr[i];
		}
		else { //이전것이 더 작으면 이전것의 배수여야 함
			if (answer % arr[i] != 0) {
        //배수이면서 answer보다 더 빨라야 함
				answer = (answer / arr[i] + 1) * arr[i];
			}
		}
	}
	return answer;
}

int main() {
	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << solution(n, arr);
	return 0;
	
}
