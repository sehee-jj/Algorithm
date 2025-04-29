#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, x_min, x_max, y_min, y_max;
    cin >> n;
    x_min = INT_MAX;
    y_min = INT_MAX;
    x_max = INT_MIN;
    y_max = INT_MIN;
    
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        if(x_min>x) x_min=x;
        if(x_max<x) x_max=x;
        if(y_min>y) y_min=y;
        if(y_max<y) y_max=y;
    }
    
    cout<< (x_max-x_min)*(y_max-y_min);
    return 0;
}