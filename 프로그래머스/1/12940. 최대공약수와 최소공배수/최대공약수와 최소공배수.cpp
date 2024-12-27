#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int div = 1;
    int min_value = min(n, m);
    for(int i=2; i<=min_value; i++)
    {
        if(n%i==0 && m%i==0)
        {
            div*=i;
            n /= i;
            m /= i;
            i--;
        }
    }
    answer.push_back(div);
    answer.push_back(div*n*m);
    return answer;
}