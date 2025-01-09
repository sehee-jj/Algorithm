#include <string>
#include <vector>

using namespace std;

bool isUpper(char c)
{
    if(c >= 65 && c <= 90)
        return true;
    else
        return false;
}

string solution(string s, int n) {
    string answer = "";
    for(char c : s)
    {
        if(c==' ')
        {
            answer.push_back(c);
            continue;
        }
        
        if((isUpper(c) && !isUpper(c+n)) || (!isUpper(c) && c+n > 122))
        {
            c -= 26;
        }
        answer.push_back(c+n);
    }
    return answer;
}