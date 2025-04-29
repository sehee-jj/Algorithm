#include <iostream>
#include <climits>
#include <queue>
using namespace std;

#define X first
#define Y second

struct route {
    int road, dis;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    route** maze = new route * [n];

    for (int i = 0; i < n; i++) {
        maze[i] = new route[m];
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            maze[i][j].road = input[j]-'0';
            maze[i][j].dis = -1;
        }
    }

    queue<pair<int, int>> Q;
    Q.push({ 0,0 });
    maze[0][0].dis = 1;

    while (!Q.empty()) {
        auto cur = Q.front();
        int curDis = maze[cur.X][cur.Y].dis + 1;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            auto& tmp = maze[nx][ny];

            if (!tmp.road || tmp.dis >= 0)
                continue;

                tmp.dis = curDis;
                Q.push({ nx, ny });
        }
    }

    cout << maze[n - 1][m - 1].dis;

    for (int i = 0; i < n; i++)
        delete[] maze[i];
    delete[] maze;

    return 0;
}