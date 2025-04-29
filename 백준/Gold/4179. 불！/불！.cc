#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define X first
#define Y second

struct state {
    char st;
    int time;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C, min = 0;
    cin >> R >> C;

    queue<pair<int, int>> JQ;
    queue<pair<int, int>> FQ;
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    state** maze = new state * [R];

    for (int i = 0; i < R; i++) {
        maze[i] = new state[C];
        for (int j = 0; j < C; j++) {
            cin >> maze[i][j].st;
            maze[i][j].time = INT_MAX;

            if (maze[i][j].st == 'J') {
                maze[i][j].time = 0;
                JQ.push({ i, j });
            }
            else if (maze[i][j].st == 'F') {
                maze[i][j].time = 0;
                FQ.push({ i, j });
            }
        }
    }

    while (!FQ.empty()) {
        auto curF = FQ.front();
        min = maze[curF.X][curF.Y].time + 1;
        FQ.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nxF = curF.X + dx[dir];
            int nyF = curF.Y + dy[dir];

            if (nxF < 0 || nxF >= R || nyF < 0 || nyF >= C)
                continue;
            if (maze[nxF][nyF].st != '#' && maze[nxF][nyF].time > min) {
                maze[nxF][nyF].time = min;
                FQ.push({ nxF, nyF });
            }
        }
    }

    /*for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j].st != '#')
                cout << maze[i][j].time;
            else
                cout << '#';
        }
        cout << endl;
    }*/

    while (!JQ.empty()) {
        auto curJ = JQ.front();
        min = maze[curJ.X][curJ.Y].time + 1;
        JQ.pop();

        for (int i = 0; i < 4; i++) {
            int nxJ = curJ.X + dx[i];
            int nyJ = curJ.Y + dy[i];

            if (nxJ < 0 || nxJ >= R || nyJ < 0 || nyJ >= C) {
                cout << min;
                for (int i = 0; i < R; i++)
                    delete[] maze[i];
                delete[] maze;
                return 0;
            }

            if (maze[nxJ][nyJ].st == '.' && maze[nxJ][nyJ].time > min) {
                maze[nxJ][nyJ].time = min;
                JQ.push({ nxJ, nyJ });
            }
        }

    }

    cout << "IMPOSSIBLE";

    for (int i = 0; i < R; i++)
        delete[] maze[i];
    delete[] maze;

    return 0;
}