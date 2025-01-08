#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i=0; i<=t.length()-p.length(); i++)
    {
        string sub_str = t.substr(i, p.length());
        if(sub_str <= p)
            answer++;
    }
    
    return answer;
}