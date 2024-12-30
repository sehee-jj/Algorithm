#include <string>
#include <stack>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int> ternary; // 3진법으로 변환한 수를 저장할 스택
    
    // 3진법 수로 변환
    while(n>0)
    {
        ternary.push(n%3);
        n /= 3;
    }
    
    int size = ternary.size();
    
    // 10진법 수로 표현
    for(int i=0; i<size; i++)
    {
        answer += (ternary.top()*pow(3,i));
        ternary.pop();
    }
    return answer;
}
