#include <string>
#include <vector>

using namespace std;

char CompareString(char s1, char s2)
{
    if(s1>s2)
    {
        return s1;
    }
    else if(s1<s2)
    {
        return s2;
    }
    else
    {
        return '*';
    }
}

void SwapVector(vector<string>& list, int i, int j)
{
    string temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

vector<string> solution(vector<string> strings, int n) {
    for(int i=0; i<strings.size(); i++)
    {
        for(int j=i+1; j<strings.size(); j++)
        {
            char s1 = strings[i][n];
            char s2 = strings[j][n];
            char result = CompareString(s1, s2);
            
            if(result==s1)
            {
                SwapVector(strings, i, j);
            }
            else if(result=='*')
            {
                if(strings[i] > strings[j])
                    {
                        SwapVector(strings, i, j);
                    }
            }
        }
    }
    return strings;
}