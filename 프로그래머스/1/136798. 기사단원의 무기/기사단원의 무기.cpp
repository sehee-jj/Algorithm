#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1; i<=number; i++)
    {
        int range = sqrt(i);
        int result = 0;
        for(int j=1; j<=range; j++)
        {
            if(i%j==0)
            {
                if(j*j!=i)
                {
                    result+=2;
                }
                else
                {
                    ++result;
                }
            }
        }
        
        if(result>limit)
        {
            answer += power;
        }
        else
        {
            answer += result;
        }
    }
    
    return answer;
}