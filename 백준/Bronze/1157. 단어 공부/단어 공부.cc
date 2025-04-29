#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    map<char, int> freq;
    char alph;
    
    string str;
    cin >> str;
    
    for(int i=0; i<str.length(); i++)
    {
        alph = toupper(str[i]);
        if(i!=0)
        {
            auto it = freq.find(alph);
            if(it == freq.end())
                freq.insert(make_pair(alph, 1));
            else
                freq[alph]++;   
        }
        else
            freq.insert(make_pair(alph, 1));
    }
    
    bool dupl = false;
    pair<char, int> mostAlph = make_pair(' ', 0);
    for(const auto& temp : freq)
    {
        if(mostAlph.second != 0)
        {
            if(temp.second>mostAlph.second)
            {
                mostAlph = temp;
                dupl = false;
            }
            else if(temp.second==mostAlph.second)
                dupl = true;
        }
        else
            mostAlph=temp;
    }
    
    if(dupl)
        cout<<"\?"<<endl;
    else
        cout<<mostAlph.first<<endl;
}