#include <iostream>
#include <vector>

using namespace std;
const int MAX = 9;

//각 열/행/3x3정사각형에 해당 숫자가 이미 존재하는지 확인
bool check_row[MAX][MAX + 1];
bool check_col[MAX][MAX + 1];
bool check_3x3[MAX][MAX + 1];

int get33Index(int row, int col) { //해당 칸의 3x3정사각형 인덱스 반환
	return (row / 3) * 3 + (col / 3);
}

bool fillSudoku(int idx, vector<vector<int>>*sudoku) {
	//종료 조건: 모든 칸 확인 완료
	if (idx == MAX * MAX) return true;
	int row = idx / MAX;
	int col = idx % MAX;

	if ((*sudoku)[row][col] != 0) { //이미 숫자가 채워진 칸이면
		return fillSudoku(idx + 1, sudoku); //다음 칸으로 넘어감
	}

	for (int i = 1; i <= MAX; i++) {
		//아직 채워지지 않은 숫자라면
		if (!check_row[row][i] && !check_col[col][i] && !check_3x3[get33Index(row, col)][i]) {
			//칸 채우기
			check_row[row][i] = true;
			check_col[col][i] = true;
			check_3x3[get33Index(row,col)][i] = true;
			(*sudoku)[row][col] = i;
			//백트래킹
			if (fillSudoku(idx + 1, sudoku)) {
				return true;
			}
			//숫자 반납, 칸도 다시 비우기
			check_row[row][i] = false;
			check_col[col][i] = false;
			check_3x3[get33Index(row, col)][i] = false;
			(*sudoku)[row][col] = 0;
		}
	}
	//위에서 다 안됐으면... 채울 수 없음
	return false;
}

vector<vector<int>> solution(vector<vector<int>> sudoku) {
	vector<vector<int>>answer(MAX, vector<int>(MAX));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
      //입력받은 스도쿠 옮기기
			answer[i][j] = sudoku[i][j];
			if (sudoku[i][j]) { //체크 배열 표시
				check_row[i][sudoku[i][j]] = true;
				check_col[j][sudoku[i][j]] = true;
				check_3x3[get33Index(i,j)][sudoku[i][j]] = true;
			}
		}
	}
	fillSudoku(0, &answer);
	return answer;
}

int main() {
	vector<vector<int>> sudoku(MAX, vector<int>(MAX));

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> sudoku[i][j];
		}
	}

	auto output = solution(sudoku);

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << output[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
