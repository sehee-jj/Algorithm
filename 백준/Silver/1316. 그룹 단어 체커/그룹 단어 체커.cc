#include <iostream>
using namespace std;

int main()
{
    bool alph[26]={false};
    int n, cnt = 0;
    
    cin >> n;
    
    for(int i= 0; i<n; i++)
    {
        string word;
        cin >> word;
        int j;
        for(j = 1; j<word.length(); j++)
        {
            if(word[j-1]!=word[j])
            {
                int alphIdx = word[j]-97;
                
                if(alph[alphIdx])
                    break;
                
                alphIdx = word[j-1]-97;
                alph[alphIdx] = true;
            }
        }
        if(j==word.length())
            cnt++;
        fill_n(alph, 26, false);
    }
    
    cout<<cnt<<endl;
    
    return 0;
}