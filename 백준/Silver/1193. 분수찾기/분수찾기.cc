#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int X, range=2, i=2;
    cin>>X;
    
    while(1) {
        if(X<range) 
            break;
        range += i++;
    }
    
    if(i%2==0)
        cout<<range-X<<'/'<<i-(range-X);
    else
        cout<<i-(range-X)<<'/'<<range-X;
    
    return 0;
}