#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    
    dist[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty())
    {
        pair<int, int> curr = q.front(); q.pop();
        for(int i=0; i<4; ++i)
        {
            int next_x = curr.first + dx[i];
            int next_y = curr.second + dy[i];
            int next_dist = dist[curr.first][curr.second]+1;
            
            if(next_x < n && next_x >= 0 && next_y < m && next_y >= 0)
            {
                if(next_x == n-1 && next_y == m-1)
                {
                    return next_dist;
                }
                else if(maps[next_x][next_y] == 1 && dist[next_x][next_y] == -1)
                {
                    dist[next_x][next_y] = next_dist;
                    q.push({next_x, next_y});
                }
            }
            //if(next_x >= n || next_x < 0 || next_y >= m || next_y < 0) continue;
            //if(maps[next_x][next_y] != 1 || dist[next_x][next_y] != -1) continue;
            
        }
    }
    
    return -1;
}