#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int perfectSet[]={1, 1, 2, 2, 2, 8};
    int possNum;
    
    for(int i = 0; i<6; i++)
    {
        cin>>possNum;
        cout<<perfectSet[i]-possNum<<' ';
    }
}