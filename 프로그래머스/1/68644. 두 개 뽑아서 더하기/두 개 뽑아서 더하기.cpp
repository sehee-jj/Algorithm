#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> result;
    sort(numbers.begin(), numbers.end());
    for(int i=0; i<numbers.size(); i++)
    {
        if(i!=0&&numbers[i]==numbers[i-1])
        {
            continue;
        }
        for(int j=i+1; j<numbers.size(); j++)
        {
            if(i!=j-1&&numbers[j]==numbers[j-1])
            {
                continue;
            }
            result.insert(numbers[i]+numbers[j]);
        }
    }
    for(int num : result)
    {
        answer.push_back(num);
    }
    return answer;
}