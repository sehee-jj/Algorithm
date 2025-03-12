#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i=1; i<food.size(); i++)
    {
        answer.append(food[i]/2, i+'0');
    }
    string reverse_str = answer;
    reverse(reverse_str.begin(), reverse_str.end());
    answer += "0" + reverse_str;
    return answer;
}