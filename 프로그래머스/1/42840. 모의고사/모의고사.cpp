#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> scores = {0, 0, 0};
    
    vector<int> pattern1 = {1, 2, 3, 4, 5};
    vector<int> pattern2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> pattern3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == pattern1[i % pattern1.size()]) scores[0]++;
        if(answers[i] == pattern2[i % pattern2.size()]) scores[1]++;
        if(answers[i] == pattern3[i % pattern3.size()]) scores[2]++;
    }
    
    int max_score = *max_element(scores.begin(), scores.end());
    
    for(int i=0; i<scores.size(); i++)
    {
        if(scores[i]==max_score)
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}