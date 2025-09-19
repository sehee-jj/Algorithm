#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;
    for(int n = 1; n<=s.length()/2+1; ++n)
    {
        string base_str = s.substr(0, n);
        int cnt = 1;
        string result = "";
        
        for(int i=n; i<s.length(); i+=n)
        {
            if(base_str == s.substr(i, n)) ++cnt;
            else
            {
                if(cnt > 1) result+= to_string(cnt);
                result += base_str;
                
                base_str = s.substr(i, n);
                cnt = 1;
            }
        }
        
        if(cnt > 1) result+= to_string(cnt);
        result += base_str;
        
        answer = min(answer, static_cast<int>(result.length()));
    }
    
    return answer;
}