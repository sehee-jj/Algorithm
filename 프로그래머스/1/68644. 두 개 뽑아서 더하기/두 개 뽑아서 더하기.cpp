#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> result;
    
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            result.insert(numbers[i]+numbers[j]);
        }
    }
    
    for(int num : result)
    {
        answer.push_back(num);
    }
    
    return answer;
}