#include <iostream>
#include <cmath>
using namespace std;

int r, c, cnt = 0;

void func(int n, pair<int, int> p) {
    if (n == 0) {
        if (p.first == r && p.second == c)
            cout << cnt;
        return;
    }
    int R = p.first;
    int C = p.second;
    if (r < R + (1 << (n - 1))) {
        if (c < C + (1 << (n - 1)))
            func(n - 1, { R, C });
        else {
            cnt += pow((1 << (n - 1)), 2);
            func(n - 1, { R, C + (1 << (n - 1)) });
        }
    }
    else {
        if (c < C + (1 << (n - 1))) {
            cnt += pow((1 << (n - 1)), 2) * 2;
            func(n - 1, { R + (1 << (n - 1)), C });
        }
        else {
            cnt += pow((1 << (n - 1)), 2) * 3;
            func(n - 1, { R + (1 << (n - 1)), C + (1 << (n - 1)) });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N >> r >> c;

    func(N, { 0, 0 });

    return 0;
}