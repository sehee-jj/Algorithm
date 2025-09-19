#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> nodes;

void eraseConnectedNode(int n, int node, const vector<vector<int>>& computers)
{
    for(int i=0; i<n; ++i)
        {
            if(computers[node][i] == 1)
            {
                auto iter = nodes.find(i);
                if(iter != nodes.end())
                {
                    nodes.erase(iter);
                    eraseConnectedNode(n, i, computers);
                }
            }
        }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; ++i) nodes.insert(i);
    
    while(!nodes.empty())
    {
        int curr_node = *nodes.begin();
        nodes.erase(nodes.begin());
        ++answer;
        
        eraseConnectedNode(n, curr_node, computers);
    }
    
    return answer;
}