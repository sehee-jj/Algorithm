#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string str)
{
    stack<char> brackets;
    for(int i=0; i<str.length(); ++i)
    {
        if(str[i] == '(') brackets.push('(');
        else if(brackets.empty()) return false;
        else brackets.pop();
    }
    
    if(!brackets.empty()) return false;
    
    return true;
}

string makeBrackets(string str)
{
    if(str.empty()) return "";
    
    string u = "", v = "";
    int l_cnt = 0, r_cnt = 0;
    
    // u, v 나누기
    for(int i=0; i<str.length(); ++i)
    {
        u.push_back(str[i]);
        if(str[i] == '(') ++l_cnt;
        else ++r_cnt;
        
        if(l_cnt == r_cnt)
        {
            v = str.substr(i+1);
            break;
        }
    }
    
    //u가 올바른 괄호 문자열인지 확인
    if(!isCorrect(u))
    {
        string v_temp = "(" + makeBrackets(v) + ")";
        string u_temp;
        if(u.length() > 2) 
        {
            u_temp = u.substr(1, u.length()-2);
            for(int i=0; i<u_temp.length(); ++i)
            {
                if(u_temp[i] == '(') u_temp[i] = ')';
                else u_temp[i] = '(';
            }
        }
        else u_temp = "";
        return v_temp + u_temp;
    }
    
    return u + makeBrackets(v);
}

string solution(string p) {
    string answer = "";
    answer = makeBrackets(p);
    return answer;
}