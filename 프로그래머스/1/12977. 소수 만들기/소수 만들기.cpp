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
        for(int j=i+1; j<nums.size()-1; j++)
        {
            for(int k=j+1; k<nums.size(); k++)
            {
                if(isPrimeNum(nums[i]+nums[j]+nums[k]))
                {
                    answer++;
                }
            }
        }
    }

    return answer;
}