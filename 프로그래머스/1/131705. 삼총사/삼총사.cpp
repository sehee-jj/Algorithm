#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void makeTrio(vector<int> number, vector<int> trio, int index)
{
    if(trio.size()>= 3)
    {
        int sum = trio.at(0) + trio.at(1) + trio.at(2);
        cnt += (sum==0?1:0);
        return;
    }
    else if(index >= number.size())
        return;
    
    for(int i=index; i<number.size(); i++)
    {
        trio.push_back(number.at(i));
        makeTrio(number, trio, i+1);
        trio.pop_back();
    }
}

int solution(vector<int> number) {
    vector<int> trio;
    makeTrio(number, trio, 0);
    return cnt;
}