#include <string>
#include <vector>
#include <map>

using namespace std;


vector<int> M2 = {1, 3, 4, 5};
vector<int> M3 = {3, 1, 2, 4, 5};
int M2_idx = 0;
int M3_idx = 0;

bool isCorrectM1(int idx,  int correct_answer)
{
    int answer = idx%5+1;
    if(answer == correct_answer)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isCorrectM2(int idx,  int correct_answer)
{
    bool result = false;
    
    if(idx%2 == 0)
    {
        if(correct_answer == 2)
        {
            result = true;
        }
    }
    else
    {
        if(M2[M2_idx%4] == correct_answer)
        {
            result = true;
        }
        M2_idx++;
    }
    
    return result;
}

bool isCorrectM3(int idx,  int correct_answer)
{
    bool result = false;
    
    if(correct_answer == M3[M3_idx%5])
    {
        result = true;
    }
    
    if(idx%2 == 1)
    {
        M3_idx++;
    }
    
    return result;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    map<int, int> result;
    int M1_ID = 1;
    int M2_ID = 2;
    int M3_ID = 3;
    
    for(int i=1; i<=3; i++)
    {
        result.insert({i, 0});
    }
    
    for(int i=0; i<answers.size(); i++)
    {
        if(isCorrectM1(i, answers[i]))
        {
            result[M1_ID]++;
        }
        
        if(isCorrectM2(i, answers[i]))
        {
            result[M2_ID]++;
        }
        
        if(isCorrectM3(i, answers[i]))
        {
            result[M3_ID]++;
        }
    }
    
    int max_score = 0;
    for(auto res_math : result)
    {
        int man = res_math.first;
        int score = res_math.second;
        if(max_score < score)
        {
            max_score = score;
            answer.clear();
            answer.push_back(man);
        }
        else if(max_score == score)
        {
            answer.push_back(man);
        }
    }
    
    return answer;
}