//21-02-16 dp solved

#include <iostream>

using namespace std;
int N;
int mSize[500][2];
int dp[500][500] = {0};

int find_answer(int begin, int end)
{
    if (begin == end) return 0;
    if (dp[begin][end]) return dp[begin][end];
    int _min = 2147483647;
    for (int mid=begin; mid<end; mid++)
    {
        int lcal = find_answer(begin, mid);
        int rcal = find_answer(mid+1, end);
        int cal = lcal + rcal + mSize[begin][0] * mSize[end][1] * mSize[mid][1];
        _min = min(_min, cal);
    }
    dp[begin][end] = _min;
    return dp[begin][end];
}

int main()
{
    cin>>N;
    for (int i=0; i<N; i++)
    {
        cin>>mSize[i][0]>>mSize[i][1];
    }
    cout<<find_answer(0, N-1)<<endl;
}