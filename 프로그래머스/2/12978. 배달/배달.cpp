#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N+1, INT_MAX);
    vector<vector<pair<int, int>>> graph(N+1);
    for(const vector<int>& e : road) 
    {
        graph[e[0]].push_back({e[1], e[2]});
        graph[e[1]].push_back({e[0], e[2]});
    }
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty())
    {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();
        
        if(curr_dist > dist[curr_node]) continue;
        
        for(const auto& e : graph[curr_node])
        {
            int next_node = e.first;
            int weight = e.second;
            int new_dist = curr_dist + weight;
            
            if(new_dist < dist[next_node])
            {
                dist[next_node] = new_dist;
                pq.push({new_dist, next_node});
            }
        }
    }
    
    for(int i=1; i<=N; ++i)
    {
        if(dist[i] <= K) ++answer;
    }

    return answer;
}