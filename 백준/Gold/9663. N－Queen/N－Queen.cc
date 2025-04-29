#include <iostream>
using namespace std;

int N, cnt = 0;
bool check1[14] = { 0, };
bool check2[27] = { 0, };
bool check3[27] = { 0, };

void func(int k) {
    if (k == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!check1[i] && !check2[k + i] && !check3[k - i + N - 1]) {
            check1[i] = true;
            check2[k + i] = true;
            check3[k - i + N - 1] = true;
            func(k + 1);
            check1[i] = false;
            check2[k + i] = false;
            check3[k - i + N - 1] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    func(0);
    cout << cnt;

    return 0;
}