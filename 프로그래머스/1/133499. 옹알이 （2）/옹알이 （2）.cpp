#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> possible_babbling = { "aya", "ye", "woo", "ma" };

    for (string str : babbling)
    {
        string prev = "";
        int idx = 0;
        
        for (int i = 0; i < possible_babbling.size(); i++)
        {
            string possible_str = possible_babbling[i];
            int len = possible_str.length();

            if (possible_str == prev)
            {
                continue;
            }

            if (possible_str == str.substr(idx, len))
            {
                prev = possible_str;
                idx += len;
                if(idx == str.length())
                {
                    answer++;
                    break;
                }
                i = -1;
            }
        }
    }
    return answer;
}