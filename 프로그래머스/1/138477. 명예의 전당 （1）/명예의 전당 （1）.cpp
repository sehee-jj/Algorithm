#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset<int> ranking;
    
    for (int day_score : score)
    {
        ranking.insert(day_score);
        if (ranking.size() > k)
        {
            ranking.erase(ranking.begin());
        }
        answer.push_back(*ranking.begin());
    }
    return answer;
}