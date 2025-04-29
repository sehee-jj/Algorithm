#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num, sum=0;
    cin >> num;
    
    while(num!=-1) {
      vector<int> div;
        for(int i=1; i<num; i++) {
            if(num%i==0) {
                sum+=i;
                div.emplace_back(i);
            }
        }
        if(num==sum) {
            cout<<num<<" = "<<div.at(0);
            for(int i = 1; i<div.size(); i++)
                cout<<" + "<<div.at(i);
            cout<<endl;
        } else {
            cout<<num<<" is NOT perfect."<<endl;
        }
        sum = 0;
        cin>>num;
    }
    return 0;
}