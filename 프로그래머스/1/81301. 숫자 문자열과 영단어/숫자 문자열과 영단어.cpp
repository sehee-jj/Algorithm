#include <string>
#include <vector>
#include <array>

using namespace std;

array<string, 10> number = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;
    for(int i=0; i<number.size(); i++)
    {
        int index = s.find(number.at(i));
        while(index != string::npos)
        {
            s.replace(index, number.at(i).length(), to_string(i));
            index = s.find(number.at(i));
        }
    }
    answer = stoi(s);
    return answer;
}