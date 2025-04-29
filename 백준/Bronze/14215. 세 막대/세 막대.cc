#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tri[3];
    cin >> tri[0] >>tri[1] >> tri[2];
    sort(tri, tri+3);
    
    while(tri[0]+tri[1]<=tri[2])
        tri[2]--;
    
    cout<<tri[0]+tri[1]+tri[2];
    return 0;
}