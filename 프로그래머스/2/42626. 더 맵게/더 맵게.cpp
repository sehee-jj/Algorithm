#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(1)
    {
        if(pq.top() >= K)
        {
            return answer;
        }
        else if(pq.size() < 2)
        {
            return -1;
        }
        
        int min = pq.top();
        pq.pop();
        int next_min = pq.top();
        pq.pop();
        
        pq.push(min + next_min*2);
        ++answer;
    }
}