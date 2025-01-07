#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int i = 0;

    while (i < s.length())
    {
        char c = s.at(i);

        if (c == ' ')
        {
            s.erase(0, i + 1);
            answer.push_back(' ');
            i = 0;
            continue;
        }
        else if (i % 2 == 0 && c >= 97)
        {
            c -= 32;
        }
        else if(i%2 != 0 && c <= 90)
        {
            c += 32;
        }
            
        answer.push_back(c);
        i++;
    }

    return answer;
}