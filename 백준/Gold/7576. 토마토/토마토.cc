#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

struct tomato {
    int tmt, day;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, minD = 0;
    cin >> m >> n;

    bool flag = false;

    tomato** basket = new tomato * [n];
    for (int i = 0; i < n; i++) {
        basket[i] = new tomato[m];
        for (int j = 0; j < m; j++) {
            cin >> basket[i][j].tmt;
            basket[i][j].day = -1;
            if (basket[i][j].tmt == 0 && !flag)
                flag = true;
        }
    }

    if (!flag) {
        cout << 0;
        for (int i = 0; i < n; i++)
            delete[] basket[i];
        delete[] basket;
        return 0;
    }

    queue<pair<int, int>> Q;
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto& temp = basket[i][j];
            if (temp.tmt == 1) {
                Q.push({ i, j });
                temp.day = 0;
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (basket[nx][ny].tmt != 0)
                continue;

            Q.push({ nx, ny });

            int nDay = basket[cur.X][cur.Y].day + 1;
            basket[nx][ny].day = nDay;
            basket[nx][ny].tmt = -1;
            minD = nDay;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (basket[i][j].tmt == 0) {
                cout << -1;
                for (int i = 0; i < n; i++)
                    delete[] basket[i];
                delete[] basket;
                return 0;
            }
        }
    }

    cout << minD;

    return 0;
}