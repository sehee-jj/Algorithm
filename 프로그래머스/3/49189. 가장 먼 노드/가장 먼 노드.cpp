#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1);
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    // 그래프 구축
    for(vector<int> e : edge)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty())
    {
        int curr_node = q.front();
        q.pop();
        
        for(int next_node : graph[curr_node])
        {
            if(dist[next_node] >= 0) continue;
            dist[next_node] = dist[curr_node]+1;
            q.push(next_node);
        }
    }
    
    int max_dist = *max_element(dist.begin(), dist.end());
    answer = count(dist.begin(), dist.end(), max_dist);
    
    return answer;
}