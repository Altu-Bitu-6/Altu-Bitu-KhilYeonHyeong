#include <iostream>
#include <vector>
#include <string>

using namespace std;

//단어가 가진 알파벳 개수 저장한 배열을 리턴하는 함수
vector<int> wordCount(string s) {
	vector<int>cnt(26, 0);
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'A']++;
	}
	return cnt;
}

int solution(int n, vector<string>vec) {
	int res = 0;
  //첫 번째 단어
	string target = vec[0];
	vector<int>target_cnt = wordCount(target);
  //두 번째 단어부터 순차적으로 비교
	for (int i = 1; i < vec.size(); i++) {
		int flag = 0;
		int a = 0, b = 0;
    //비교할 단어
		string cmp = vec[i];
		vector<int>cmp_cnt = wordCount(cmp);
    //비슷한 단어: 같은 구성이거나, 각 글자의 개수 차이가 한개 이하로 나야 함 (+개수차이가 나는 알파벳이 여러개면 안됨)
		for (int j = 0; j < 26; j++) {
      //개수 같으면 넘어감
			if (target_cnt[j] == cmp_cnt[j]) continue;
      //개수 차이가 두개 이상이면 안됨
			if (abs(target_cnt[j] - cmp_cnt[j]) > 1) {
				flag = 1;
				break;
			}
      //개수 차이가 한개
			else if (target_cnt[j] < cmp_cnt[j]) {
				a++;
			}
			else if (target_cnt[j] > cmp_cnt[j]) {
				b++;
			}
      //개수 차이가 한개여도 그런 문자가 여러개면 안됨
			if (a > 1 || b > 1) {
				flag = 1;
				break;
			}
		}
    //비슷한 단어가 아니면 결과값 추가하지 않음
		if (flag == 1) continue;
		res++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	cout << solution(n, vec);
	return 0;
}