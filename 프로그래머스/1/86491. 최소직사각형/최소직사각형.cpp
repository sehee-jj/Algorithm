#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_height = 0;
    
    for(vector<int> temp : sizes)
    {
        if(temp[0] < temp[1])
        {
            swap(temp[0], temp[1]);
        }
        max_width = max(max_width, temp[0]);
        max_height = max(max_height, temp[1]);
    }
    
    return max_width * max_height;
}