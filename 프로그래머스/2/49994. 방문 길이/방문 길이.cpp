#include <string>
#include <map>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    pair<int,int> loc = {0, 0};
    map<pair<int,int>, string> save_road;
    
    for(char dir : dirs)
    {
        auto temp = loc;
        char opposite_dir;
        
        switch(dir)
        {
            case 'U':
                temp.second += 1;
                opposite_dir = 'D';
                break;
            case 'D':
                temp.second -= 1;
                opposite_dir = 'U';
                break;
            case 'R':
                temp.first += 1;
                opposite_dir = 'L';
                break;
            case 'L':
                temp.first -= 1;
                opposite_dir = 'R';
                break;
            default:
                break;
        }
        
        if(temp.first > 5 || temp.first < -5 
           || temp.second > 5 || temp.second < -5) continue;
        
        cout<< temp.first <<", " << temp.second << endl;
        
        if(save_road.find(loc) != save_road.end() 
           && save_road[loc].find(string(1, dir)) != string::npos)
        {
            loc = temp;
            continue;
        }
        
        ++answer;
        save_road[loc] += dir;
        save_road[temp] += opposite_dir;
        loc = temp;
    }
    
    return answer;
}