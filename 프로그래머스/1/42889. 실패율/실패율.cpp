#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int x, int y)
{
    return x > y;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    vector<float> failure_rate(N, 0.f);
    
    sort(stages.begin(), stages.end(), compare);
    
    for(int i=1; i<=N; ++i)
    {
        int clear_x =0, clear_o = 0;
        
        for(int stage : stages)
        {
            if(i <= stage) 
            {
                ++clear_o;
                if(i == stage) 
                    ++clear_x;
            }
            else break;
        }
        
        if(clear_o != 0)
        {
            failure_rate[i-1] = (float) clear_x/clear_o;
        }
    }
    
    for(int i=0; i<N; ++i)
    {
        auto max_idx = max_element(failure_rate.begin(), failure_rate.end());
        answer[i] = max_idx - failure_rate.begin() + 1;
        cout << *max_idx << endl;
        *max_idx = -1;
    }
    
    return answer;
}