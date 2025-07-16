#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool IsCompositeNum(int n) {
    int mid_num = sqrt(n);
    int cnt = 1;
    
    for(int i=2; i<= mid_num; ++i)
    {
        if(n%i == 0) ++cnt;
    }
    
    cnt *= 2;
    
    if(mid_num*mid_num == n) --cnt;
    
    return cnt >= 3;
}

int solution(int n) {
    int answer = 0;
    
    for(int i = 4; i<= n; ++i)
    {
        if(IsCompositeNum(i)) ++answer;
    }
    
    return answer;
}