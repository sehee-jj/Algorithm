#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char c : s)
    {
        if(c==' ')
        {
            answer.push_back(c);
            continue;
        }
        
        if((isupper(c) && !isupper(c+n)) || (islower(c) && !islower(c+n)))
        {
            c -= 26;
        }
        answer.push_back(c+n);
    }
    return answer;
}