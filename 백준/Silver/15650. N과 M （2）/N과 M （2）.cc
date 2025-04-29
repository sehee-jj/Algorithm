#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin>>N>>M;
    
    int arr[8];
    
    fill_n(arr, 8, 1);
    for(int i=0; i<M; i++)
        arr[i] = 0;
    
    do {
        for(int i=0; i<N; i++) {
            if(arr[i]==0)
                cout<<i+1<<' ';
        }
        cout<<'\n';
    } while(next_permutation(arr, arr+N));
    
    return 0;
}