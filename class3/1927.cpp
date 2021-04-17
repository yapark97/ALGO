#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> PQ;
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for (int i=0; i<N; i++)
    {
        int k;
        cin>>k;
        if (k == 0) {
            if (PQ.empty())
                cout<<"0\n";
            else {
                cout<<-PQ.top()<<"\n";
                PQ.pop();
            }
        }
        else {
            PQ.push(-k);
        }
    }
}