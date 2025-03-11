#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> cmd : commands)
    {
        int start = cmd[0]-1;
        int end = cmd[1];
        vector<int> result(array.begin() + start, array.begin() + end);
        sort(result.begin(), result.end());
        answer.push_back(result[cmd[2] - 1]);
    }
    return answer;
}