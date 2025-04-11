#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getRanking(int num)
{
    switch(num)
    {
        case 0:
        case 1:
            return 6;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 1;
        default:
            return 0;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_cnt = 0;
    int winning_cnt = 0;
    for(int num : lottos)
    {
        if(num == 0)
        {
            zero_cnt++;
        }
        else
        {
            auto it = find(win_nums.begin(), win_nums.end(), num);
            if(it != win_nums.end())
            {
                winning_cnt++;
            }
        }
    }
    
    answer.push_back(getRanking(winning_cnt+zero_cnt));
    answer.push_back(getRanking(winning_cnt));
    
    return answer;
}