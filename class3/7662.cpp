#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, K;
bool Deleted[1000001];
priority_queue<pair<long long int, int>> Max;
priority_queue<pair<long long int, int>> Min;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        memset(Deleted, false, sizeof(Deleted));
        while (!Max.empty())
            Max.pop();
        while (!Min.empty())
            Min.pop();
        cin>>K;
        for (int k=0; k<K; k++)
        {
            char cmd;
            cin>>cmd;
            long long int num;
            cin>>num;
            if (cmd == 'I') {
                Max.push(make_pair(num, k));
                Min.push(make_pair(-num, k));
            }
            else if (num == -1) {
                while (!Min.empty() && Deleted[Min.top().second])
                    Min.pop();
                if (!Min.empty()) {
                    int idx = Min.top().second;
                    Min.pop();
                    Deleted[idx] = true;
                }
            }
            else if (num == 1) {
                while (!Max.empty() && Deleted[Max.top().second])
                    Max.pop();
                if (!Max.empty()) {
                    int idx = Max.top().second;
                    Max.pop();
                    Deleted[idx] = true;
                }
            }
        }
        while (!Max.empty() && Deleted[Max.top().second])
            Max.pop();
        while (!Min.empty() && Deleted[Min.top().second])
            Min.pop();
        if (Max.empty())
            cout<<"EMPTY\n";
        else
            cout<<Max.top().first<<" "<<-Min.top().first<<"\n";
    }
}