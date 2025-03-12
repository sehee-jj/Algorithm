#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> alphabet;
    for(int c = 97; c<123; c++)
    {
        alphabet.insert({static_cast<char>(c), -1});
    }
    
    for(int i=0; i<s.length(); i++)
    {
        int& c_idx = alphabet.find(s[i])->second;
        if(c_idx == -1)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i-c_idx);
        }
        c_idx = i;
    }
    return answer;
}