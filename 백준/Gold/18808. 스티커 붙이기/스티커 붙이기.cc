#include <iostream>
#include <algorithm>
using namespace std;

#define R first
#define C second

int N, M, K, r, c, cnt=0;
int notebook[40][40], sticker[10][10];

pair<int, int> find_point(int x, int y) {
    for (int i = x; i < N; i++) {
        int j=0;
        if (i == x)
            j = y;
        for (j; j < M; j++) {
            if (notebook[i][j] != sticker[0][0] || sticker[0][0] == 0)
                if (i + r <= N && j + c <= M)
                    return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

bool check_spot(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1 && notebook[i + x][j + y] == 1)
                return false;
        }
    }
    for (int i = x; i < x + r; i++) {
        for (int j = y; j < y + c; j++) {
            if (sticker[i - x][j - y] == 1) {
                notebook[i][j] = 1;
                cnt++;
            }
        }
    }
    return true;
}

bool find_spot() {
    int x = 0, y = 0;
    while (1) {
        auto p = find_point(x, y);
        if (p == make_pair(-1, -1))
            return false;
        if (!check_spot(p.R, p.C)) {
            x = p.R;
            y = p.C+1;
        }
        else
            return true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    while (K--) {
        cin >> r >> c;
        fill_n(sticker[0], 100, 0);
        for (int x = 0; x < r; x++)
            for (int y = 0; y < c; y++)
                cin >> sticker[x][y];
        for (int u = 0; u < 4; u++) {
            if (!find_spot()) {
                int cp[10][10];
                copy(&sticker[0][0], &sticker[0][0] + 100, &cp[0][0]);
                fill_n(sticker[0], 100, 0);
                int temp = r;
                r = c;
                c = temp;
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        sticker[i][j] = cp[c - j - 1][i];
            }
            else
                break;
        }
    }

    cout << cnt;

    return 0;
}