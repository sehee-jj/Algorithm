#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNum(int num)
{
    int range = sqrt(num);
    for(int i=2; i<=range; i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for(int i=0; i<nums.size()-2; i++)
    {
        int result = nums[i];
        for(int j=i+1; j<nums.size()-1; j++)
        {
            result += nums[j];
            for(int k=j+1; k<nums.size(); k++)
            {
                result += nums[k];
                if(isPrimeNum(result))
                {
                    answer++;
                }
                result -= nums[k];
            }
            result -= nums[j];
        }
        result -= nums[i];
    }

    return answer;
}