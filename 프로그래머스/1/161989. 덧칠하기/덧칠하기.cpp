#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int start = 0;
    while(start < section.size())
    {
        ++answer;
        
        int wall_num = section[start++]+m;
        int i=start;
        
        for(i; i<section.size(); i++)
        {
            if(wall_num<=section[i])
            {
                start = i;
                break;
            }
        }
        
        if(i==section.size()) break;
    }
    return answer;
}