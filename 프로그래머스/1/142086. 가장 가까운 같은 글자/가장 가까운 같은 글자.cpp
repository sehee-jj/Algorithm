#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> alphabet;
    for(int i=0; i<s.length(); i++)
    {
        if(alphabet.find(s[i]) == alphabet.end())
        {
            alphabet.insert({s[i], i});
            answer.push_back(-1);
        }
        else
        {
            int& c_idx = alphabet.find(s[i])->second;
            answer.push_back(i-c_idx);
            c_idx = i;
        }
    }
    return answer;
}