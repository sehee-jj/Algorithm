#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int start = section[0];
    for(int wall_num : section)
    {
        if(start <= wall_num)
        {
            ++answer;
            start = wall_num+m;
        }
    }
    return answer;
}