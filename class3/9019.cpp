#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

queue<pair<int, string>> Q;
int T, A, B;
bool V[10000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        memset(V, false, sizeof(V));
        queue<pair<int, string>> e;
        swap(Q, e);
        cin>>A>>B;
        Q.push(make_pair(A, ""));
        V[A] = true;
        string str = "";
        while (!Q.empty()) {
            int num = Q.front().first, newn;
            str = Q.front().second;
            Q.pop();
            if (num==B) break;
            newn = num*2%10000;
            if (!V[newn]) Q.push(make_pair(num*2%10000, str+"D"));
            V[newn] = true;
            newn = num==0 ? 9999 : num-1;
            if (!V[newn]) Q.push(make_pair(newn, str+"S"));
            V[newn] = true;
            newn = (num/1000 + num*10)%10000;
            if (!V[newn]) Q.push(make_pair(newn, str+"L"));
            V[newn] = true;
            newn = num/10 + num%10*1000;
            if (!V[newn]) Q.push(make_pair(newn, str+"R"));
            V[newn] = true;
        }
        cout<<str<<"\n";
    }
}