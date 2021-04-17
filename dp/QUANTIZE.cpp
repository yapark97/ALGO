//21-04-11 QUANTIZE solved

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int T, N, S;
vector<int> V, Sum, Sum_sq;
int DP[101][11];
int ANS;

int MSE(int first, int last)
{
    if (first == last) return 0;
    int mean = first == 0 ? Sum[last-1] : Sum[last-1] - Sum[first-1];
    mean = floor(mean / (float)(last-first) + 0.5);
    int ret = first == 0 ? Sum_sq[last-1] : Sum_sq[last-1] - Sum_sq[first-1];
    if (!first) ret -= 2*mean*Sum[last-1];
    else ret -= 2*mean*(Sum[last-1]-Sum[first-1]);
    ret += pow(mean, 2) * (last-first);
    return ret;
}

int split(int left, int parts)
{
    if (left == 0)
        return 0;
    if (parts == 0)
        return -1;
    if (DP[left][parts] != -1)
        return DP[left][parts];
    int ret = -1;
    for (int i=1; i<=left; i++) {
        int prev = split(left-i, parts-1), mse = MSE(V.size()-left, V.size()-left+i);
        if (prev != -1 && (ret == -1 || ret > prev + mse))
            ret = prev + mse;
    }
    DP[left][parts] = ret;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for (int t=0; t<T; t++)
    {
        V.clear();
        Sum.clear();
        Sum_sq.clear();
        cin>>N>>S;
        for (int i=0; i<N; i++) {
            int temp;
            cin>>temp;
            V.push_back(temp);
        }
        sort(V.begin(), V.end());
        Sum.push_back(V[0]);
        Sum_sq.push_back(pow(V[0], 2));
        for (int i=1; i<N; i++) {
            Sum.push_back(Sum.back() + V[i]);
            Sum_sq.push_back(Sum_sq.back() + pow(V[i], 2));
        }
        memset(DP, -1, sizeof(DP));
        cout<<split(N, S)<<"\n";
    }
}