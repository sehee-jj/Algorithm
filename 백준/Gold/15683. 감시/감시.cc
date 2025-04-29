#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define R first
#define C second

int N, M, w = 0, BS_min = 64;
int office[8][8];
bool range[8][8];
vector<pair<int, int>> cctv;

int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };

void change_T(int r, int c, int dir) {
    dir %= 4;
    while (1) {
        r += dr[dir];
        c += dc[dir];
        if (r < 0 || r >= N || c < 0 || c >= M)
            break;
        if (office[r][c] == 6)
            break;
        if (office[r][c] == 0)
            range[r][c] = true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> office[i][j];
            if (office[i][j] > 0) {
                if (office[i][j] == 6)
                    w++;
                else
                    cctv.push_back({ i, j });
            }
        }
    }

    for (int i = 0; i < (1 << (2 * cctv.size())); i++) {
        fill_n(&range[0][0], 64, false);
        int tmp = i;
        for (int j = 0; j < cctv.size(); j++) {
            int dir = tmp % 4;
            tmp /= 4;
            int r = cctv[j].R;
            int c = cctv[j].C;
            switch (office[r][c]) {
            case 1:
                change_T(r, c, dir);
                break;
            case 2:
                change_T(r, c, dir);
                change_T(r, c, dir + 2);
                break;
            case 3:
                change_T(r, c, dir);
                change_T(r, c, dir + 1);
                break;
            case 4:
                change_T(r, c, dir);
                change_T(r, c, dir + 1);
                change_T(r, c, dir + 2);
                break;
            case 5:
                change_T(r, c, dir);
                change_T(r, c, dir + 1);
                change_T(r, c, dir + 2);
                change_T(r, c, dir + 3);
                break;
            }
        }
        int BS = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!range[i][j])
                    BS++;
            }
        }
        BS += w * (-1) - static_cast<int>(cctv.size());
        BS_min = min(BS, BS_min);
    }

    cout << BS_min;

    return 0;
}