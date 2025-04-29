#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int x, y, w, h, minDist=INT_MAX;
    cin >> x >> y >> w >> h;
    
    minDist = min(x, y);
    minDist = min(minDist, w-x);
    minDist = min(minDist, h-y);
    
    cout<<minDist;
    return 0;
}