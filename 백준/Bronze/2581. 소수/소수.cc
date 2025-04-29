#include <iostream>
using namespace std;

int main() {
    int M, N, sum=0, min;
    cin>>M>>N;
    for(int num=M; num<=N; num++) {
        int j;
        for(j=2; j<num; j++) {
            if(num%j==0)
                break;
        }
        if(num==j) {
            if(sum==0)
                min=num;
            sum+=num;
        }
    }
    if(sum==0)
        cout<<-1;
    else {
        cout<<sum<<endl;
        cout<<min<<endl;
    }
    return 0;
}