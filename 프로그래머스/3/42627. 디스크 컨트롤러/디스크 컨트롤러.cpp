#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct comp{
    bool operator()(vector<int> A, vector<int> B)
    {
        if(A[1]>B[1]) return true;
        else if(A[1]==B[1]) return A[0]>B[0];
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, comp> ready_queue;
    sort(jobs.begin(), jobs.end());
    int curr_time = 0, total_time = 0, n = jobs.size();
    ready_queue.push(jobs[0]);
    int idx = 1;
    
    while(1)
    {
        if(ready_queue.size() != 0)
        {
            vector<int> next_job = ready_queue.top();
            ready_queue.pop();
            if(next_job[0] > curr_time) curr_time = next_job[0];
            curr_time += next_job[1];
            total_time += curr_time - next_job[0];
        }
        
        for(; idx<n; ++idx)
        {
            if(ready_queue.size() == 0 || jobs[idx][0] <= curr_time)
            {
                ready_queue.push(jobs[idx]);
            }
            else break;
        }
        
        if(ready_queue.size() == 0) break;
    }
    
    answer = total_time/n;
    
    return answer;
}