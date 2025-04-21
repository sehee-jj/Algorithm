#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    string str1, str2;
    int i = 0;

    if (X.length() > Y.length())
    {
        str1 = Y;
        str2 = X;
    }
    else
    {
        str1 = X;
        str2 = Y;
    }

    sort(str1.rbegin(), str1.rend());
    sort(str2.rbegin(), str2.rend());

    while (i < str1.length())
    {
        int char1_cnt = 0;
        int char2_cnt = 0;
        int common_cnt = 0;

        if (str2.find(str1[i]) != string::npos)
        {
            char1_cnt = str1.find_last_of(str1[i]) - str1.find_first_of(str1[i]) + 1;
            char2_cnt = str2.find_last_of(str1[i]) - str2.find_first_of(str1[i]) + 1;
            if (char1_cnt < char2_cnt)
            {
                common_cnt = char1_cnt;
            }
            else
            {
                common_cnt = char2_cnt;
            }

            answer += str1.substr(str1.find_first_of(str1[i]), common_cnt);
            i += char1_cnt;
        }
        else
        {
            i = str1.find_last_of(str1[i]) + 1;
        }
    }

    if (answer.length() == 0)
    {
        return "-1";
    }
    else if (answer[0] == '0')
    {
        return "0";
    }

    return answer;
}