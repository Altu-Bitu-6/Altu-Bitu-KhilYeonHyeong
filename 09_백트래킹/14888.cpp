#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 11;

int input[MAX]; //피연산자 저장할 배열
int op[4]; //입력받은 각 연산자(+ - * /)의 개수 저장할 배열

int n;
int max_num = -1000000001;
int min_num = 1000000001;

void backtracking(int res, int cnt) {
    if (cnt == n - 1) { //종료조건: 연산자 개수 = 피연산자수-1
        max_num = max(max_num, res);
        min_num = min(min_num, res);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i]>0) { //사용할 연산자가 있으면
            op[i]--; //해당 연산자 하나 사용
            int tmp;
            if (i == 0) { //덧셈
                tmp = res + input[cnt + 1]; //백트래킹 시작 cnt를 0으로 했으니 다음 피연산자를 가져와 계산하기 위해 인덱스를 cnt+1로 사용
            }
            else if (i == 1) { //뺄셈
                tmp = res - input[cnt + 1];
            }
            else if (i == 2) { //
                tmp = res * input[cnt + 1];
            }
            else {
                tmp = res / input[cnt + 1];
            }
            backtracking(tmp, cnt + 1); //백트래킹
            op[i]++; //사용한 연산자 반납
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    backtracking(input[0], 0);
    cout << max_num << '\n' << min_num;
    return 0;
}
