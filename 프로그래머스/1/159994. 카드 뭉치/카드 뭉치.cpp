#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int i = 0, j=0, target = 0;
    while(target<goal.size()&&(i<cards1.size()||j<cards2.size()))
    {
        if(i<cards1.size()&&cards1[i]==goal[target])
        {
            i++;
        }
        else if(j<cards2.size()&&cards2[j]==goal[target])
        {
            j++;
        }
        else
        {
            return "No";
        }
        
        target++;
    }
    return "Yes";
}