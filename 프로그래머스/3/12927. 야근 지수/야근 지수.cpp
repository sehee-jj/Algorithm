#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    int total = accumulate(works.begin(), works.end(), 0);
    
    if(total <= n) return 0;
    
    for(int i=0; i<n; ++i)
    {
        int temp_work = pq.top()-1;
        pq.pop();
        if(temp_work != 0)
        {
            pq.push(temp_work);
        }
    }
    
    int size = pq.size();
    for(int i=0; i<size; ++i)
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}