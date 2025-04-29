#include <iostream>
#include <stack>
using namespace std;

struct height_group {
  int h, cnt;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    
    long long res = 0;
    stack<height_group> S;
    
    while(n--) {
      int x, cnt=1; 
      cin>>x;
      while(!S.empty()&&S.top().h<=x) {
        res += S.top().cnt;
        if(S.top().h==x) cnt+=S.top().cnt;
        S.pop();
      }
      if(!S.empty()) res++;
      S.push({x, cnt});
    }
    
    cout<<res;

    return 0;
}