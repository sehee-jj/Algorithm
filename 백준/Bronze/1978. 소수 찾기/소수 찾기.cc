#include <iostream>
using namespace std;

int main() {
    int N, num, cnt=0;
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>num;
        int j;
        for(j=2; j<num; j++) {
            if(num%j==0)
                break;
        }
        if(num==j)
            cnt++;
    }
    cout<<cnt;
    return 0;
}