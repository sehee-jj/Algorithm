#include <iostream>
using namespace std;

int N, S, res = 0, cnt = 0;
int num[20];
bool vis[20] = { 0, };

void find_subseq(int i) {
    if (i == N)
        return;
    for (; i < N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            res += num[i];
            if (res == S)
                cnt++;
            find_subseq(i+1);
            res -= num[i];
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> num[i];

    find_subseq(0);

    cout << cnt;

    return 0;
}