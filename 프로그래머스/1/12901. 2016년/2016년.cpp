#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> day = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
    int day_all = day[a-1] + b;
    switch(day_all%7)
    {
        case 1:
            answer = "FRI";
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
        case 0:
            answer = "THU";
            break;
    }
    return answer;
}