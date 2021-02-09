//21-01-19 union-find solved

#include <iostream>

using namespace std;

int N, M, k;
int friends[10000]; //root에는 비용이 가장 작은 학생이? (-비용)

int _find(int x)
{
    if (friends[x] < 0) return x;
    int root =  _find(friends[x]);
    friends[x] = root;
    return root;
}

void _union(int x, int y)
{
    x = _find(x);
    y = _find(y);
    if (x == y) return ;
    if (friends[x] > friends[y]) // x비용이 더 작음
        friends[y] = x;
    else
        friends[x] = y;
}

int main()
{
    cin>>N>>M>>k;
    for (int i = 0; i < N; i++)
    {
        cin>>friends[i];
        friends[i] = -friends[i];
    }
    int x, y;
    for (int i = 0; i < M; i++)
    {
        //학생들의 친구관계
        cin>>x>>y;
        _union(x-1, y-1);
    }
    int costSum = 0;
    for (int i = 0; i < N; i++)
        if (friends[i] < 0)
            costSum -= friends[i];
    if (costSum > k)
        cout<<"Oh no"<<endl;
    else
        cout<<costSum<<endl;
}