#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> li; //톱니바퀴를 저장
//li[0] : 1번째 톱니바퀴, li[1]: 2번째 톱니바퀴, ...

vector<pair<int, int>> stack; //돌려야하는 톱니바퀴 인덱스와 방향
vector<int>visited; //검사한 톱니바퀴를 다시 검사하면 올바르지 않은 결과가 나오므로 검사여부 표시

//톱니바퀴 회전을 확인하는 함수
void check_rotation(int current_num, int current_dir) {
	//매개변수: 현재 기준이 되는 바퀴의 인덱스와 회전 방향

	//왼쪽에 있는 톱니바퀴가 회전하는지 검사
	if (current_num - 1 >= 0 && visited[current_num - 1] == 0) { //왼쪽에 톱니바퀴가 있고, 아직 검사하지 않은 상태여야 회전가능
		//나의 6번째 톱니와 내 왼쪽의 2번째 톱니 비교
		if (li[current_num][6] != li[current_num-1][2]) { //맞물린 톱니가 다른 극이면 회전해야 함
			stack.push_back(make_pair(current_num - 1, current_dir * -1)); //왼쪽 톱니바퀴를 반대 방향으로 회전
			visited[current_num - 1] = 1; //검사했음을 표시
			check_rotation(current_num - 1, current_dir * -1); //왼쪽 톱니바퀴에 대해 재귀호출
		}
	}
	//오른쪽에 있는 톱니바퀴가 회전하는지 검사
	if (current_num + 1  < li.size() && visited[current_num + 1] == 0) { //오른쪽에 톱니바퀴가 있고, 아직 검사하지 않은 상태여야 회전가능
		//나의 2번째 톱니와 내 왼쪽의 6번째 톱니 비교
		if (li[current_num][2] != li[current_num+1][6]) { //맞물린 톱니가 다른 극이면 회전해야 함
			stack.push_back(make_pair(current_num + 1, current_dir * -1)); //오른쪽 톱니바퀴를 반대 방향으로 회전
			visited[current_num + 1] = 1; //검사했음을 표시
			check_rotation(current_num + 1, current_dir * -1); //오른쪽 톱니바퀴에 대해 재귀호출
		}
	}
}

int main() {
	int t; //톱니바퀴의 개수
	cin >> t; //입력
	li.resize(t); //t만큼 li 할당
	for (int i = 0; i < t; i++) { //톱니바퀴 극 정보
		cin >> li[i]; //입력
	}
	int k; //회전횟수
	cin >> k; //입력
	for (int i = 0; i < k; i++) { //첫번째로 돌려야 할 톱니바퀴에 대해 바로 돌리기
		int num, direction; //회전한 톱니바퀴 인덱스, 방향
		cin >> num >> direction; //입력
		stack.clear(); //매 회전마다 새로 받아야 하므로 스택 초기화
		stack.push_back(make_pair(num - 1, direction)); //회전 정보를 저장. 톱니바퀴 인덱스는 톱니바퀴번호 - 1
		visited.assign(t, 0); //방문 여부 표시를 위한 배열 할당
		visited[num - 1] = 1; //첫번째 톱니바퀴에 방문 표시
		
		//돌릴 톱니바퀴 체크
		check_rotation(num - 1, direction);

		//돌려야 하는 톱니바퀴를 모두 체크한 이후
		while (!stack.empty()) {
			pair<int, int> top = stack.back(); //회전 정보를 스택에서 꺼냄
			stack.pop_back(); //스택에서 삭제
			int tmp_num = top.first; //현재 돌려야 할 톱니바퀴 인덱스
			int tmp_dir = top.second; //현재 돌려야할 톱니바퀴 방향
			if (tmp_dir == 1) { //시계방향이면
				li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7); //맨 뒤였던 것을 맨 앞으로 하고 나머지 붙이기
			}
			else { //반시계 방향이면
				li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0]; //1번째~7번째 인덱스를 맨앞으로 옮기고 0번째 인덱스를 맨 뒤로 붙이기
			}
		}
	}
	//12시 방향(0번인덱스)이 S극인 톱니바퀴 개수 세기
	int cnt = 0; //구해야 할 값
	for (int i = 0; i < t; i++) { //각 톱니바퀴 검사
		if (li[i][0] == '1') { //0번인덱스가 1이면(==S극이면)
			cnt++; //1 더하기
		}
	}
	cout << cnt; //결과값 출력
	return 0;
}
