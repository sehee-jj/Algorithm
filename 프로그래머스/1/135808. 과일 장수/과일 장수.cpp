#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int idx = score.size()-m;
    sort(score.begin(), score.end());
    
    for(int idx = score.size()-m; idx >= 0; idx-=m)
    {
        answer += score.at(idx) * m;
    }
    
    return answer;
}