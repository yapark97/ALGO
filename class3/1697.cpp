#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
bool V[100001];
priority_queue<pair<int, int>> PQ;

int main()
{
    cin>>N>>K;
    PQ.push(make_pair(0, N));
    int ans=0, pos;
    memset(V, false, sizeof(V));
    while (!PQ.empty())
    {
        ans = -PQ.top().first, pos = PQ.top().second;
        PQ.pop();
        if (pos < 0 || pos > 100000 || V[pos]) continue;
        V[pos] = true;
        if (pos == K) break;
        PQ.push(make_pair(-ans-1, pos+1));
        PQ.push(make_pair(-ans-1, pos-1));
        PQ.push(make_pair(-ans-1, pos*2));
    }
    cout<<ans<<endl;
}