#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int** input = new int* [n];

    for (int i = 0; i < n; i++) {
        input[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
        }
    }

    int paint = 0, width = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] == 1) {
                int tmp_width = 0;
                queue<pair<int, int>> vis;
                vis.push({ i, j });
                input[i][j] = 0;
                paint++;
                while (!vis.empty()) {
                    auto pos = vis.front();
                    tmp_width++;
                    vis.pop();
                    if (pos.first + 1 < n && input[pos.first + 1][pos.second] == 1) {
                        input[pos.first + 1][pos.second] = 0;
                        vis.push({ pos.first + 1, pos.second });
                    }
                    if (pos.first - 1 >= 0 && input[pos.first - 1][pos.second] == 1) {
                        input[pos.first - 1][pos.second] = 0;
                        vis.push({ pos.first - 1, pos.second });
                    }
                    if (pos.second + 1 < m && input[pos.first][pos.second + 1] == 1) {
                        input[pos.first][pos.second + 1] = 0;
                        vis.push({ pos.first, pos.second + 1 });
                    }
                    if (pos.second - 1 >= 0 && input[pos.first][pos.second - 1] == 1) {
                        input[pos.first][pos.second - 1] = 0;
                        vis.push({ pos.first, pos.second - 1 });
                    }
                }
                width = max(width, tmp_width);
            }
        }
    }

    cout << paint << "\n";
    cout << width;

    return 0;
}