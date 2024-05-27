#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, input;
    cin >> n;

    vector<int>arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); //이분탐색 위해 정렬

    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> input;
        //존재 여부만 확인하면 되므로 binary_search 함수 사용
        if (binary_search(arr.begin(), arr.end(), input)) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }
    return 0;
}