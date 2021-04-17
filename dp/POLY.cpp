//21-04-11 POLY solved

#include <iostream>
#include <cstring>

using namespace std;

int T, N;
int DP[101][101];

int poly(int sum, int top)
{
    if (DP[sum][top] != -1)
        return DP[sum][top];
    //base case
    if (sum == top) return 1;

    //recursion
    int ret = 0;
    for (int i=1; i<=sum-top; i++)
        ret = (ret + (poly(sum-top, i) * (top+i-1))%10000000) % 10000000;

    DP[sum][top] = ret;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        cin>>N;
        memset(DP, -1, sizeof(DP));
        int ans=0;
        for (int i=1; i<=N; i++)
            ans = (ans + poly(N, i)) % 10000000;
        cout<<ans<<"\n";
    }
}