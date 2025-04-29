#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, min;
    cin >> N >> K;
    
    bool vis[100001] = {false,};

    if (N == K) {
        cout << 0;
        return 0;
    }

    queue<pair<int, int>> Q;
    vis[N] = true;
    Q.push({ N, 0 });

    while (!Q.empty()) {
        auto cur = Q.front();
        min = cur.Y + 1;
        Q.pop();

        if (cur.X - 1 == K || cur.X + 1 == K || cur.X * 2 == K) {
            cout << min;
            return 0;
        }
        
        if(cur.X-1>=0&&!vis[cur.X-1]) {
            vis[cur.X-1]=true;
            Q.push({ cur.X - 1, min });
        }
        if(cur.X+1<=100000&&!vis[cur.X+1]) {
            vis[cur.X+1]=true;
            Q.push({ cur.X + 1, min });
        }
        if(cur.X*2<=100000&&!vis[cur.X*2]) {
            vis[cur.X*2]=true;
            Q.push({ cur.X * 2, min });
        }
    }

    return 0;
}