#include <string>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int, greater<char>> mx, my;
    
    for(char c : X) mx[c]++;
    for(char c : Y) my[c]++;
    
    for(auto it : mx)
    {
        int cnt;
        
        if(it.second < my[it.first]) cnt = it.second;
        else cnt = my[it.first];
        
        if(answer.empty() && it.first == '0' && cnt != 0) 
        {
            answer = "0";
            break;
        }
        
        for(int j =0; j<cnt; j++)
        {
            answer += it.first;
        }
    }
    
    if(answer.empty()) answer = "-1";

    return answer;
}