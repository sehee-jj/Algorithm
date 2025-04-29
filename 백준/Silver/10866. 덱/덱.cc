#include <iostream>
using namespace std;

class Deque {
    private:
        int DQ[20001];
        int *head=&DQ[10000], *tail=&DQ[10000];
    public:
        void push_front(int x) {
            *(--head) = x;
            return ;
        }
    
        void push_back(int x) {
            *(tail++) = x;
            return;
        }
    
        int pop_front() {
           return *(head++); 
        }
    
        int pop_back() {
            return *(--tail);
        }
    
        const int size() {
            return tail-head;
        }
    
        const int empty() {
            if (!size())
                return 1;
            else
                return 0;
        }
    
        const int front() {
            return *head;
        }
    
        const int back() {
            return *(tail-1);
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Deque Dq;
    string op;
    int n;
    cin >> n;
    
    while(n--) {
        cin >> op;
        if(op == "push_front") {
            int x;
            cin>>x;
            Dq.push_front(x);
        }
        else if(op == "push_back") {
            int x;
            cin>>x;
            Dq.push_back(x);
        }
        else if(op == "pop_front") {
            if(Dq.empty()) {
                cout<<-1<<"\n";
                continue;
            }
            cout<<Dq.pop_front()<<"\n";
        }
        else if(op == "pop_back") {
            if(Dq.empty()) {
                cout<<-1<<"\n";
                continue;
            }
            cout<<Dq.pop_back()<<"\n";
        }
        else if(op == "size")
            cout<<Dq.size()<<"\n";
        else if(op == "empty")
            cout<<Dq.empty()<<"\n";
        else if(op == "front") {
            if(Dq.empty())
                cout<<-1<<"\n";
            else
                cout<<Dq.front()<<"\n";
        }
        else if(op == "back") {
            if(Dq.empty())
                cout<<-1<<"\n";
            else
                cout<<Dq.back()<<"\n";
        }
    }
    
    return 0;
}