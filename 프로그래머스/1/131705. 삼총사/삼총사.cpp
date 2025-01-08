#include <string>
#include <vector>

using namespace std;

int makeTrio(vector<int> number, vector<int> trio, int index)
{
    int result = 0;
    if(trio.size()>= 3)
    {
        int sum = trio.at(0) + trio.at(1) + trio.at(2);
        return sum==0 ? 1:0;
    }
    else if(index >= number.size())
        return 0;
    
    for(int i=index; i<number.size(); i++)
    {
        trio.push_back(number.at(i));
        result += makeTrio(number, trio, i+1);
        trio.pop_back();
    }
    
    return result;
}

int solution(vector<int> number) {
    vector<int> trio;
    return makeTrio(number, trio, 0);
}