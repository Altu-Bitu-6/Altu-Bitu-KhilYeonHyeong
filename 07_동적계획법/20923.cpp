#include <iostream>
#include <vector>
#include <deque>

using namespace std;

string playGame(deque<int>dodo, deque<int>su, int n, int m) {
    //도도와 수연의 그라운드
    deque<int>dodo_ground;
    deque<int>su_ground;
    string answer;
    
    //1이면 도도 턴 -1이면 수연 턴
    int turn = 1;
    //도도와 수연이의 현재 패 초기화(관련없는 숫자로...)
    int do_card=100, su_card=100;

    for (int i = 0; i < m; i++) {

        //도도의 턴
        if (turn == 1) {
            //도도 패 내려놓음
            do_card = dodo.front();
            dodo.pop_front();
            dodo_ground.push_front(do_card);
        }
        
        //수연의 턴
        if (turn == -1) {
            su_card = su.front();
            su.pop_front();
            su_ground.push_front(su_card);
        }

        //다음 턴으로 넘어가면 카드 내는 사람 교체
        turn *= -1;

        //종료 조건
        if (dodo.empty() && !su.empty()) { //도도 카드가 다 떨어짐
            return "su";
        }
        else if (su.empty() && !dodo.empty()) { //수연 카드가 다 떨어짐
            return "do";
        }
        else if (dodo.empty() && su.empty()) { //둘 다 떨어짐
            return "dosu";
        }

        //수연이가 치는 조건 : 합이 5고 어느 한쪽의 그라운드도 비어있지 않을 때
        if (!dodo_ground.empty() && !su_ground.empty() && do_card + su_card == 5) { //합이 5면 수연이가 침
            //도도 그라운드에 있는 카드더미를 뒤집어 자신의 덱 아래로 합침
            //그라운드에 있는걸 뒤집어 합쳐야 하니까 pop back
            while (!dodo_ground.empty()) {
                int tmp = dodo_ground.back();
                dodo_ground.pop_back();
                su.push_back(tmp);
            }
            //자기 그라운드에 있는 카드더미도 그 아래로 합침
            while(!su_ground.empty()) {
                int tmp = su_ground.back();
                su_ground.pop_back();
                su.push_back(tmp);
            }
        }
        //도도가 치는 조건 : 현재 패에 5가 등장했을 때
        else if ( (dodo_ground.size() && do_card == 5) || (su_ground.size() && su_card == 5)) { //패에 5가 나오면 도도가 침
            //수연 그라운드의 카드더미 뒤집어 합침
            while (!su_ground.empty()) {
                int tmp = su_ground.back();
                su_ground.pop_back();
                dodo.push_back(tmp);
            }
            //자기 그라운드에 있는 카드더미도 그 아래로 합침
            while (!dodo_ground.empty()) {
                int tmp = dodo_ground.back();
                dodo_ground.pop_back();
                dodo.push_back(tmp);
            }
        }
        //아무도 종 안 치면 그대로 진행
        else {
            continue;
        }
    }

    //m번의 게임이 끝난 뒤 승리 여부 결정
    if (dodo.size() > su.size()) answer = "do";
    else if (dodo.size() < su.size()) answer = "su";
    else answer = "dosu";

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    //도도와 수연이의 카드 저장할 덱
    deque<int>dodo;
    deque<int>su;
    for (int i = 0; i < n; i++) {
        //카드더미의 위 = front
        int d, s;
        cin >> d >> s;
        dodo.push_front(d);
        su.push_front(s);
    }

    cout << playGame(dodo, su, n, m);
    return 0;
}
