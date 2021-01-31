//21-01-31 brute-force

#include <iostream>

using namespace std;

int N;
int S[20][20];
int _min = -1;

void find_min(int *team)
{
    int start = 0, link = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            if (team[i] == team[j] && team[i])
                start += S[i][j];
            else if (team[i] == team[j])
                link += S[i][j];
        }
    int diff = start>link ? start-link : link-start;
    if (_min == -1)
        _min = diff;
    else
        _min = min(_min, diff);
}

void bf(int count, int idx, int *team)
{
    if (count == N/2) //스타트팀 꽉참
    {
        find_min(team);
        return ;
    }
    while (++idx < N)
    {
        team[idx] = 1;
        bf(count+1, idx, team);
        team[idx] = 0;
    }
}

int main()
{
    cin>>N;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin>>S[i][j];
    
    int team[20] = {0}; //스타트팀이면 1
    team[0] = 1;
    bf(1, 0, team);//스타트팀 들어간 사람수 0명, 마지막 들어간 사람의 인덱스 -1

    cout<<_min<<endl;
}