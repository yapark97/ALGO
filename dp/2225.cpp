#include <iostream>
#include <cstring>

using namespace std;

int N, K;
long dp[200][200]; //times, sum

int find_answer(int num, int sum)
{
    if (dp[num][sum] != -1) return dp[num][sum];
    long ret = 0;
    for (int i=0; i<=N; i++)
    {
        if (i > sum) break;
        ret += find_answer(num-1, sum-i);
    }
    dp[num][sum] = ret;
    cout<<num<<" "<<sum<<" "<<ret<<endl;
    return ret;
}

int main()
{
    cin>>N>>K;
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<=N; i++)
        dp[0][i] = 0;
    for (int i=0; i<=K; i++)
        dp[i][0] = 1;
    cout<<find_answer(K, N)%1000000000<<endl;
}