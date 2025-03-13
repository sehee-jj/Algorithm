#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a)
    {
        int received_coke = (n/a)*b;
        answer += received_coke;
        n = received_coke + n%a;
    }
    return answer;
}