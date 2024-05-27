#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[6][2]; //들어오는 6개의 입력을 저장할 배열
int dir[4]; //각 방향별 들어온 횟수 저장할 배열

int solution(int k) {
    //각 방향의 등장 횟수 세기
    for (int i = 0; i < 6; i++) {
        dir[board[i][0]]++;
    }

    //육각형 넓이 = 큰 사각형 - 작은 사각형
    
    int a1 = 1, a2 = 1;
    for (int i = 0; i < 6; i++) {
        //큰 사각형 넓이 = 한 번씩 나오는 방향으로 갔을 때의 길이 곱
        if (dir[board[i][0]] == 1) {
            a1 *= board[i][1];
            continue;
        }
        //작은 사각형 넓이 = 번갈아 반복되는 방향(ex 1313, 4242...)에서 2,3번째로 등장하는 길이 곱
        //231423처럼 양끝으로 연결될 수도 있으니 6으로 나눈 나머지로 인덱스 지정
        if (board[i][0] == board[(i + 2) % 6][0]) {
            a2 *= board[(i + 1) % 6][1];
        }
    }

    int area = a1 - a2;
    return area * k;

}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < 6; i++) {
        cin >> board[i][0] >> board[i][1];
    }
    cout << solution(k);
    return 0;
}
